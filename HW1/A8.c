
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdbool.h>




int main(int argc, char **argv)
{
	uint32_t N;
	uint32_t Result=0;
	//uint32_t weight=1;
	uint32_t count=0;
	scanf("%" SCNu32, &N );
	if (N > 1000000) {
    printf("-1");
    return 0;
}
	while (N!=0)
	{
		Result=N%3;
		switch (Result)
		{
			case 0:
				N/=3;
				break;
			case 1:
				N/=3;
				count++;
				break;
			case 2:
				N=(N/3)+1;
				count++;
				break;
			default:
				break;
		}
		
	}
	printf("%"PRIu32, count);
	return 0;
}

	
	/*
	while (N<0xFF000000)
	{
		if (!(N%3)||N==1)
		{
			count++;
			printf("%"PRIu32, count);
			return 0;
		}
		else
		{
			N+=Quantity;
		}
		Quantity*=3;
		count++;
	}
	printf("%"PRIu8, 1);
	*/
	
	
	//~ typedef struct data 
//~ {
	//~ uint32_t count=1;
	//~ uint32_t weight=1;
	//~ //uint32_t TotalWeight=0;
//~ }data;



//~ int Weigh( uint32_t weight, uint32_t N, uint32_t count)
//~ {
	
	//~ while (N>0)
	//~ {
		//~ N-=weight;
		//~ count++;
		//~ if (!N)
		//~ {
			//~ printf("%"PRIu8, count);
			//~ return 1;
		//~ }
		//~ weight*=3;
	//~ }
	//~ return 0;
//~ }


	//~ while (count<30)
	//~ {
		//~ if (Weigh(weight,N,count))
		//~ {
			//~ return 0;
		//~ }
		//~ else
		//~ {
			//~ N+=weight;
			//~ count++;
		//~ }
		//~ weight*=3;
	//~ }
	//~ printf("%d", 1);
