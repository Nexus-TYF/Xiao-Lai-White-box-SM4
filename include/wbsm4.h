#include "WBMatrix/WBMatrix.h"
#include "sm4.h"
#define SM4_ROUNDS 32

Aff32 M[SM4_ROUNDS][3];
Aff32 C[SM4_ROUNDS];
Aff32 D[SM4_ROUNDS];

Aff32 SE[4];
Aff32 FE[4];

uint32_t Table[SM4_ROUNDS][4][256];

void printstate(unsigned char * in);
void wbsm4_gen(uint8_t *key);
void wbsm4_encrypt(unsigned char IN[], unsigned char OUT[]);