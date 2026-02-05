
#include <stdio.h>


void input ()
{
	int length;
	int max;
	
	int count=0;
	int i=0;
	scanf ("%d", &length);
	
	for (; i < length; i++)
	{
		int num;
		scanf ("%d", &num);
		if (i==0)
		{
			max=num;
			count=1;
		}
		else
		{
			if(max<=num)
			{
				if(max== num)count++;
				else
				{
					max=num;
					count=1;
				}
			}
			
		}
	}

printf("%d\n",  count);
}

int main(int argc, char **argv)
{
	input ();
	return 0;
}

