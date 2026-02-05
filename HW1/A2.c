

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int rightRotate(uint32_t n, uint8_t k)
{
	return (n >> k)|(n << (32 - k));
}



int main(int argc, char **argv)
{
	uint32_t N;
	uint8_t K;
	
	scanf("%" SCNu32, &N );
	scanf("%" SCNu8, &K );
	uint32_t Result=rightRotate(N, K);
	printf("%"PRIu32, Result);
	return 0;
}

