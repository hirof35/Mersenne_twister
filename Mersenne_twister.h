#ifndef __Mersenne_twister_H__
#define __Mersenne_twister_H__
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#define N 64
#define M 397
#define A 0x9908B0DF
#define U 11
#define D 0x9D2C5680
#define S 7
#define B 0x9D2C5680
#define T 15
#define C 0xEFC60000
#define L 18
#define F 1812433253
#define W 32
#define R 31
extern uint32_t mt[N];
extern int index;
void twist(void);
uint32_t extract_number(void);
void init_by_seed(uint32_t);
#endif // !__Mersenne_twister_H__
