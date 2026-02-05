


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>




int main(int argc, char **argv)
{
	uint32_t N;
	uint32_t K;
	uint32_t Result=0;
	scanf("%" SCNu32, &N );
	
	for (int i = 0; i < N; i++)
	{
		scanf("%" SCNu32, &K );
		Result^=K;
	}
	
	printf("%"PRIu8, Result);
	
	return 0;
}

