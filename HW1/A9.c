
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <stdlib.h> 

struct pack_array {
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
};

void array2struct(int array[], struct pack_array * a)
{
	uint32_t mask = 0x80000000U;
	uint32_t count1_=0;
	uint32_t count0_=0;
	int i=0;
	uint32_t DecimalSum=0;
	while (mask)
	{
		if (array[i]==1)
		{
			count1_++;
			DecimalSum |= ((uint32_t)1 << (31 - i));
		}
		else
		{
			count0_++;
		}
		i++;
		mask>>=1U;
	}
	a->array=DecimalSum;
	a->count0=count0_;
	a->count1=count1_;
}

int main(int argc, char **argv)
{
	struct pack_array * a = malloc(sizeof(struct pack_array));
	int array[32]={0};
	for (int i = 0; i < 32; i++)
	{
		scanf("%d" , &array[i] );
	
	}
	array2struct(array, a);
	
printf("%" PRIu32, a->array);
printf(" %u %u", a->count0, a->count1);
	
	return 0;
}

