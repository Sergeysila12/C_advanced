#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>





int main(int argc, char **argv)
{
	
	char N[100];
	scanf("%s", N );
	int length_N = strlen(N); 
	int digits[100];
    for (int i = 0; i < length_N; i++) {
        digits[i] = N[i] - '0';
    }
	
	//free(N);
	int z=0;
	int ArrayResult[1000]={0};
	
	for (int i = 0; i < length_N; i++)
	{
		if (digits[i] == 0) continue;
		for (int j = i+1; j < length_N; j++)
		{
			for (int k = j+1; k < length_N; k++)
			{
				z=digits[i]*100+digits[j]*10+digits[k];
				ArrayResult[z]=1;
			}
		}
	}
	

    int count = 0;
    for (int i = 100; i <= 999; i++) {
        if (ArrayResult[i]) count++;
    }
    
    printf("%d\n", count);
	

	return 0;
}

