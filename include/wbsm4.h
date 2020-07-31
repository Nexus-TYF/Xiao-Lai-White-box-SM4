#include "WBMatrix/WBMatrix.h"
#include "sm4.h"
#define SM4_NUM_ROUNDS 32
//operational matrix
Aff32 P[SM4_NUM_ROUNDS + 4][2];
Aff8 E[SM4_NUM_ROUNDS + 4][4][2];
Aff32 EC[SM4_NUM_ROUNDS + 4][2];
Aff32 Q[SM4_NUM_ROUNDS + 4][2];

uint8_t skbox_enc[SM4_NUM_ROUNDS][4][256];

typedef struct Sm4Whitebox{
    //Affine
    Aff32 M[SM4_NUM_ROUNDS][3];
    Aff32 C[SM4_NUM_ROUNDS];
    Aff32 D[SM4_NUM_ROUNDS];

    Aff32 SE[4];
    Aff32 FE[4];

    //lookup table
    uint32_t Table[SM4_NUM_ROUNDS][4][256];
}Sm4Whitebox;

void printstate(unsigned char * in);
void sm4_wb_gen_secrect_sbox(sm4_context *sm4_key);
void sm4_wb_gen_affine(Sm4Whitebox* sm4_wb_ctx);
void sm4_wb_combine_tables(Sm4Whitebox* sm4_wb_ctx);
void sm4_wb_gen_tables(uint8_t *key, Sm4Whitebox *sm4_wb_ctx);
void sm4_wb_enc(unsigned char IN[], unsigned char OUT[], Sm4Whitebox *sm4_wb_ctx);