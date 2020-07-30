#ifndef _HWBMATRIX_H_
#define _HWBMATRIX_H_
/***
 * Last Update:2020/07/01
 * Version:2.2.1
***/
#include "WBMatrix/structure.h"
#include "WBMatrix/inverse.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "WBMatrix/random.h"

void SetRandSeed(unsigned int seed);//Set random seed

/*
* 8bit Matrix operation
*/
void initM8(M8 *Mat);
void randM8(M8 *Mat);
void identityM8(M8 *Mat);
void printM8(M8 Mat);
void printbitM8(M8 Mat);
void copyM8(M8 Mat1, M8 *Mat2);
int isequalM8(M8 Mat1, M8 Mat2);
int isinvertM8(M8 Mat);

void initV8(V8 *Vec);
void randV8(V8 *Vec);
void printV8(V8 Vec);
int isequalV8(V8 Vec1, V8 Vec2);
void VecAddVecV8(V8 Vec1, V8 Vec2, V8 *Vec);

uint8_t affineU8(Aff8 aff,uint8_t arr);
int xorU8(uint8_t n);
int HWU8(uint8_t n);
void printU8(uint8_t n);

void MatMulVecM8(M8 Mat,V8 Vec, V8 *ans);
uint8_t MatMulNumM8(M8 Mat, uint8_t n);
void MatMulMatM8(M8 Mat1, M8 Mat2, M8 *Mat);
void MatAddMatM8(M8 Mat1, M8 Mat2, M8 *Mat);
void MattransM8(M8 Mat, M8 *Mat_trans);
void initinvbaseM8(int N);
void freebaseM8();

void genMatpairM8(M8 *Mat, M8 *Mat_inv);
void genaffinepairM8(Aff8 *aff, Aff8 *aff_inv);
void affinemixM8(Aff8 aff, Aff8 preaff_inv, Aff8 *mixaff);
/*
* 16bit Matrix operation
*/
void initM16(M16 *Mat);
void randM16(M16 *Mat);
void identityM16(M16 *Mat);
void printM16(M16 Mat);
void printbitM16(M16 Mat);
void copyM16(M16 Mat1, M16 *Mat2);
int isequalM16(M16 Mat1, M16 Mat2);
int isinvertM16(M16 Mat);

void initV16(V16 *Vec);
void randV16(V16 *Vec);
void printV16(V16 Vec);
int isequalV16(V16 Vec1, V16 Vec2);
void VecAddVecV16(V16 Vec1, V16 Vec2, V16 *Vec);

uint16_t affineU16(Aff16 aff, uint16_t arr);
int xorU16(uint16_t n);
int HWU16(uint16_t n);
void printU16(uint16_t n);
void MatAddMatM16(M16 Mat1, M16 Mat2, M16 *Mat);
void MatMulVecM16(M16 Mat, V16 Vec, V16 *ans);
uint16_t MatMulNumM16(M16 Mat, uint16_t n);
void MatMulMatM16(M16 Mat1, M16 Mat2, M16 *Mat);

void MattransM16(M16 Mat, M16 *Mat_trans);
void initinvbaseM16(int N);
void freebaseM16();

void genMatpairM16(M16 *Mat, M16 *Mat_inv);
void genaffinepairM16(Aff16 *aff, Aff16 *aff_inv);
void affinemixM16(Aff16 aff, Aff16 preaff_inv, Aff16 *mixaff);
/*
* 32bit Matrix operation
*/
void initM32(M32 *Mat);
void randM32(M32 *Mat);
void identityM32(M32 *Mat);
void printM32(M32 Mat);
void printbitM32(M32 Mat);
void copyM32(M32 Mat1, M32 *Mat2);
int isequalM32(M32 Mat1, M32 Mat2);
int isinvertM32(M32 Mat);

void initV32(V32 *Vec);
void randV32(V32 *Vec);
void printV32(V32 Vec);
int isequalV32(V32 Vec1, V32 Vec2);
void VecAddVecV32(V32 Vec1, V32 Vec2, V32 *Vec);

uint32_t affineU32(Aff32 aff, uint32_t arr);
int xorU32(uint32_t n);
int HWU32(uint32_t n);
void printU32(uint32_t n);

void MatMulVecM32(M32 Mat, V32 Vec, V32 *ans);
uint32_t MatMulNumM32(M32 Mat, uint32_t n);
void MatMulMatM32(M32 Mat1, M32 Mat2, M32 *Mat);
void MatAddMatM32(M32 Mat1, M32 Mat2, M32 *Mat);
void MattransM32(M32 Mat, M32 *Mat_trans);
void initinvbaseM32(int N);
void freebaseM32();

void genMatpairM32(M32 *Mat, M32 *Mat_inv);
void genaffinepairM32(Aff32 *aff, Aff32 *aff_inv);
void affinemixM32(Aff32 aff, Aff32 preaff_inv, Aff32 *mixaff);
void MatrixcomM8to32(M8 m1, M8 m2, M8 m3, M8 m4, M32 *mat);
void VectorcomV8to32(V8 v1, V8 v2, V8 v3, V8 v4, V32 *vec);
void affinecomM8to32(Aff8 aff1, Aff8 aff2, Aff8 aff3, Aff8 aff4, Aff32 *aff);
/*
* 64bit Matrix operation
*/
void initM64(M64 *Mat);
void randM64(M64 *Mat);
void identityM64(M64 *Mat);
void printM64(M64 Mat);
void printbitM64(M64 Mat);
void copyM64(M64 Mat1, M64 *Mat2);
int isequalM64(M64 Mat1, M64 Mat2);
int isinvertM64(M64 Mat);

void initV64(V64 *Vec);
void randV64(V64 *Vec);
void printV64(V64 Vec);
int isequalV64(V64 Vec1, V64 Vec2);
void VecAddVecV64(V64 Vec1, V64 Vec2, V64 *Vec);

uint64_t affineU64(Aff64 aff, uint64_t arr);
int xorU64(uint64_t n);
int HWU64(uint64_t n);
void printU64(uint64_t n);

void MatMulVecM64(M64 Mat, V64 Vec, V64 *ans);
uint64_t MatMulNumM64(M64 Mat, uint64_t n);
void MatMulMatM64(M64 Mat1, M64 Mat2, M64 *Mat);

void MattransM64(M64 Mat, M64 *Mat_trans);
void initinvbaseM64(int N);
void freebaseM64();

void MatAddMatM64(M64 Mat1, M64 Mat2, M64 *Mat);
void genMatpairM64(M64 *Mat, M64 *Mat_inv);
void genaffinepairM64(Aff64 *aff, Aff64 *aff_inv);
void affinemixM64(Aff64 aff, Aff64 preaff_inv, Aff64 *mixaff);
/*
* 128bit Matrix operation
*/
void initM128(M128 *Mat);
void randM128(M128 *Mat);
void identityM128(M128 *Mat);
void printM128(M128 Mat);
void printbitM128(M128 Mat);
void copyM128(M128 Mat1, M128 *Mat2);
int isequalM128(M128 Mat1, M128 Mat2);
int isinvertM128(M128 Mat);

void initV128(V128 *Vec);
void randV128(V128 *Vec);
void printV128(V128 Vec);

void affineU128(Aff128 aff, uint64_t arr[], uint64_t ans[]);
int xorU128(uint64_t n[]);
int HWU128(uint64_t n[]);
void printU128(uint64_t n[]);
int isequalV128(V128 Vec1, V128 Vec2);
void VecAddVecV128(V128 Vec1, V128 Vec2, V128 *Vec);

void MatMulVecM128(M128 Mat, V128 Vec, V128 *ans);
//void MatMulNumM128(M128 Mat, uint64_t n[], uint64_t ans[]);
void MatMulMatM128(M128 Mat1, M128 Mat2, M128 *Mat);

void MattransM128(M128 Mat, M128 *Mat_trans);
void initinvbaseM128(int N);
void freebaseM128();

void MatAddMatM128(M128 Mat1, M128 Mat2, M128 *Mat);
void genMatpairM128(M128 *Mat, M128 *Mat_inv);
void genaffinepairM128(Aff128 *aff, Aff128 *aff_inv);
void affinemixM128(Aff128 aff, Aff128 preaff_inv, Aff128 *mixaff);

#endif