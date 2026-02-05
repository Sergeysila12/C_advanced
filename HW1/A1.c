


#include <stdio.h>



void conversion(char s, int N)
{
	char OutSimbol;
	if(s>=0x41&&s<=0x5A)
	{
		OutSimbol=(s-'A'+N)%26;
		OutSimbol+='A';
		//~ OutSimbol=(s+N);
		//~ if (OutSimbol>0x5A)
		//~ {
			//~ OutSimbol%=0x5A+0x40;
			//~ //OutSimbol+=0x40;
		//~ }
	}
	else if(s>=0x61&&s<=0x7A)
	{
		OutSimbol=(s-'a'+N)%26;
		OutSimbol+='a';
		//~ OutSimbol=(s+N);
		//~ if (OutSimbol>0x7A)
		//~ {
			//~ OutSimbol%=0x7A+ 0x60;
			//~ //OutSimbol+=0x60;
		//~ }
	}
	else
	{
		OutSimbol=s;
	}
	printf("%c",  (char)OutSimbol);
}


int main(int argc, char **argv)
{
	char simbol;
	int N;
	scanf ("%d", &N);
	do
	{
		scanf ("%c", &simbol);
		conversion(simbol,N);
	}
	while(simbol!='.');
	
	return 0;
}

