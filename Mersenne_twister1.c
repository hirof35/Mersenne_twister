#include"Mersenne_twister.h"
uint32_t mt[N];
int index = N + 1;
void twist(void) {
	for (int i = 0; i < N; i++) {
		uint32_t x = (mt[i] & 0x80000000) + (mt[(i + 1) % N] & 0x7FFFFFFF);
		mt[i] = mt[(i + M) % N] ^ (x >> 1);
		if (x % 2 != 0) {
			mt[i] ^= A;
		}
	}
	index = 0;
}
uint32_t extract_number(void) {
	if (index >= N) {
		if (index > N) {
			printf("Generator was not speed");
			exit(1);
		}
		twist();
	}
	uint32_t y = mt[index];
	y ^= (y >> U) & D;
	y ^= (y << S) & B;
	y ^= (y << T) & C;
	y ^= y >> L;
	index++;
	return y;
}
void init_by_seed(uint32_t seed) {
	mt[0] = seed;
	for (int i = 1; i < N; i++) {
		mt[i] = (F * (mt[i - 1] ^ (mt[i - 1] >> (W - 2))) + i);
	}
	index = N; // indexをNに設定することで、最初のextract_number()呼び出しでtwist()が実行される
}
