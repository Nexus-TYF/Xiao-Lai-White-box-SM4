#include "wbsm4.h"
#include "sbox.h"

#define GET32(pc)  (\
((uint32_t)(pc)[0] << 24) ^\
((uint32_t)(pc)[1] << 16) ^\
((uint32_t)(pc)[2] <<  8) ^\
((uint32_t)(pc)[3]))

#define PUT32(st, ct)\
(ct)[0] = (uint8_t)((st) >> 24);\
(ct)[1] = (uint8_t)((st) >> 16);\
(ct)[2] = (uint8_t)((st) >>  8);\
(ct)[3] = (uint8_t)(st)

uint32_t identM32[32]={0x80000000,0x40000000,0x20000000,0x10000000,0x8000000,0x4000000,0x2000000,0x1000000,0x800000,0x400000,0x200000,0x100000,0x80000,0x40000,0x20000,0x10000,0x8000,0x4000,0x2000,0x1000,0x800,0x400,0x200,0x100,0x80,0x40,0x20,0x10,0x8,0x4,0x2,0x1};

M32 sm4_csl_xor_matrix = {
    .M[0] = 0xA0202080, 
    .M[1] = 0x50101040, 
    .M[2] = 0x28080820, 
    .M[3] = 0x14040410,
    .M[4] = 0xA020208, 
    .M[5] = 0x5010104, 
    .M[6] = 0x2808082, 
    .M[7] = 0x1404041, 
    .M[8] = 0x80A02020, 
    .M[9] = 0x40501010, 
    .M[10] = 0x20280808, 
    .M[11] = 0x10140404, 
    .M[12] = 0x80A0202, 
    .M[13] = 0x4050101, 
    .M[14] = 0x82028080, 
    .M[15] = 0x41014040, 
    .M[16] = 0x2080A020, 
    .M[17] = 0x10405010, 
    .M[18] = 0x8202808, 
    .M[19] = 0x4101404, 
    .M[20] = 0x2080A02, 
    .M[21] = 0x1040501, 
    .M[22] = 0x80820280, 
    .M[23] = 0x40410140, 
    .M[24] = 0x202080A0, 
    .M[25] = 0x10104050, 
    .M[26] = 0x8082028, 
    .M[27] = 0x4041014, 
    .M[28] = 0x202080A, 
    .M[29] = 0x1010405, 
    .M[30] = 0x80808202, 
    .M[31] = 0x40404101
};

void printstate(unsigned char * in)
{
    for(int i = 0; i < 16; i++) 
    {
        printf("%.2X", in[i]);
    }
    printf("\n");
}
void sm4_wb_gen_secrect_sbox(sm4_context *sm4_key) {
    uint8_t *sst;
    uint32_t key[32];
    for(int i=0;i<32;i++)
    {
        key[i] = sm4_key->sk[i];
    }
    uint32_t *rk = key;
    for (int i = 0; i < 32; i++) 
    {
        for (int j = 0; j < 256; j++) 
        {
            skbox_enc[i][0][j] = SBOX[ j ^ ((rk[i] >> 24) & 0xff) ];
            skbox_enc[i][1][j] = SBOX[ j ^ ((rk[i] >> 16) & 0xff) ];
            skbox_enc[i][2][j] = SBOX[ j ^ ((rk[i] >>  8) & 0xff) ];
            skbox_enc[i][3][j] = SBOX[ j ^ ((rk[i]      ) & 0xff) ];
        }
    }
}
void sm4_wb_gen_affine(Sm4Whitebox* sm4_wb_ctx)
{
    int i,j;
    int rounds = 32 + 4;
    for (i = 0; i < rounds; i++) 
    {
        //gen P affine matrix
          genaffinepairM32(&P[i][0], &P[i][1]);

        //gen E affine matrix
        for (j = 0; j < 4; j++) 
        {
            genaffinepairM8(&E[i][j][0], &E[i][j][1]);
        }

        // combine 4 E8 to 1 E32
        affinecomM8to32(E[i][0][1], E[i][1][1], E[i][2][1], E[i][3][1], &EC[i][1]);
        genaffinepairM32(&Q[i][0], &Q[i][1]);
    }
}
void sm4_wb_combine_tables(Sm4Whitebox* sm4_wb_ctx)
{
    int i, j;
    int rounds = 32;
    for (i = 0; i < rounds; i++)
    {
        //part 1. gen M affine matrix
        affinemixM32(EC[i][1], P[i+1][1], &sm4_wb_ctx->M[i][0]);
        affinemixM32(EC[i][1], P[i+2][1], &sm4_wb_ctx->M[i][1]);
        affinemixM32(EC[i][1], P[i+3][1], &sm4_wb_ctx->M[i][2]);

        //part 2. gen Q combine L into 4 matrix
        M32 QL;
        MatMulMatM32(Q[i][0].Mat, sm4_csl_xor_matrix, &QL);
        M32 QLi[4];
        for(j = 0; j<4; j++)
        {
            for (int ii = 0; ii < 32; ii++) 
            {
                QLi[j].M[ii] = (uint8_t)(QL.M[ii] >> (8 * j));
            }
        }

        int k;
        uint32_t r = Q[i][0].Vec.V;
        for (k = 0; k < 256; k++) 
        {
            for (int d = 0; d < 4; d++) 
            {
                int kd =  affineU8(E[i][d][0], k);
                kd = skbox_enc[i][d][kd];
                uint32_t temp = 0;
                for(int ii = 0; ii < 32; ii++){
                    if(xorU8((uint8_t)(QLi[3-d].M[ii]) & kd)) temp ^= identM32[ii];
                }
                sm4_wb_ctx->Table[i][d][k] = temp;
            }
            sm4_wb_ctx->Table[i][3][k] = sm4_wb_ctx->Table[i][3][k] ^ r;
        }
        
        //part 3. gen C D matrix, C for Xi0, D for T(Xi1+Xi2+Xi3+rk)
        affinemixM32(P[i+4][0], P[i][1], &sm4_wb_ctx->C[i]);
        affinemixM32(P[i+4][0], Q[i][1], &sm4_wb_ctx->D[i]);
        sm4_wb_ctx->D[i].Vec.V ^= P[i+4]->Vec.V ;
    }

    //external encoding
    for (int i=0; i<4; i++) 
    {
        sm4_wb_ctx->SE[i].Mat = P[i][0].Mat;
        sm4_wb_ctx->SE[i].Vec = P[i][0].Vec;

        sm4_wb_ctx->FE[i].Mat = P[rounds + i][1].Mat;
        sm4_wb_ctx->FE[i].Vec = P[rounds + i][1].Vec;
    }

}
void sm4_wb_gen_tables(uint8_t *key, Sm4Whitebox *sm4_wb_ctx)
{
    sm4_context ctx;
    sm4_setkey_enc(&ctx, key);
    sm4_wb_gen_secrect_sbox(&ctx);
    sm4_wb_gen_affine(sm4_wb_ctx);
    sm4_wb_combine_tables(sm4_wb_ctx);
}
void sm4_wb_enc(unsigned char IN[], unsigned char OUT[], Sm4Whitebox *sm4_wb_ctx)
{
    uint32_t x0,x1,x2,x3,x4;
    uint32_t xt0, xt1, xt2, xt3, xt4;
    
    x0 = GET32(IN     );
	x1 = GET32(IN +  4);
	x2 = GET32(IN +  8);
    x3 = GET32(IN + 12);

    x0 = affineU32(sm4_wb_ctx->SE[0], x0);
    x1 = affineU32(sm4_wb_ctx->SE[1], x1);
    x2 = affineU32(sm4_wb_ctx->SE[2], x2);
    x3 = affineU32(sm4_wb_ctx->SE[3], x3);

    for(int i = 0; i < 32; i++)
    {
        xt1 = affineU32(sm4_wb_ctx->M[i][0], x1);
        xt2 = affineU32(sm4_wb_ctx->M[i][1], x2);
        xt3 = affineU32(sm4_wb_ctx->M[i][2], x3);
        x4 = xt1 ^ xt2 ^ xt3;
        x4 = sm4_wb_ctx->Table[i][0][(x4 >> 24) & 0xff] ^ sm4_wb_ctx->Table[i][1][(x4 >> 16) & 0xff] ^ sm4_wb_ctx->Table[i][2][(x4 >> 8) & 0xff] ^ sm4_wb_ctx->Table[i][3][x4 & 0xff];
        xt0 = affineU32(sm4_wb_ctx->C[i], x0);
        xt4 = affineU32(sm4_wb_ctx->D[i], x4);
        x4 = xt0 ^ xt4;
        
        x0=x1;
        x1=x2;
        x2=x3;
        x3=x4;
    }
    x4 = x2;
    x2 = x0;
    x0 = x3;
    x3 = x1;

    x0 = affineU32(sm4_wb_ctx->FE[3], x0);
    x4 = affineU32(sm4_wb_ctx->FE[2], x4);
    x3 = affineU32(sm4_wb_ctx->FE[1], x3);
    x2 = affineU32(sm4_wb_ctx->FE[0], x2);

    PUT32(x0, OUT     );
	PUT32(x4, OUT +  4);
	PUT32(x3, OUT +  8);
	PUT32(x2, OUT + 12);
}