#include "WBMatrix/WBMatrix.h"

unsigned int randseed;

M8 baseM8 = {
    .M[0] = 0x80,
    .M[1] = 0x40,
    .M[2] = 0x20,
    .M[3] = 0x10,
    .M[4] = 0x8,
    .M[5] = 0x4,
    .M[6] = 0x2,
    .M[7] = 0x1
};
M16 baseM16 = {
    .M[0] = 0x8000,
    .M[1] = 0x4000,
    .M[2] = 0x2000,
    .M[3] = 0x1000,
    .M[4] = 0x800,
    .M[5] = 0x400,
    .M[6] = 0x200,
    .M[7] = 0x100,
    .M[8] = 0x80,
    .M[9] = 0x40,
    .M[10] = 0x20,
    .M[11] = 0x10,
    .M[12] = 0x8,
    .M[13] = 0x4,
    .M[14] = 0x2,
    .M[15] = 0x1
};
M32 baseM32 = {
    .M[0] = 0x80000000,
    .M[1] = 0x40000000,
    .M[2] = 0x20000000,
    .M[3] = 0x10000000,
    .M[4] = 0x8000000,
    .M[5] = 0x4000000,
    .M[6] = 0x2000000,
    .M[7] = 0x1000000,
    .M[8] = 0x800000,
    .M[9] = 0x400000,
    .M[10] = 0x200000,
    .M[11] = 0x100000,
    .M[12] = 0x80000,
    .M[13] = 0x40000,
    .M[14] = 0x20000,
    .M[15] = 0x10000,
    .M[16] = 0x8000,
    .M[17] = 0x4000,
    .M[18] = 0x2000,
    .M[19] = 0x1000,
    .M[20] = 0x800,
    .M[21] = 0x400,
    .M[22] = 0x200,
    .M[23] = 0x100,
    .M[24] = 0x80,
    .M[25] = 0x40,
    .M[26] = 0x20,
    .M[27] = 0x10,
    .M[28] = 0x8,
    .M[29] = 0x4,
    .M[30] = 0x2,
    .M[31] = 0x1
};
M64 baseM64 = {
    .M[0] = 0x8000000000000000,
    .M[1] = 0x4000000000000000,
    .M[2] = 0x2000000000000000,
    .M[3] = 0x1000000000000000,
    .M[4] = 0x800000000000000,
    .M[5] = 0x400000000000000,
    .M[6] = 0x200000000000000,
    .M[7] = 0x100000000000000,
    .M[8] = 0x80000000000000,
    .M[9] = 0x40000000000000,
    .M[10] = 0x20000000000000,
    .M[11] = 0x10000000000000,
    .M[12] = 0x8000000000000,
    .M[13] = 0x4000000000000,
    .M[14] = 0x2000000000000,
    .M[15] = 0x1000000000000,
    .M[16] = 0x800000000000,
    .M[17] = 0x400000000000,
    .M[18] = 0x200000000000,
    .M[19] = 0x100000000000,
    .M[20] = 0x80000000000,
    .M[21] = 0x40000000000,
    .M[22] = 0x20000000000,
    .M[23] = 0x10000000000,
    .M[24] = 0x8000000000,
    .M[25] = 0x4000000000,
    .M[26] = 0x2000000000,
    .M[27] = 0x1000000000,
    .M[28] = 0x800000000,
    .M[29] = 0x400000000,
    .M[30] = 0x200000000,
    .M[31] = 0x100000000,
    .M[32] = 0x80000000,
    .M[33] = 0x40000000,
    .M[34] = 0x20000000,
    .M[35] = 0x10000000,
    .M[36] = 0x8000000,
    .M[37] = 0x4000000,
    .M[38] = 0x2000000,
    .M[39] = 0x1000000,
    .M[40] = 0x800000,
    .M[41] = 0x400000,
    .M[42] = 0x200000,
    .M[43] = 0x100000,
    .M[44] = 0x80000,
    .M[45] = 0x40000,
    .M[46] = 0x20000,
    .M[47] = 0x10000,
    .M[48] = 0x8000,
    .M[49] = 0x4000,
    .M[50] = 0x2000,
    .M[51] = 0x1000,
    .M[52] = 0x800,
    .M[53] = 0x400,
    .M[54] = 0x200,
    .M[55] = 0x100,
    .M[56] = 0x80,
    .M[57] = 0x40,
    .M[58] = 0x20,
    .M[59] = 0x10,
    .M[60] = 0x8,
    .M[61] = 0x4,
    .M[62] = 0x2,
    .M[63] = 0x1
};
M128 baseM128 = {
    .M[0][0] = 0x8000000000000000,
    .M[1][0] = 0x4000000000000000,
    .M[2][0] = 0x2000000000000000,
    .M[3][0] = 0x1000000000000000,
    .M[4][0] = 0x800000000000000,
    .M[5][0] = 0x400000000000000,
    .M[6][0] = 0x200000000000000,
    .M[7][0] = 0x100000000000000,
    .M[8][0] = 0x80000000000000,
    .M[9][0] = 0x40000000000000,
    .M[10][0] = 0x20000000000000,
    .M[11][0] = 0x10000000000000,
    .M[12][0] = 0x8000000000000,
    .M[13][0] = 0x4000000000000,
    .M[14][0] = 0x2000000000000,
    .M[15][0] = 0x1000000000000,
    .M[16][0] = 0x800000000000,
    .M[17][0] = 0x400000000000,
    .M[18][0] = 0x200000000000,
    .M[19][0] = 0x100000000000,
    .M[20][0] = 0x80000000000,
    .M[21][0] = 0x40000000000,
    .M[22][0] = 0x20000000000,
    .M[23][0] = 0x10000000000,
    .M[24][0] = 0x8000000000,
    .M[25][0] = 0x4000000000,
    .M[26][0] = 0x2000000000,
    .M[27][0] = 0x1000000000,
    .M[28][0] = 0x800000000,
    .M[29][0] = 0x400000000,
    .M[30][0] = 0x200000000,
    .M[31][0] = 0x100000000,
    .M[32][0] = 0x80000000,
    .M[33][0] = 0x40000000,
    .M[34][0] = 0x20000000,
    .M[35][0] = 0x10000000,
    .M[36][0] = 0x8000000,
    .M[37][0] = 0x4000000,
    .M[38][0] = 0x2000000,
    .M[39][0] = 0x1000000,
    .M[40][0] = 0x800000,
    .M[41][0] = 0x400000,
    .M[42][0] = 0x200000,
    .M[43][0] = 0x100000,
    .M[44][0] = 0x80000,
    .M[45][0] = 0x40000,
    .M[46][0] = 0x20000,
    .M[47][0] = 0x10000,
    .M[48][0] = 0x8000,
    .M[49][0] = 0x4000,
    .M[50][0] = 0x2000,
    .M[51][0] = 0x1000,
    .M[52][0] = 0x800,
    .M[53][0] = 0x400,
    .M[54][0] = 0x200,
    .M[55][0] = 0x100,
    .M[56][0] = 0x80,
    .M[57][0] = 0x40,
    .M[58][0] = 0x20,
    .M[59][0] = 0x10,
    .M[60][0] = 0x8,
    .M[61][0] = 0x4,
    .M[62][0] = 0x2,
    .M[63][0] = 0x1,
    .M[64][1] = 0x8000000000000000,
    .M[65][1] = 0x4000000000000000,
    .M[66][1] = 0x2000000000000000,
    .M[67][1] = 0x1000000000000000,
    .M[68][1] = 0x800000000000000,
    .M[69][1] = 0x400000000000000,
    .M[70][1] = 0x200000000000000,
    .M[71][1] = 0x100000000000000,
    .M[72][1] = 0x80000000000000,
    .M[73][1] = 0x40000000000000,
    .M[74][1] = 0x20000000000000,
    .M[75][1] = 0x10000000000000,
    .M[76][1] = 0x8000000000000,
    .M[77][1] = 0x4000000000000,
    .M[78][1] = 0x2000000000000,
    .M[79][1] = 0x1000000000000,
    .M[80][1] = 0x800000000000,
    .M[81][1] = 0x400000000000,
    .M[82][1] = 0x200000000000,
    .M[83][1] = 0x100000000000,
    .M[84][1] = 0x80000000000,
    .M[85][1] = 0x40000000000,
    .M[86][1] = 0x20000000000,
    .M[87][1] = 0x10000000000,
    .M[88][1] = 0x8000000000,
    .M[89][1] = 0x4000000000,
    .M[90][1] = 0x2000000000,
    .M[91][1] = 0x1000000000,
    .M[92][1] = 0x800000000,
    .M[93][1] = 0x400000000,
    .M[94][1] = 0x200000000,
    .M[95][1] = 0x100000000,
    .M[96][1] = 0x80000000,
    .M[97][1] = 0x40000000,
    .M[98][1] = 0x20000000,
    .M[99][1] = 0x10000000,
    .M[100][1] = 0x8000000,
    .M[101][1] = 0x4000000,
    .M[102][1] = 0x2000000,
    .M[103][1] = 0x1000000,
    .M[104][1] = 0x800000,
    .M[105][1] = 0x400000,
    .M[106][1] = 0x200000,
    .M[107][1] = 0x100000,
    .M[108][1] = 0x80000,
    .M[109][1] = 0x40000,
    .M[110][1] = 0x20000,
    .M[111][1] = 0x10000,
    .M[112][1] = 0x8000,
    .M[113][1] = 0x4000,
    .M[114][1] = 0x2000,
    .M[115][1] = 0x1000,
    .M[116][1] = 0x800,
    .M[117][1] = 0x400,
    .M[118][1] = 0x200,
    .M[119][1] = 0x100,
    .M[120][1] = 0x80,
    .M[121][1] = 0x40,
    .M[122][1] = 0x20,
    .M[123][1] = 0x10,
    .M[124][1] = 0x8,
    .M[125][1] = 0x4,
    .M[126][1] = 0x2,
    .M[127][1] = 0x1
};
int basetrailM8[initM8_max][3] = {-1};
int basetrailM16[initM16_max][3] = {-1};
int basetrailM32[initM32_max][3] = {-1};
int basetrailM64[initM64_max][3] = {-1};
int basetrailM128[initM128_max][3] = {-1};

//8bit internal xor table
int xor[] = {0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 
1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 
1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 
1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 
1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 
0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 
1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 
0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 
1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 
1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 
0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 
0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 
1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0};

//8bit Hamming weight table
int HW[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4, 1, 2, 2, 3, 2, 
3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 1, 2, 2, 3, 2, 3, 3, 4, 2, 
3, 3, 4, 3, 4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 
5, 5, 6, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5, 2, 
3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 3, 3, 4, 3, 
4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 
5, 5, 6, 5, 6, 6, 7, 1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 
4, 4, 5, 2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 2, 
3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 
5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 2, 3, 3, 4, 3, 4, 4, 5, 3, 
4, 4, 5, 4, 5, 5, 6, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 
6, 6, 7, 3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7, 4, 
5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8};

uint8_t idM8[8] = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01};
uint16_t idM16[16] = {0x8000, 0x4000, 0x2000, 0x1000, 0x800, 0x400, 0x200, 0x100, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};
uint32_t idM32[32] = {0x80000000, 0x40000000, 0x20000000, 0x10000000, 0x8000000, 0x4000000, 0x2000000, 0x1000000, 0x800000, 0x400000, 0x200000, 0x100000, 0x80000, 0x40000, 0x20000, 0x10000, 0x8000, 0x4000, 0x2000, 0x1000, 0x800, 0x400, 0x200, 0x100, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};
uint64_t idM64[64] = {0x8000000000000000, 0x4000000000000000, 0x2000000000000000, 0x1000000000000000, 0x800000000000000, 0x400000000000000, 0x200000000000000, 0x100000000000000, 0x80000000000000, 0x40000000000000, 0x20000000000000, 0x10000000000000, 0x8000000000000, 0x4000000000000, 0x2000000000000, 0x1000000000000, 0x800000000000, 0x400000000000, 0x200000000000, 0x100000000000, 0x80000000000, 0x40000000000, 0x20000000000, 0x10000000000, 0x8000000000, 0x4000000000, 0x2000000000, 0x1000000000, 0x800000000, 0x400000000, 0x200000000, 0x100000000, \
                        0x80000000, 0x40000000, 0x20000000, 0x10000000, 0x8000000, 0x4000000, 0x2000000, 0x1000000, 0x800000, 0x400000, 0x200000, 0x100000, 0x80000, 0x40000, 0x20000, 0x10000, 0x8000, 0x4000, 0x2000, 0x1000, 0x800, 0x400, 0x200, 0x100, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1};
int initM8_times;
int initM16_times;
int initM32_times;
int initM64_times;
int initM128_times;

void SetRandSeed(unsigned int seed)
{
    randseed = seed;
}

void initM8(M8 *Mat)//initial Matrix 8*8
{
    for(int i = 0; i < 8; i++)
    {
        (*Mat).M[i] = 0;
    }
}
void initM16(M16 *Mat)//initial Matrix 16*16
{
    for(int i = 0; i < 16; i++)
    {
        (*Mat).M[i] = 0;
    }
}
void initM32(M32 *Mat)//initial Matrix 32*32
{
    for(int i = 0; i < 32; i++)
    {
        (*Mat).M[i] = 0;
    }
}
void initM64(M64 *Mat)//initial Matrix 64*64
{
    for(int i = 0; i < 64; i++)
    {
        (*Mat).M[i] = 0;
    }
}
void initM128(M128 *Mat)//initial Matrix 128*128
{
    for(int i = 0; i < 128; i++)
    {
        (*Mat).M[i][0] = 0;
        (*Mat).M[i][1] = 0;
    }
}
void initV8(V8 *Vec)//initial Vector 8*1
{
    (*Vec).V = 0;
}
void initV16(V16 *Vec)//initial Vector 16*1
{
    (*Vec).V = 0;
}
void initV32(V32 *Vec)//initial Vector 32*1
{
    (*Vec).V = 0;
}
void initV64(V64 *Vec)//initial Vector 64*1
{
    (*Vec).V = 0;
}
void initV128(V128 *Vec)//initial Vector 128*1
{
    (*Vec).V[0] = 0;
    (*Vec).V[1] = 0;
}
void randM8(M8 *Mat)//randomize Matrix 8*8 
{
    InitRandom((randseed++)^((unsigned int)time(NULL)));
    for(int i = 0; i < 8; i++)
    {
        (*Mat).M[i] = cus_random();
    }
}
void randM16(M16 *Mat)//randomize Matrix 16*16 
{
    InitRandom((randseed++)^((unsigned int)time(NULL)));
    for(int i = 0; i < 16; i++)
    {
        (*Mat).M[i] = cus_random();
    }
}
void randM32(M32 *Mat)//randomize Matrix 32*32 
{
    InitRandom((randseed++)^((unsigned int)time(NULL)));
    for(int i = 0; i < 32; i++)
    {
        (*Mat).M[i] = cus_random();
    }
}
void randM64(M64 *Mat)//randomize Matrix 64*64 
{
    InitRandom((randseed++)^((unsigned int)time(NULL)));
    uint32_t *m;
    for(int i = 0; i < 64; i++)
    {
        m = (uint32_t*)&((*Mat).M[i]);
        *(m+1) = cus_random();
        *m = cus_random();
    }
}
void randM128(M128 *Mat)//randomize Matrix 128*128 
{
    InitRandom((randseed++)^((unsigned int)time(NULL)));
    uint32_t *m;
    for(int i = 0; i < 128; i++)
    {
        m = (uint32_t*)&((*Mat).M[i][0]);
        *(m+1) = cus_random();
        *m = cus_random();
        m = (uint32_t*)&((*Mat).M[i][1]);
        *(m+1) = cus_random();
        *m = cus_random();
    }
}
void identityM8(M8 *Mat)//identity matrix 8*8
{
    for(int i = 0; i < 8; i++)
    {
        (*Mat).M[i] = idM8[i];
    }
}
void identityM16(M16 *Mat)//identity matrix 16*16
{
    for(int i = 0; i < 16; i++)
    {
        (*Mat).M[i] = idM16[i];
    }
}
void identityM32(M32 *Mat)//identity matrix 32*32
{
    for(int i = 0; i < 32; i++)
    {
        (*Mat).M[i] = idM32[i];
    }
}
void identityM64(M64 *Mat)//identity matrix 64*64
{
    for(int i = 0; i < 64; i++)
    {
        (*Mat).M[i] = idM64[i];
    }
}
void identityM128(M128 *Mat)//identity matrix 128*128
{
    for(int i = 0; i < 64; i++)
    {
        (*Mat).M[i][0] = idM64[i];
        (*Mat).M[i][1] = 0;
    }
    for(int i = 64; i < 128; i++)
    {
        (*Mat).M[i][0] = 0;
        (*Mat).M[i][1] = idM64[i-64];
    }
}
void randV8(V8 *Vec)//randomize Vector 8*1
{
    InitRandom((randseed++)^(unsigned int)time(NULL));
    (*Vec).V = cus_random();
}
void randV16(V16 *Vec)//randomize Vector 16*1
{
    InitRandom((randseed++)^(unsigned int)time(NULL));
    (*Vec).V = cus_random();
}
void randV32(V32 *Vec)//randomize Vector 32*1
{
    uint16_t *v = (uint16_t*)&((*Vec).V);
    InitRandom((randseed++)^(unsigned int)time(NULL));
    *(v+1) = cus_random();
    *v = cus_random();
}
void randV64(V64 *Vec)//randomize Vector 64*1
{
    uint16_t *v = (uint16_t*)&((*Vec).V);
    InitRandom((randseed++)^(unsigned int)time(NULL));
    *(v+3) = cus_random();
    *(v+2) = cus_random();
    *(v+1) = cus_random();
    *v = cus_random();
}
void randV128(V128 *Vec)//randomize Vector 128*1
{
    uint16_t *v = (uint16_t*)&((*Vec).V[0]);
    InitRandom((randseed++)^(unsigned int)time(NULL));
    *(v+3) = cus_random();
    *(v+2) = cus_random();
    *(v+1) = cus_random();
    *v = cus_random();
    v = (uint16_t*)&((*Vec).V[1]);
    *(v+3) = cus_random();
    *(v+2) = cus_random();
    *(v+1) = cus_random();
    *v = cus_random();
}
void printM8(M8 Mat)//printf Matrix 8*8
{
    for(int i = 0; i < 8; i++)
    {
        printf("0x%x\n", Mat.M[i]);
    }
}
void printM16(M16 Mat)//printf Matrix 16*16
{
    for(int i = 0; i < 16; i++)
    {
        printf("0x%x\n", Mat.M[i]);
    }
}
void printM32(M32 Mat)//printf Matrix 32*32
{
    for(int i = 0; i < 32; i++)
    {
        printf("0x%x\n", Mat.M[i]);
    }
}
void printM64(M64 Mat)//printf Matrix 64*64
{
    for(int i = 0; i < 64; i++)
    {
        printf("0x%llx\n", Mat.M[i]);
    }
}
void printM128(M128 Mat)//printf Matrix 128*128
{
    for(int i = 0; i < 128; i++)
    {
        printf("0x%llx ", Mat.M[i][0]);
        printf("0x%llx\n", Mat.M[i][1]);
    }
}
void printV8(V8 Vec)//printf Vector 8*1
{
    printf("0x%x\n", Vec.V);
}
void printV16(V16 Vec)//printf Vector 16*1
{
    printf("0x%x\n", Vec.V);
}
void printV32(V32 Vec)//printf Vector 32*1
{
    printf("0x%x\n", Vec.V);
}
void printV64(V64 Vec)//printf Vector 64*1
{
    printf("0x%llx\n", Vec.V);
}
void printV128(V128 Vec)//printf Vector 128*1
{
    printf("0x%llx ", Vec.V[0]);
    printf("0x%llx\n", Vec.V[1]);
}
void copyM8(M8 Mat1, M8 *Mat2)
{
    for(int i = 0; i < 8; i++)
    {
        (*Mat2).M[i] = Mat1.M[i];
    }
}
void copyM16(M16 Mat1, M16 *Mat2)
{
    for(int i = 0; i < 16; i++)
    {
        (*Mat2).M[i] = Mat1.M[i];
    }
}
void copyM32(M32 Mat1, M32 *Mat2)
{
    for(int i = 0; i < 32; i++)
    {
        (*Mat2).M[i] = Mat1.M[i];
    }
}
void copyM64(M64 Mat1, M64 *Mat2)
{
    for(int i = 0; i < 64; i++)
    {
        (*Mat2).M[i] = Mat1.M[i];
    }
}
void copyM128(M128 Mat1, M128 *Mat2)
{
    for(int i = 0; i < 128; i++)
    {
        (*Mat2).M[i][0] = Mat1.M[i][0];
        (*Mat2).M[i][1] = Mat1.M[i][1];
    }
}
int isequalM8(M8 Mat1, M8 Mat2)
{
    int flag = 1;
    for(int i = 0; i < 8; i++)
    {
        if(Mat1.M[i] != Mat2.M[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int isequalM16(M16 Mat1, M16 Mat2)
{
    int flag = 1;
    for(int i = 0; i < 16; i++)
    {
        if(Mat1.M[i] != Mat2.M[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int isequalM32(M32 Mat1, M32 Mat2)
{
    int flag = 1;
    for(int i = 0; i < 32; i++)
    {
        if(Mat1.M[i] != Mat2.M[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int isequalM64(M64 Mat1, M64 Mat2)
{
    int flag = 1;
    for(int i = 0; i < 64; i++)
    {
        if(Mat1.M[i] != Mat2.M[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int isequalM128(M128 Mat1, M128 Mat2)
{
    int flag = 1;
    for(int i = 0; i < 128; i++)
    {
        if(Mat1.M[i][0] != Mat2.M[i][0])
        {
            flag = 0;
            break;
        }
        if(Mat1.M[i][1] != Mat2.M[i][1])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
int isequalV8(V8 Vec1, V8 Vec2)
{
    int flag = 1;
    if(Vec1.V != Vec2.V) flag = 0;
    return flag;
}
int isequalV16(V16 Vec1, V16 Vec2)
{
    int flag = 1;
    if(Vec1.V != Vec2.V) flag = 0;
    return flag;
}
int isequalV32(V32 Vec1, V32 Vec2)
{
    int flag = 1;
    if(Vec1.V != Vec2.V) flag = 0;
    return flag;
}
int isequalV64(V64 Vec1, V64 Vec2)
{
    int flag = 1;
    if(Vec1.V != Vec2.V) flag = 0;
    return flag;
}
int isequalV128(V128 Vec1, V128 Vec2)
{
    int flag = 1;
    if(Vec1.V[0] != Vec2.V[0]) flag = 0;
    if(Vec1.V[1] != Vec2.V[1]) flag = 0;
    return flag;
}
int isinvertM8(M8 Mat)//Invertible Matrix?
{
    uint8_t temp;
    int flag;
    for(int i = 0; i < 8; i++)
    {
        if((Mat.M[i] & idM8[i]) == idM8[i])
        {
            for(int j = i + 1; j < 8; j++)
            {
                if((Mat.M[j] & idM8[i]) == idM8[i])
                {
                    Mat.M[j] ^= Mat.M[i];
                }
            }
        }
        else
        {
            flag = 1;
            for(int j = i + 1; j < 8; j++)
            {
                if((Mat.M[j] & idM8[i]) == idM8[i])
                {
                    temp = Mat.M[i];
                    Mat.M[i] = Mat.M[j];
                    Mat.M[j] = temp;
                    flag = 0;
                    break;
                }
            }
            if(flag) return 0;
            for(int k = i + 1; k < 8; k++)
            {
                if((Mat.M[k] & idM8[i]) == idM8[i])
                {
                    Mat.M[k] ^= Mat.M[i];
                }
            }
        }
    }
    if(Mat.M[7] == idM8[7]) return 1;
    else return 0;
}
int isinvertM16(M16 Mat)//Invertible Matrix?
{
    uint16_t temp;
    int flag;
    for(int i = 0; i < 16; i++)
    {
        if((Mat.M[i] & idM16[i]) == idM16[i])
        {
            for(int j = i + 1; j < 16; j++)
            {
                if((Mat.M[j] & idM16[i]) == idM16[i])
                {
                    Mat.M[j] ^= Mat.M[i];
                }
            }
        }
        else
        {
            flag = 1;
            for(int j = i + 1; j < 16; j++)
            {
                if((Mat.M[j] & idM16[i]) == idM16[i])
                {
                    temp = Mat.M[i];
                    Mat.M[i] = Mat.M[j];
                    Mat.M[j] = temp;
                    flag = 0;
                    break;
                }
            }
            if(flag) return 0;
            for(int k = i + 1; k < 16; k++)
            {
                if((Mat.M[k] & idM16[i]) == idM16[i])
                {
                    Mat.M[k] ^= Mat.M[i];
                }
            }
        }
    }
    if(Mat.M[15] == idM16[15]) return 1;
    else return 0;
}
int isinvertM32(M32 Mat)//Invertible Matrix?
{
    uint32_t temp;
    int flag;
    for(int i = 0; i < 32; i++)
    {
        if((Mat.M[i] & idM32[i]) == idM32[i])
        {
            for(int j = i + 1; j < 32; j++)
            {
                if((Mat.M[j] & idM32[i]) == idM32[i])
                {
                    Mat.M[j] ^= Mat.M[i];
                }
            }
        }
        else
        {
            flag = 1;
            for(int j = i + 1; j < 32; j++)
            {
                if((Mat.M[j] & idM32[i]) == idM32[i])
                {
                    temp = Mat.M[i];
                    Mat.M[i] = Mat.M[j];
                    Mat.M[j] = temp;
                    flag = 0;
                    break;
                }
            }
            if(flag) return 0;
            for(int k = i + 1; k < 32; k++)
            {
                if((Mat.M[k] & idM32[i]) == idM32[i])
                {
                    Mat.M[k] ^= Mat.M[i];
                }
            }
        }
    }
    if(Mat.M[31] == idM32[31]) return 1;
    else return 0;
}
int isinvertM64(M64 Mat)//Invertible Matrix?
{
    uint64_t temp;
    int flag;
    for(int i = 0; i < 64; i++)
    {
        if((Mat.M[i] & idM64[i]) == idM64[i])
        {
            for(int j = i + 1; j < 64; j++)
            {
                if((Mat.M[j] & idM64[i]) == idM64[i])
                {
                    Mat.M[j] ^= Mat.M[i];
                }
            }
        }
        else
        {
            flag = 1;
            for(int j = i + 1; j < 64; j++)
            {
                if((Mat.M[j] & idM64[i]) == idM64[i])
                {
                    temp = Mat.M[i];
                    Mat.M[i] = Mat.M[j];
                    Mat.M[j] = temp;
                    flag = 0;
                    break;
                }
            }
            if(flag) return 0;
            for(int k = i + 1; k < 64; k++)
            {
                if((Mat.M[k] & idM64[i]) == idM64[i])
                {
                    Mat.M[k] ^= Mat.M[i];
                }
            }
        }
    }
    if(Mat.M[63] == idM64[63]) return 1;
    else return 0;
}
int isinvertM128(M128 Mat)//Invertible Matrix?
{
    uint64_t temp[2];
    int flag;
    for(int i = 0; i < 64; i++)
    {
        if((Mat.M[i][0] & idM64[i]) == idM64[i])
        {
            for(int j = i + 1; j < 128; j++)
            {
                if((Mat.M[j][0] & idM64[i]) == idM64[i])
                {
                    Mat.M[j][0] ^= Mat.M[i][0];
                    Mat.M[j][1] ^= Mat.M[i][1];
                }
            }
        }
        else
        {
            flag = 1;
            for(int j = i + 1; j < 128; j++)
            {
                if((Mat.M[j][0] & idM64[i]) == idM64[i])
                {
                    temp[0] = Mat.M[i][0];
                    Mat.M[i][0] = Mat.M[j][0];
                    Mat.M[j][0] = temp[0];

                    temp[1] = Mat.M[i][1];
                    Mat.M[i][1] = Mat.M[j][1];
                    Mat.M[j][1] = temp[1];
                    flag = 0;
                    break;
                }
            }
            if(flag) return 0;
            for(int k = i + 1; k < 128; k++)
            {
                if((Mat.M[k][0] & idM64[i]) == idM64[i])
                {
                    Mat.M[k][0] ^= Mat.M[i][0];
                    Mat.M[k][1] ^= Mat.M[i][1];
                }
            }
        }
    }
    for(int i = 64; i < 128;i++)
    {
        if((Mat.M[i][1] & idM64[i-64]) == idM64[i-64])
        {
            for(int j = i + 1; j < 128; j++)
            {
                if((Mat.M[j][1] & idM64[i-64]) == idM64[i-64])
                {
                    Mat.M[j][1] ^= Mat.M[i][1];
                }
            }
        }
        else
        {
            flag = 1;
            for(int j = i + 1; j < 128; j++)
            {
                if((Mat.M[j][1] & idM64[i-64]) == idM64[i-64])
                {
                    temp[1] = Mat.M[i][1];
                    Mat.M[i][1] = Mat.M[j][1];
                    Mat.M[j][1] = temp[1];
                    flag = 0;
                    break;
                }
            }
            if(flag) return 0;
            for(int k = i + 1; k < 128; k++)
            {
                if((Mat.M[k][1] & idM64[i-64]) == idM64[i-64])
                {
                    Mat.M[k][1] ^= Mat.M[i][1];
                }
            }
        }
    }
    if(Mat.M[127][1] == idM64[63]) return 1;
    else return 0;
}
uint8_t affineU8(Aff8 aff, uint8_t arr)//8bits affine transformation
{
    V8 mul_vec, ans_vec;
    mul_vec.V = arr;
    MatMulVecM8(aff.Mat, mul_vec, &ans_vec);//mul
    return ans_vec.V ^ aff.Vec.V;//add
}
uint16_t affineU16(Aff16 aff, uint16_t arr)//16bits affine transformation
{
    V16 mul_vec, ans_vec;
    mul_vec.V = arr;
    MatMulVecM16(aff.Mat, mul_vec, &ans_vec);//mul
    return ans_vec.V ^ aff.Vec.V;//add
}
uint32_t affineU32(Aff32 aff, uint32_t arr)//32bits affine transformation
{
    V32 mul_vec, ans_vec;
    mul_vec.V = arr;
    MatMulVecM32(aff.Mat, mul_vec, &ans_vec);//mul
    return ans_vec.V ^ aff.Vec.V;//add
}
uint64_t affineU64(Aff64 aff, uint64_t arr)//64bits affine transformation
{
    V64 mul_vec, ans_vec;
    mul_vec.V = arr;
    MatMulVecM64(aff.Mat, mul_vec, &ans_vec);//mul
    return ans_vec.V ^ aff.Vec.V;//add
}
void affineU128(Aff128 aff, uint64_t arr[], uint64_t ans[])//128bits affine transformation
{
    V128 mul_vec, ans_vec;
    mul_vec.V[0] = arr[0];
    mul_vec.V[1] = arr[1];
    MatMulVecM128(aff.Mat, mul_vec, &ans_vec);//mul
    ans[0] = ans_vec.V[0] ^ aff.Vec.V[0];//add
    ans[1] = ans_vec.V[1] ^ aff.Vec.V[1];
}
int xorU8(uint8_t n)// uint8_t internal xor
{
    if(xor[n]) return 1;
    else return 0;
}
int xorU16(uint16_t n)// uint16_t internal xor
{
    uint8_t temp = 0;
    uint8_t* u = (uint8_t*)&n;
    temp = (*u) ^ (*(u+1));
    if(xorU8(temp)) return 1;
    else return 0;
}
int xorU32(uint32_t n)// uint32_t internal xor
{
    uint16_t temp = 0;
    uint16_t* u = (uint16_t*)&n;
    temp = (*u) ^ (*(u+1));
    if(xorU16(temp)) return 1;
    else return 0;
}
int xorU64(uint64_t n)// uint64_t internal xor
{
    uint32_t temp = 0;
    uint32_t* u = (uint32_t*)&n;
    temp = (*u) ^ (*(u+1));
    if(xorU32(temp)) return 1;
    else return 0;
}
int xorU128(uint64_t n[])// uint128_t internal xor
{
    uint64_t temp = 0;
    temp = n[0] ^ n[1];
    if(xorU64(temp)) return 1;
    else return 0;
}
int HWU8(uint8_t n)// uint8_t HW
{
    return HW[n];
}
int HWU16(uint16_t n)// uint16_t HW
{
    uint8_t* u = (uint8_t*)&n;
    return HWU8(*u) + HWU8(*(u+1));
}
int HWU32(uint32_t n)// uint32_t HW
{
    uint16_t* u = (uint16_t*)&n;
    return HWU16(*u) + HWU16(*(u+1));
}
int HWU64(uint64_t n)// uint64_t HW
{
    uint32_t* u = (uint32_t*)&n;
    return HWU32(*u) + HWU32(*(u+1));
}
int HWU128(uint64_t n[])// uint128_t HW
{
    return HWU64(n[0]) + HWU64(n[1]);
}
void printU8(uint8_t n)//printf uint8_t
{
    printf("0x%x\n", n);
}
void printU16(uint16_t n)//printf uint16_t
{
    printf("0x%x\n", n);
}
void printU32(uint32_t n)//printf uint32_t
{
    printf("0x%x\n", n);
}
void printU64(uint64_t n)//printf uint64_t
{
    printf("0x%x\n", n);
}
void printU128(uint64_t n[])//printf uint128_t
{
    printf("0x%x ", n[0]);
    printf("0x%x\n", n[1]);
}
void printbitM8(M8 Mat)//printf Matrix 8*8 in the form of bits 
{
    uint8_t temp;
    for(int i = 0; i < 8; i++)
    {
        temp = Mat.M[i];
        for(int j = 0; j < 8; j++)
        {
            if(temp & 0x80) printf("%d ", 1);
            else printf("%d ", 0);
            temp = temp << 1;
        }
        printf("\n");
    }
    printf("\n");
}
void printbitM16(M16 Mat)//printf Matrix 16*16 in the form of bits 
{
    uint16_t temp;
    for(int i = 0; i < 16; i++)
    {
        temp = Mat.M[i];
        for(int j = 0; j < 16; j++)
        {
            if(temp & 0x8000) printf("%d ", 1);
            else printf("%d ", 0);
            temp = temp << 1;
        }
        printf("\n");
    }
    printf("\n");
}
void printbitM32(M32 Mat)//printf Matrix 32*32 in the form of bits 
{
    uint32_t temp;
    for(int i = 0; i < 32; i++)
    {
        temp = Mat.M[i];
        for(int j = 0; j < 32; j++)
        {
            if(temp & 0x80000000) printf("%d ", 1);
            else printf("%d ", 0);
            temp = temp << 1;
        }
        printf("\n");
    }
    printf("\n");
}
void printbitM64(M64 Mat)//printf Matrix 64*64 in the form of bits 
{
    uint64_t temp;
    for(int i = 0; i < 64; i++)
    {
        temp = Mat.M[i];
        for(int j = 0; j < 64; j++)
        {
            if(temp & 0x8000000000000000) printf("%d ", 1);
            else printf("%d ", 0);
            temp = temp << 1;
        }
        printf("\n");
    }
    printf("\n");
}
void printbitM128(M128 Mat)//printf Matrix 128*128 in the form of bits 
{
    uint64_t temp;
    for(int i = 0; i < 128; i++)
    {
        temp = Mat.M[i][0];
        for(int j = 0; j < 64; j++)
        {
            if(temp & 0x8000000000000000) printf("%d ", 1);
            else printf("%d ", 0);
            temp = temp << 1;
        }
        temp = Mat.M[i][1];
        for(int j = 0; j < 64; j++)
        {
            if(temp & 0x8000000000000000) printf("%d ", 1);
            else printf("%d ", 0);
            temp = temp << 1;
        }
        printf("\n");
    }
    printf("\n");
}
void VecAddVecV8(V8 Vec1, V8 Vec2, V8 *Vec)
{
    (*Vec).V = Vec1.V ^ Vec2.V;
}
void VecAddVecV16(V16 Vec1, V16 Vec2, V16 *Vec)
{
    (*Vec).V = Vec1.V ^ Vec2.V;
}
void VecAddVecV32(V32 Vec1, V32 Vec2, V32 *Vec)
{
    (*Vec).V = Vec1.V ^ Vec2.V;
}
void VecAddVecV64(V64 Vec1, V64 Vec2, V64 *Vec)
{
    (*Vec).V = Vec1.V ^ Vec2.V;
}
void VecAddVecV128(V128 Vec1, V128 Vec2, V128 *Vec)
{
    (*Vec).V[0] = Vec1.V[0] ^ Vec2.V[0];
    (*Vec).V[1] = Vec1.V[1] ^ Vec2.V[1];
}
uint8_t MatMulNumM8(M8 Mat, uint8_t n)//matrix * number -> number 8bits
{
    uint8_t temp = 0;
    for(int i = 0; i < 8; i++)
    {
        if(xorU8(Mat.M[i] & n)) temp ^= idM8[i];
    }
    return temp;
}
uint16_t MatMulNumM16(M16 Mat, uint16_t n)//matrix * number -> number 16bits
{
    uint16_t temp = 0;
    for(int i = 0; i < 16; i++)
    {
        if(xorU16(Mat.M[i] & n)) temp ^= idM16[i];
    }
    return temp;
}
uint32_t MatMulNumM32(M32 Mat, uint32_t n)//matrix * number -> number 32bits
{
    uint32_t temp = 0;
    for(int i = 0; i < 32; i++)
    {
        if(xorU32(Mat.M[i] & n)) temp ^= idM32[i];
    }
    return temp;
}
uint64_t MatMulNumM64(M64 Mat, uint64_t n)//matrix * number -> number 64bits
{
    uint64_t temp = 0;
    for(int i = 0; i < 64; i++)
    {
        if(xorU64(Mat.M[i] & n)) temp ^= idM64[i];
    }
    return temp;
}
void MatMulVecM8(M8 Mat, V8 Vec, V8 *ans)//matrix * vector -> vector 8*1
{
    initV8(ans);
    for(int i = 0; i < 8; i++)
    {
        if(xorU8(Mat.M[i] & Vec.V)) (*ans).V ^= idM8[i];
    }
}
void MatMulVecM16(M16 Mat, V16 Vec, V16 *ans)//matrix * vector -> vector 16*1
{
    initV16(ans);
    for(int i = 0; i < 16; i++)
    {
        if(xorU16(Mat.M[i] & Vec.V)) (*ans).V ^= idM16[i];
    }
}
void MatMulVecM32(M32 Mat, V32 Vec, V32 *ans)//matrix * vector -> vector 32*1
{
    initV32(ans);
    for(int i = 0; i < 32; i++)
    {
        if(xorU32(Mat.M[i] & Vec.V)) (*ans).V ^= idM32[i];
    }
}
void MatMulVecM64(M64 Mat, V64 Vec, V64 *ans)//matrix * vector -> vector 64*1
{
    initV64(ans);
    for(int i = 0; i < 64; i++)
    {
        if(xorU64(Mat.M[i] & Vec.V)) (*ans).V ^= idM64[i];
    }
}
void MatMulVecM128(M128 Mat, V128 Vec, V128 *ans)//matrix * vector -> vector 128*1
{
    initV128(ans);
    uint64_t temp[2]; 
    for(int i = 0; i < 64; i++)
    {
        temp[0] = Mat.M[i][0] & Vec.V[0];
        temp[1] = Mat.M[i][1] & Vec.V[1];
        if(xorU128(temp)) (*ans).V[0] ^= idM64[i];
    }
    for(int i = 64; i < 128; i++)
    {
        temp[0] = Mat.M[i][0] & Vec.V[0];
        temp[1] = Mat.M[i][1] & Vec.V[1];
        if(xorU128(temp)) (*ans).V[1] ^= idM64[i-64];
    }
}
void freebaseM8()
{
    identityM8(&baseM8);
    basetrailM8[0][0] = -1;
}
void freebaseM16()
{
    identityM16(&baseM16);
    basetrailM16[0][0] = -1;
}
void freebaseM32()
{
    identityM32(&baseM32);
    basetrailM32[0][0] = -1;
}
void freebaseM64()
{
    identityM64(&baseM64);
    basetrailM64[0][0] = -1;
}
void freebaseM128()
{
    identityM128(&baseM128);
    basetrailM128[0][0] = -1;
}
void initinvbaseM8(int N)//initial base matrix,  parameter: initM8_min ,  initM8_max
{
    int p, q;
    uint8_t temp;
    InitRandom((randseed++)^(unsigned int)time(NULL));
    if(basetrailM8[0][0] != -1) return ;
    initM8_times = N;
    for(int i = 0; i < initM8_times; i++)//generate reversible base matrix
    {
        p = cus_random()%8;
        q = cus_random()%8;
        while(p == q)
        {
            p = cus_random()%8;
            q = cus_random()%8;
        }
        if(p > q)//add
        {
            
            baseM8.M[p] ^= baseM8.M[q];
            basetrailM8[i][0] = 1;
            basetrailM8[i][1] = p;
            basetrailM8[i][2] = q;
        }
        else//swap
        {
            temp = baseM8.M[p];
            baseM8.M[p] = baseM8.M[q];
            baseM8.M[q] = temp;
            basetrailM8[i][0] = 0;
            basetrailM8[i][1] = p;
            basetrailM8[i][2] = q;
        }   
    }
}
void genMatpairM8(M8 *Mat, M8 *Mat_inv)//generate 8*8 reversible matrix and its inverse matrix
{
    int p, q;
    uint8_t temp;
    int trail[M8N][3];// generate trail
    copyM8(baseM8, Mat);//copy base matrix
    identityM8(Mat_inv);
    InitRandom((randseed++)^(unsigned int)time(NULL));
    for(int i = 0; i < M8N; i++)//generate reversible matrix
    {
        p = cus_random()%8;
        q = cus_random()%8;
        while(p == q)
        {
            p = cus_random()%8;
            q = cus_random()%8;
        }
        if(p > q)//add
        {
            
            (*Mat).M[p] ^= (*Mat).M[q];
            trail[i][0] = 1;
            trail[i][1] = p;
            trail[i][2] = q;
        }
        else//swap
        {
            temp = (*Mat).M[p];
            (*Mat).M[p] = (*Mat).M[q];
            (*Mat).M[q] = temp;
            trail[i][0] = 0;
            trail[i][1] = p;
            trail[i][2] = q;
        }   
    }
    /* *** the example for mitigating DCA attack
    int extratimes = 0;
    if(antiDCA)
    {
        for(int i = 0; i < 8; i++)
        {
            while(HW8((*Mat).M[i]) == 1)
            {
                p = cus_random()%8;
                while(p == i)
                {
                    p = cus_random()%8;
                }
                (*Mat).M[i] ^= (*Mat).M[p];
                trail[M8N+extratimes][0] = 1;
                trail[M8N+extratimes][1] = i;
                trail[M8N+extratimes][2] = p;
                extratimes++;
            }
        }
    }
    */
    for(int j = M8N - 1; j >= 0; j--)//generate inverse matrix
    {
        if(trail[j][0])//add
        {
            (*Mat_inv).M[trail[j][1]] ^=  (*Mat_inv).M[trail[j][2]];
        }
        else//swap
        {
            temp = (*Mat_inv).M[trail[j][1]];
            (*Mat_inv).M[trail[j][1]] = (*Mat_inv).M[trail[j][2]];
            (*Mat_inv).M[trail[j][2]] = temp;
        }   
    }
    if(basetrailM8[0][0] != -1)//base matrix
    {
        for(int j = initM8_times - 1; j >= 0; j--)//generate inverse matrix
        {
            if(basetrailM8[j][0])//add
            {
                (*Mat_inv).M[basetrailM8[j][1]] ^= (*Mat_inv).M[basetrailM8[j][2]];
            }
            else//swap
            {
                temp = (*Mat_inv).M[basetrailM8[j][1]];
                (*Mat_inv).M[basetrailM8[j][1]] = (*Mat_inv).M[basetrailM8[j][2]];
                (*Mat_inv).M[basetrailM8[j][2]] = temp;
            }   
        }
    }
}
void initinvbaseM16(int N)//initial base matrix,  parameter: initM16_min ,  initM16_max
{
    int p, q;
    uint16_t temp;
    InitRandom((randseed++)^(unsigned int)time(NULL));
    if(basetrailM16[0][0] != -1) return ;
    initM16_times = N;
    for(int i = 0; i < initM16_times; i++)//generate reversible base matrix
    {
        p = cus_random()%16;
        q = cus_random()%16;
        while(p == q)
        {
            p = cus_random()%16;
            q = cus_random()%16;
        }
        if(p > q)//add
        {
            
            baseM16.M[p] ^= baseM16.M[q];
            basetrailM16[i][0] = 1;
            basetrailM16[i][1] = p;
            basetrailM16[i][2] = q;
        }
        else//swap
        {
            temp = baseM16.M[p];
            baseM16.M[p] = baseM16.M[q];
            baseM16.M[q] = temp;
            basetrailM16[i][0] = 0;
            basetrailM16[i][1] = p;
            basetrailM16[i][2] = q;
        }   
    }
}
void genMatpairM16(M16 *Mat, M16 *Mat_inv)//generate 16*16 reversible matrix and its inverse matrix
{
    int p, q;
    uint16_t temp;
    int trail[M16N][3];
    copyM16(baseM16, Mat);//copy base matrix
    identityM16(Mat_inv);
    InitRandom((randseed++)^(unsigned int)time(NULL));
    for(int i = 0; i < M16N; i++)//generate reversible matrix
    {
        p = cus_random()%16;
        q = cus_random()%16;
        while(p == q)
        {
            p = cus_random()%16;
            q = cus_random()%16;
        }
        if(p > q)//add
        {
            
            (*Mat).M[p] ^= (*Mat).M[q];
            trail[i][0] = 1;
            trail[i][1] = p;
            trail[i][2] = q;
        }
        else//swap
        {
            p = cus_random()%16;
            q = cus_random()%16;
            while(p == q)
            {
                p = cus_random()%16;
                q = cus_random()%16;
            }
            temp = (*Mat).M[p];
            (*Mat).M[p] = (*Mat).M[q];
            (*Mat).M[q] = temp;
            trail[i][0] = 0;
            trail[i][1] = p;
            trail[i][2] = q;
        }   
    }
    for(int j = M16N - 1; j >= 0; j--)//generate inverse matrix
    {
        if(trail[j][0])//add
        {
            (*Mat_inv).M[trail[j][1]] ^= (*Mat_inv).M[trail[j][2]];
        }
        else//swap
        {
            temp = (*Mat_inv).M[trail[j][1]];
            (*Mat_inv).M[trail[j][1]] = (*Mat_inv).M[trail[j][2]];
            (*Mat_inv).M[trail[j][2]] = temp;
        }   
    }
    if(basetrailM16[0][0] != -1)
    {
        for(int j = initM16_times - 1; j >= 0; j--)//generate inverse matrix for base matrix
        {
            if(basetrailM16[j][0])//add
            {
                (*Mat_inv).M[basetrailM16[j][1]] ^= (*Mat_inv).M[basetrailM16[j][2]];
            }
            else//swap
            {
                temp = (*Mat_inv).M[basetrailM16[j][1]];
                (*Mat_inv).M[basetrailM16[j][1]] = (*Mat_inv).M[basetrailM16[j][2]];
                (*Mat_inv).M[basetrailM16[j][2]] = temp;
            }
        }
    }
}
void initinvbaseM32(int N)//initial base matrix,  parameter: initM32_min ,  initM32_max
{
    int p, q;
    uint32_t temp;
    InitRandom((randseed++)^(unsigned int)time(NULL));
    if(basetrailM32[0][0] != -1) return ;
    initM32_times = N;
    for(int i = 0; i < initM32_times; i++)//generate reversible base matrix
    {
        p = cus_random()%32;
        q = cus_random()%32;
        while(p == q)
        {
            p = cus_random()%32;
            q = cus_random()%32;
        }
        if(p > q)//add
        {
            
            baseM32.M[p] ^= baseM32.M[q];
            basetrailM32[i][0] = 1;
            basetrailM32[i][1] = p;
            basetrailM32[i][2] = q;
        }
        else//swap
        {
            temp = baseM32.M[p];
            baseM32.M[p] = baseM32.M[q];
            baseM32.M[q] = temp;
            basetrailM32[i][0] = 0;
            basetrailM32[i][1] = p;
            basetrailM32[i][2] = q;
        }   
    }
}
void genMatpairM32(M32 *Mat, M32 *Mat_inv)//generate 32*32 reversible matrix and its inverse matrix
{
    int p, q;
    uint32_t temp;
    int trail[M32N][3];
    copyM32(baseM32, Mat);//copy base matrix
    identityM32(Mat_inv);
    InitRandom((randseed++)^(unsigned int)time(NULL));
    for(int i = 0; i < M32N; i++)//generate reversible matrix
    {
        p = cus_random()%32;
        q = cus_random()%32;
        while(p == q)
        {
            p = cus_random()%32;
            q = cus_random()%32;
        }
        if(p > q)//add
        {
            (*Mat).M[p] ^= (*Mat).M[q];
            trail[i][0] = 1;
            trail[i][1] = p;
            trail[i][2] = q;
        }
        else//swap
        {
            temp = (*Mat).M[p];
            (*Mat).M[p] = (*Mat).M[q];
            (*Mat).M[q] = temp;
            trail[i][0] = 0;
            trail[i][1] = p;
            trail[i][2] = q;
        }   
    }
    for(int j = M32N - 1; j >= 0; j--)//generate inverse matrix
    {
        if(trail[j][0])//add
        {
            (*Mat_inv).M[trail[j][1]] ^= (*Mat_inv).M[trail[j][2]];
        }
        else//swap
        {
            temp = (*Mat_inv).M[trail[j][1]];
            (*Mat_inv).M[trail[j][1]] = (*Mat_inv).M[trail[j][2]];
            (*Mat_inv).M[trail[j][2]] = temp;
        }   
    }
    if(basetrailM32[0][0] != -1)
    {
        for(int j = initM32_times - 1; j >= 0; j--)//generate inverse matrix for base matrix
        {
            if(basetrailM32[j][0])//add
            {
                (*Mat_inv).M[basetrailM32[j][1]] ^= (*Mat_inv).M[basetrailM32[j][2]];
            }
            else//swap
            {
                temp = (*Mat_inv).M[basetrailM32[j][1]];
                (*Mat_inv).M[basetrailM32[j][1]] = (*Mat_inv).M[basetrailM32[j][2]];
                (*Mat_inv).M[basetrailM32[j][2]] = temp;
            }   
        }
    }
}
void initinvbaseM64(int N)//initial base matrix,  parameter: initM64_min ,  initM64_max
{
    int p, q;
    uint64_t temp;
    InitRandom((randseed++)^(unsigned int)time(NULL));
    if(basetrailM64[0][0] != -1) return ;
    initM64_times = N;
    for(int i = 0; i < initM64_times; i++)//generate reversible base matrix
    {
        p = cus_random()%64;
        q = cus_random()%64;
        while(p == q)
        {
            p = cus_random()%64;
            q = cus_random()%64;
        }
        if(p > q)//add
        {
            
            baseM64.M[p] ^= baseM64.M[q];
            basetrailM64[i][0] = 1;
            basetrailM64[i][1] = p;
            basetrailM64[i][2] = q;
        }
        else//swap
        {
            temp = baseM64.M[p];
            baseM64.M[p] = baseM64.M[q];
            baseM64.M[q] = temp;
            basetrailM64[i][0] = 0;
            basetrailM64[i][1] = p;
            basetrailM64[i][2] = q;
        }   
    }
}
void genMatpairM64(M64 *Mat, M64 *Mat_inv)//generate 64*64 reversible matrix and its inverse matrix
{
    int p, q;
    uint64_t temp;
    int trail[M64N][3];
    copyM64(baseM64, Mat);//copy base matrix
    identityM64(Mat_inv);
    InitRandom((randseed++)^(unsigned int)time(NULL));
    for(int i = 0; i < M64N; i++)//generate reversible matrix
    {
        p = cus_random()%64;
        q = cus_random()%64;
        while(p == q)
        {
            p = cus_random()%64;
            q = cus_random()%64;
        }
        if(p > q)//add
        {
            
            (*Mat).M[p] ^= (*Mat).M[q];
            trail[i][0] = 1;
            trail[i][1] = p;
            trail[i][2] = q;
        }
        else//swap
        {
            temp = (*Mat).M[p];
            (*Mat).M[p] = (*Mat).M[q];
            (*Mat).M[q] = temp;
            trail[i][0] = 0;
            trail[i][1] = p;
            trail[i][2] = q;
        }   
    }
    for(int j = M64N - 1; j >= 0; j--)//generate inverse matrix
    {
        if(trail[j][0])//add
        {
            (*Mat_inv).M[trail[j][1]] ^= (*Mat_inv).M[trail[j][2]];
        }
        else//swap
        {
            temp = (*Mat_inv).M[trail[j][1]];
            (*Mat_inv).M[trail[j][1]] = (*Mat_inv).M[trail[j][2]];
            (*Mat_inv).M[trail[j][2]] = temp;
        }   
    }
    if(basetrailM64[0][0] != -1)
    {
        for(int j = initM64_times - 1; j >= 0; j--)//generate inverse matrix for base matrix
        {
            if(basetrailM64[j][0])//add
            {
                (*Mat_inv).M[basetrailM64[j][1]] ^= (*Mat_inv).M[basetrailM64[j][2]];
            }
            else//swap
            {
                temp = (*Mat_inv).M[basetrailM64[j][1]];
                (*Mat_inv).M[basetrailM64[j][1]] = (*Mat_inv).M[basetrailM64[j][2]];
                (*Mat_inv).M[basetrailM64[j][2]] = temp;
            }   
        }
    }
}
void initinvbaseM128(int N)//initial base matrix,  parameter: initM128_min ,  initM128_max
{
    int p, q;
    uint64_t temp[2];
    InitRandom((randseed++)^(unsigned int)time(NULL));
    if(basetrailM128[0][0] != -1) return ;
    initM128_times = N;
    for(int i = 0; i < initM128_times; i++)//generate reversible base matrix
    {
        p = cus_random()%128;
        q = cus_random()%128;
        while(p == q)
        {
            p = cus_random()%128;
            q = cus_random()%128;
        }
        if(p > q)//add
        {
            
            baseM128.M[p][0] ^= baseM128.M[q][0];
            baseM128.M[p][1] ^= baseM128.M[q][1];
            basetrailM128[i][0] = 1;
            basetrailM128[i][1] = p;
            basetrailM128[i][2] = q;
        }
        else//swap
        {
            temp[0] = baseM128.M[p][0];
            temp[1] = baseM128.M[p][1];
            baseM128.M[p][0] = baseM128.M[q][0];
            baseM128.M[p][1] = baseM128.M[q][1];
            baseM128.M[q][0] = temp[0];
            baseM128.M[q][1] = temp[1];
            basetrailM128[i][0] = 0;
            basetrailM128[i][1] = p;
            basetrailM128[i][2] = q;
        }   
    }
}
void genMatpairM128(M128 *Mat, M128 *Mat_inv)//generate 128*128 reversible matrix and its inverse matrix
{
    int p, q;
    uint64_t temp[2];
    int trail[M128N][3];
    copyM128(baseM128, Mat);
    identityM128(Mat_inv);
    InitRandom((randseed++)^(unsigned int)time(NULL));
    for(int i = 0; i < M128N; i++)//generate reversible matrix
    {
        p = cus_random()%128;
        q = cus_random()%128;
        while(p == q)
        {
            p = cus_random()%128;
            q = cus_random()%128;
        }
        if(p > q)//add
        {
            (*Mat).M[p][0] ^= (*Mat).M[q][0];
            (*Mat).M[p][1] ^= (*Mat).M[q][1];
            trail[i][0] = 1;
            trail[i][1] = p;
            trail[i][2] = q;
        }
        else//swap
        {
            temp[0] = (*Mat).M[p][0];
            (*Mat).M[p][0] = (*Mat).M[q][0];
            (*Mat).M[q][0] = temp[0];
            temp[1] = (*Mat).M[p][1];
            (*Mat).M[p][1] = (*Mat).M[q][1];
            (*Mat).M[q][1] = temp[1];
            trail[i][0] = 0;
            trail[i][1] = p;
            trail[i][2] = q;
        }   
    }
    for(int j = M128N - 1; j >= 0; j--)//generate inverse matrix
    {
        if(trail[j][0])//add
        {
            (*Mat_inv).M[trail[j][1]][0] ^= (*Mat_inv).M[trail[j][2]][0];
            (*Mat_inv).M[trail[j][1]][1] ^= (*Mat_inv).M[trail[j][2]][1];
        }
        else//swap
        {
            temp[0] = (*Mat_inv).M[trail[j][1]][0];
            (*Mat_inv).M[trail[j][1]][0] = (*Mat_inv).M[trail[j][2]][0];
            (*Mat_inv).M[trail[j][2]][0] = temp[0];
            temp[1] = (*Mat_inv).M[trail[j][1]][1];
            (*Mat_inv).M[trail[j][1]][1] = (*Mat_inv).M[trail[j][2]][1];
            (*Mat_inv).M[trail[j][2]][1] = temp[1];
        }   
    }
    if(basetrailM128[0][0] != -1)
    {
        for(int j = initM128_times - 1; j >= 0; j--)//generate inverse matrix for base matrix
        {
            if(basetrailM128[j][0])//add
            {
                (*Mat_inv).M[basetrailM128[j][1]][0] ^= (*Mat_inv).M[basetrailM128[j][2]][0];
                (*Mat_inv).M[basetrailM128[j][1]][1] ^= (*Mat_inv).M[basetrailM128[j][2]][1];
            }
            else//swap
            {
                temp[0] = (*Mat_inv).M[basetrailM128[j][1]][0];
                (*Mat_inv).M[basetrailM128[j][1]][0] = (*Mat_inv).M[basetrailM128[j][2]][0];
                (*Mat_inv).M[basetrailM128[j][2]][0] = temp[0];
                temp[1] = (*Mat_inv).M[basetrailM128[j][1]][1];
                (*Mat_inv).M[basetrailM128[j][1]][1] = (*Mat_inv).M[basetrailM128[j][2]][1];
                (*Mat_inv).M[basetrailM128[j][2]][1] = temp[1];
            }   
        }
    }
}
void genaffinepairM8(Aff8 *aff, Aff8 *aff_inv)//generate a pair of affine
{
    genMatpairM8(&(aff->Mat), &(aff_inv->Mat));
    randV8(&(aff->Vec));
    MatMulVecM8((*aff_inv).Mat, (*aff).Vec, &(aff_inv->Vec));
}
void genaffinepairM16(Aff16 *aff, Aff16 *aff_inv)//generate a pair of affine
{
    genMatpairM16(&(aff->Mat), &(aff_inv->Mat));
    randV16(&(aff->Vec));
    MatMulVecM16((*aff_inv).Mat, (*aff).Vec, &(aff_inv->Vec));
}
void genaffinepairM32(Aff32 *aff, Aff32 *aff_inv)//generate a pair of affine
{
    genMatpairM32(&(aff->Mat), &(aff_inv->Mat));
    randV32(&(aff->Vec));
    MatMulVecM32((*aff_inv).Mat, (*aff).Vec, &(aff_inv->Vec));
}
void genaffinepairM64(Aff64 *aff, Aff64 *aff_inv)//generate a pair of affine
{
    genMatpairM64(&(aff->Mat), &(aff_inv->Mat));
    randV64(&(aff->Vec));
    MatMulVecM64((*aff_inv).Mat, (*aff).Vec, &(aff_inv->Vec));
}
void genaffinepairM128(Aff128 *aff, Aff128 *aff_inv)//generate a pair of affine
{
    genMatpairM128(&(aff->Mat), &(aff_inv->Mat));
    randV128(&(aff->Vec));
    MatMulVecM128((*aff_inv).Mat, (*aff).Vec, &(aff_inv->Vec));
}
void MatrixcomM8to32(M8 m1, M8 m2, M8 m3, M8 m4, M32 *mat)//diagonal matrix combine, four 8*8 -> 32*32
{
    int j = 0;
    uint8_t* m;
    initM32(mat);
    for(int i = 0; i<8; i++)
    {
        m = (uint8_t*)&(*mat).M[j];
        *(m+3) = m1.M[i];
        j++;
    }
    for(int i = 0; i < 8; i++)
    {
        m = (uint8_t*)&(*mat).M[j];
        *(m+2) = m2.M[i];
        j++;
    }
    for(int i = 0; i < 8; i++)
    {
        m = (uint8_t*)&(*mat).M[j];
        *(m+1) = m3.M[i];
        j++;
    }
    for(int i = 0; i < 8; i++)
    {
        m = (uint8_t*)&(*mat).M[j];
        *m = m4.M[i];
        j++;
    }
}
void VectorcomV8to32(V8 v1, V8 v2, V8 v3, V8 v4, V32 *vec)//four vectors combine
{
    uint8_t* v;
    v = (uint8_t*)&(*vec).V;
    *(v+3) = v1.V;
    *(v+2) = v2.V;
    *(v+1) = v3.V;
    *v = v4.V;
}
void affinecomM8to32(Aff8 aff1, Aff8 aff2, Aff8 aff3, Aff8 aff4, Aff32 *aff)//diagonal affine combine, four 8*8 -> 32*32
{
    MatrixcomM8to32(aff1.Mat, aff2.Mat, aff3.Mat, aff4.Mat, &(aff->Mat));
    VectorcomV8to32(aff1.Vec, aff2.Vec, aff3.Vec, aff4.Vec, &(aff->Vec));
}
void MattransM8(M8 Mat, M8 *Mat_trans)//matrix tansposition M8
{
    initM8(Mat_trans);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(Mat.M[i] & idM8[j]) (*Mat_trans).M[j] ^= idM8[i];
        }
    }
}
void MattransM16(M16 Mat, M16 *Mat_trans)//matrix tansposition M16
{
    initM16(Mat_trans);
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            if(Mat.M[i] & idM16[j]) (*Mat_trans).M[j] ^= idM16[i];
        }
    }
}
void MattransM32(M32 Mat, M32 *Mat_trans)//matrix tansposition M32
{
    initM32(Mat_trans);
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            if(Mat.M[i] & idM32[j]) (*Mat_trans).M[j] ^= idM32[i];
        }
    }
}
void MattransM64(M64 Mat, M64 *Mat_trans)//matrix tansposition M64
{
    initM64(Mat_trans);
    for(int i = 0; i < 64; i++)
    {
        for(int j = 0; j < 64; j++)
        {
            if(Mat.M[i] & idM64[j]) (*Mat_trans).M[j] ^= idM64[i];
        }
    }
}
void MattransM128(M128 Mat, M128 *Mat_trans)//matrix tansposition M128
{
    initM128(Mat_trans);
    for(int i = 0; i < 64; i++)
    {
        for(int j = 0; j < 64; j++)
        {
            if(Mat.M[i][0] & idM64[j]) (*Mat_trans).M[j][0] ^= idM64[i];
            if(Mat.M[i][1] & idM64[j]) (*Mat_trans).M[j+64][0] ^= idM64[i];
        }
    }
    for(int i = 64; i < 128; i++)
    {
        for(int j = 0; j < 64; j++)
        {
            if(Mat.M[i][0] & idM64[j]) (*Mat_trans).M[j][1] ^= idM64[i-64];
            if(Mat.M[i][1] & idM64[j]) (*Mat_trans).M[j+64][1] ^= idM64[i-64];
        }
    }
}
void MatAddMatM8(M8 Mat1, M8 Mat2, M8 *Mat)
{
    for(int i = 0; i < 8; i++)
    {
        (*Mat).M[i] = Mat1.M[i] ^ Mat2.M[i];
    }
}
void MatAddMatM16(M16 Mat1, M16 Mat2, M16 *Mat)
{
    for(int i = 0; i < 16; i++)
    {
        (*Mat).M[i] = Mat1.M[i] ^ Mat2.M[i];
    }
}
void MatAddMatM32(M32 Mat1, M32 Mat2, M32 *Mat)
{
    for(int i = 0; i < 32; i++)
    {
        (*Mat).M[i] = Mat1.M[i] ^ Mat2.M[i];
    }
}
void MatAddMatM64(M64 Mat1, M64 Mat2, M64 *Mat)
{
    for(int i = 0; i < 64; i++)
    {
        (*Mat).M[i] = Mat1.M[i] ^ Mat2.M[i];
    }
}
void MatAddMatM128(M128 Mat1, M128 Mat2, M128 *Mat)
{
    for(int i = 0; i < 128; i++)
    {
        (*Mat).M[i][0] = Mat1.M[i][0] ^ Mat2.M[i][0];
        (*Mat).M[i][1] = Mat1.M[i][1] ^ Mat2.M[i][1];
    }
}
void MatMulMatM8(M8 Mat1, M8 Mat2, M8 *Mat)//matrix multiplication 8*8 mul 8*8 -> 8*8
{
    M8 Mat2_trans;
    initM8(Mat);
    MattransM8(Mat2, &Mat2_trans);
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            if(xorU8(Mat1.M[i] & Mat2_trans.M[j])) (*Mat).M[i] ^= idM8[j];
        }       
    }
}
void MatMulMatM16(M16 Mat1, M16 Mat2, M16 *Mat)//matrix multiplication 16*16 mul 16*16 -> 16*16
{
    M16 Mat2_trans;
    initM16(Mat);
    MattransM16(Mat2, &Mat2_trans);
    for(int i = 0; i < 16; i++)
    {
        for(int j = 0; j < 16; j++)
        {
            if(xorU16(Mat1.M[i] & Mat2_trans.M[j])) (*Mat).M[i] ^= idM16[j];
        }       
    }
}
void MatMulMatM32(M32 Mat1, M32 Mat2, M32 *Mat)//matrix multiplication 32*32 mul 32*32 -> 32*32
{
    M32 Mat2_trans;
    initM32(Mat);
    MattransM32(Mat2, &Mat2_trans);
    for(int i = 0; i < 32; i++)
    {
        for(int j = 0; j < 32; j++)
        {
            if(xorU32(Mat1.M[i] & Mat2_trans.M[j])) (*Mat).M[i] ^= idM32[j];
        }       
    } 
}
void MatMulMatM64(M64 Mat1, M64 Mat2, M64 *Mat)//matrix multiplication 64*64 mul 64*64 -> 64*64
{
    M64 Mat2_trans;
    initM64(Mat);
    MattransM64(Mat2, &Mat2_trans);
    for(int i = 0; i < 64; i++)
    {
        for(int j = 0; j < 64; j++)
        {
            if(xorU64(Mat1.M[i] & Mat2_trans.M[j])) (*Mat).M[i] ^= idM64[j];
        }       
    } 
}
void MatMulMatM128(M128 Mat1, M128 Mat2, M128 *Mat)//matrix multiplication 128*128 mul 128*128 -> 128*128
{
    M128 Mat2_trans;
    uint64_t temp[2];
    initM128(Mat);
    MattransM128(Mat2, &Mat2_trans);
    for(int i = 0; i < 128; i++)
    {
        for(int j = 0; j < 64; j++)
        {
            temp[0] = Mat1.M[i][0] & Mat2_trans.M[j][0];
            temp[1] = Mat1.M[i][1] & Mat2_trans.M[j][1];
            if(xorU128(temp)) (*Mat).M[i][0] ^= idM64[j];
        }
        for(int j = 64; j < 128; j++)
        {
            temp[0] = Mat1.M[i][0] & Mat2_trans.M[j][0];
            temp[1] = Mat1.M[i][1] & Mat2_trans.M[j][1];
            if(xorU128(temp)) (*Mat).M[i][1] ^= idM64[j-64];
        }
    } 
}
void affinemixM8(Aff8 aff, Aff8 preaff_inv, Aff8 *mixaff)//mixed transformation of (previous affine inversion) and this round affine
{
    MatMulMatM8(aff.Mat, preaff_inv.Mat, &(mixaff->Mat));
    MatMulVecM8(aff.Mat, preaff_inv.Vec, &(mixaff->Vec));
    (*mixaff).Vec.V ^= aff.Vec.V;
}
void affinemixM16(Aff16 aff, Aff16 preaff_inv, Aff16 *mixaff)//mixed transformation of (previous affine inversion) and this round affine
{
    MatMulMatM16(aff.Mat, preaff_inv.Mat, &(mixaff->Mat));
    MatMulVecM16(aff.Mat, preaff_inv.Vec, &(mixaff->Vec));
    (*mixaff).Vec.V ^= aff.Vec.V;
}
void affinemixM32(Aff32 aff, Aff32 preaff_inv, Aff32 *mixaff)//mixed transformation of (previous affine inversion) and this round affine
{
    MatMulMatM32(aff.Mat, preaff_inv.Mat, &(mixaff->Mat));
    MatMulVecM32(aff.Mat, preaff_inv.Vec, &(mixaff->Vec));
    (*mixaff).Vec.V ^= aff.Vec.V;
}
void affinemixM64(Aff64 aff, Aff64 preaff_inv, Aff64 *mixaff)//mixed transformation of (previous affine inversion) and this round affine
{
    MatMulMatM64(aff.Mat, preaff_inv.Mat, &(mixaff->Mat));
    MatMulVecM64(aff.Mat, preaff_inv.Vec, &(mixaff->Vec));
    (*mixaff).Vec.V ^= aff.Vec.V;
}
void affinemixM128(Aff128 aff, Aff128 preaff_inv, Aff128 *mixaff)//mixed transformation of (previous affine inversion) and this round affine
{
    MatMulMatM128(aff.Mat, preaff_inv.Mat, &(mixaff->Mat));
    MatMulVecM128(aff.Mat, preaff_inv.Vec, &(mixaff->Vec));
    (*mixaff).Vec.V[0] ^= aff.Vec.V[0];
    (*mixaff).Vec.V[1] ^= aff.Vec.V[1];
}