
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>


//~ union floatbit {
 //~ float value;
 //~ struct {
 //~ uint32_t mant : 23;
 //~ uint32_t exp : 8;
 //~ uint32_t sign : 1;
 //~ } bit;
//~ } f;

//~ int extractExp(float a)
//~ {
	//~ uint32_t b=(uint32_t)a;
	//~ uint32_t Exp=0;
	//~ uint32_t mask = 0x40000000U;
	//~ while (mask!=0x200000)
	//~ {
		//~ if (mask&b)
		//~ {
			//~ Exp|=mask;
		//~ }
		//~ mask>>=1U;
	//~ }
	//~ return Exp>>=23U;
//~ }

int extractExp(float f)
{
	uint32_t b;
	memcpy(&b, &f, sizeof(f));
	//printf("b= %d\n", b);
	uint8_t Exp=b>>23;

	return Exp;
}

int main(int argc, char **argv)
{
	float f;
	scanf("%f" , &f );
	printf("%d", extractExp(f));
	return 0;
}

