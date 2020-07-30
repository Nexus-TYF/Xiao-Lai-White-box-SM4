#include "wbsm4.h"

#define GET32(pc)  (\
	((uint32_t)(pc)[0] << 24) ^	\
	((uint32_t)(pc)[1] << 16) ^\
	((uint32_t)(pc)[2] <<  8) ^\
	((uint32_t)(pc)[3]))

#define PUT32(st, ct)\
(ct)[0] = (uint8_t)((st) >> 24);\
(ct)[1] = (uint8_t)((st) >> 16);\
(ct)[2] = (uint8_t)((st) >>  8);\
(ct)[3] = (uint8_t)(st)

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
int main()
{
    unsigned char IN[16] = {0x00,0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88,0x99,0xaa,0xbb,0xcc,0xdd,0xee,0xff};
    unsigned char key[16] = {0};
    unsigned char OUT[16];
    unsigned char OOUT[16];

    Sm4Whitebox sm4_wb_ctx;
    
    sm4_wb_gen_tables(key, &sm4_wb_ctx);
    printstate(IN); 
    sm4_wb_enc(IN, OUT, &sm4_wb_ctx);
    printstate(OUT);
    
    sm4_context ctx;
    sm4_setkey_enc(&ctx, key);
    sm4_crypt_ecb(&ctx, 1, 16, IN, OOUT);
    printstate(OOUT);
    return 0;
}