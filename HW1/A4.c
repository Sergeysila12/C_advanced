
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>


uint32_t MaxOrder_ofBits(uint32_t n, uint8_t k)
{
//	uint32_t mask = 0;
	uint32_t resultTemp=0;
	int bit_index=0;
	uint32_t result=0;
	while (bit_index!=33-k)
	{
		resultTemp=(n>>bit_index)&((1U<<k)-1);
		if (resultTemp>result)result=resultTemp;
		bit_index++;
	}
	
	return result;
}

/*
uint32_t MaxOrder_ofBits(uint32_t n, uint8_t k)
{
	uint32_t result=0;
	uint32_t resultTemp=0;
	int bit_index=31;
	//uint32_t mask = 0x80000000U;
	uint32_t maskTemp = 0xFFFFFFFFu;
	//int i=32-k+1;
	do 
	{
		maskTemp>>=(31-bit_index);
		maskTemp-=(uint32_t)((1U<<(bit_index+1-k))-1U);
		
		resultTemp=maskTemp&n;
		resultTemp>>=bit_index-k;
		printf("resultTemp=%u bit_index=%u result=%u maskTemp=%u \n",resultTemp,bit_index,result,maskTemp );
		if (resultTemp>result)result=resultTemp;
		//printf("mask= %d bit_index=%d \n",  mask, bit_index);
		//mask>>=1U;
		//n>>=1U;
		bit_index--;
		maskTemp = 0xFFFFFFFFu;
		//i--;
	}
	while(bit_index-k>-1);
	return result;
}

*/
/*
	//printf("mask_bit= %d bit_index=%d result=%d \n",  mask, bit_index,result);
	if(bit_index-k>=0)//&&result<=(n>>(bit_index-k)))
		{
				
			result=n>>k;
			printf("mask_bit= %d bit_index=%d result=%d \n",  mask, bit_index,result);
			//printf("result=%d \n",  result);
		}
		//else if (mask==1&&!result) result=1;
		//else if (bit_index==k&&result>0)return result;
		else if (bit_index<k&&result>0)return result;
		//else if (bit_index==k&&result==0)return n;
		else if (bit_index<k&&result==0)return n;
			
			
			//else if () return n>>bit_index;		
			//break;
					
uint32_t 1MaxOrder_ofBits(uint32_t n, uint8_t k)
{
	//uint32_t result=0;
	int bit_index=32;
	uint32_t mask = 0x80000000U;
	while (bit_index)
	{
		if(n&mask)
		{
			//printf("mask_bit= %d bit_index=%d\n",  mask, bit_index );
			if(bit_index-k>0)n>>=(bit_index-k);		
			break;
		}
		//printf("mask= %d bit_index=%d \n",  mask, bit_index);
		mask>>=1U;
		bit_index--;
		
	}
	
	return n;
}

*/



int main(int argc, char **argv)
{
	
	uint32_t N;
	uint8_t K;
	scanf("%" SCNu32, &N );
	scanf("%" SCNu8, &K );
	uint32_t Result=MaxOrder_ofBits(N, K);
	printf("%"PRIu8, Result);
	return 0;
}

