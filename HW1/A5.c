
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>



int Quantity_ofBits(uint32_t N)
{
	
	int count=0;
	while (N)
	{
		if (N&0x1)
		{
			count++;
		}
		N>>=1U;
	}
	return count;
}


int main(int argc, char **argv)
{
	uint32_t N;
	scanf("%" SCNu32, &N );
	uint32_t Result=Quantity_ofBits(N);
	printf("%"PRIu8, Result);
	return 0;
}

