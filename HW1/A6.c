
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

uint32_t Reverse_ofBits(uint32_t N)
{
	uint32_t mask = 0x80000000U;
	while (mask!=0x800000)
	{
		N^=mask;
		mask>>=1U;
	}
	return N;
}

int main(int argc, char **argv)
{
	uint32_t N;
	scanf("%" SCNu32, &N );
	uint32_t Result=Reverse_ofBits(N);
	printf("%"PRIu8, Result);
	
	return 0;
}

