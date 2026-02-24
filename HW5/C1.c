

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>


#define SIZE 10000
#define min(a, b) ((a) < (b) ? (a) : (b))


/*

void z_preprocess(int Z[], char *str)
{
        const size_t len = strlen(str);
        if (0 == len)
                return;

        Z[0] = len;

        for (size_t curr = 1, left = 0, right = 1; curr < len; ++curr)
        {
                if (curr >= right)
                {
                        size_t off = 0;
                        while ( curr + off < len && str[curr + off] == str[off] )
                                ++off;
                        Z[curr] = off;
                        right = curr + Z[curr];
                        left = curr;
                }
                else
                {
                        const size_t equiv = curr - left;
                        if (Z[equiv] < right - curr)
                                Z[curr] = Z[equiv];
                        else
                        {
                                size_t off = 0;
                                while ( right + off < len && str[right - curr + off] == str[right + off] )
                                        ++off;
                                Z[curr] = right - curr + off;
                                right += off;
                                left = curr;
                        }
                }
        }
}

	//~ size_t tlen = strlen(t);
	//~ size_t plen = strlen(p);
	
	int first=zFunction2 (s, z);
	//s={0};
	sprintf(s, "%s#%s", t, p);
	int second=zFunction2 (s,  z);
	
	printf(	"%d %d", first, second);


	//~ for (i = 0; i < n; i++)
	//~ {
		//~ printf(	"z[i]=%d\n", z[i]);
	//~ }



int zFunction2 (char *s, int z[]) {
	int n = strlen(s);
	for (int i=1, l=0, r=0; i<n; ++i) 
	{
		if (i <= r)z[i] = min (r-i+1, z[i-l]);
		
		while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
		if (i+z[i]-1 > r)
			l = i, r = i+z[i]-1;
	}
	int suffix=z[n-1];
	return suffix;
}

*/

int zFunction (char *s, int z[])
{
	z[0]=0; 
	int j=0, i=1;
	int n = strlen(s);
	//printf(	"n=%d\n", n);
	while (i<n)
	{
		if (s[i]!=s[j])
		{
			if (j==0)
			{
				z[i]=0;
				i++;
				//printf(	"s[i]=%c\n", s[i]);
			}
			else if(j>0) 
			{
				j=z[j-1];
			}
		}
		else if(s[i]==s[j])
		{
			z[i]=j+1;
			i++;
			j++;
		}
			
	}
	return z[n-1];
}



int main(int argc, char **argv)
{
	int z[SIZE+SIZE] = {0};
	int y[SIZE+SIZE] = {0};
	char t[SIZE]={0};
	char s[SIZE+SIZE]={0};
	char s1[SIZE+SIZE]={0};
	
	char p[SIZE]={0};
	scanf("%s", p);
	scanf("%s", t );
	
	sprintf(s, "%s#%s", p, t);
	sprintf(s1, "%s#%s", t, p);
	
	printf("%d %d", zFunction (s, z), zFunction (s1, y));
	
	return 0;
}

