


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t dump_ofBits (uint32_t n, uint8_t k)
{
	uint32_t mask=0xFFFFFFFFu;
	//mask^=1;
	mask>>=(32-k);
	//printf("mask=%d ", mask);
	return n&mask;
}

int main(int argc, char **argv)
{
	uint32_t N;
	uint8_t K;
	
	scanf("%" SCNu32, &N );
	scanf("%" SCNu8, &K );
	uint32_t Result=dump_ofBits(N, K);
	
	printf("%"PRIu8, Result);
	
	return 0;
}

