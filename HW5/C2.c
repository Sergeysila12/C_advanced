#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <string.h>

#define MAX_STACK_SIZE 255
#define false 0
#define true 1

typedef int datatype;

datatype st[MAX_STACK_SIZE]; //массив - стек


volatile int pst=0; // заполненность стека



void push(datatype v){
// используется для вычислений
 if(pst>MAX_STACK_SIZE) {
 fprintf(stderr,"Error.Stack overflow");
 return ;
 }
 st[pst++]=v;
}

 datatype pop()
{
	if(pst<=0) 
		{
			fprintf(stderr, "Error. Stack underflow");
			return 1;
		}
	else if(pst>=MAX_STACK_SIZE)
	 {
        fprintf(stderr, "Error. Stack overflow");
        return 1;
	}
	return st[--pst];
}



void operate(char c){ // вычисляем два верхних значения на стеке st
	
	//printf("c=%c\n", c);
	datatype arg1=pop();
	//printf("pst =%d arg2=%d\n", pst, arg2);
	datatype arg2=pop();
	//printf("pst =%d arg1=%d\n", pst, arg1);
	if (c=='+') push(arg2+arg1);
	else if (c=='-') push(arg2-arg1);
	else if (c=='*') push(arg2*arg1);
	else if (c=='/') push(arg2/arg1);
}


_Bool isDigit(char c) // проверяем является ли символ цифрой
{
    return ((c>='0')&&(c<='9'));
}

_Bool isOperator(char c) {
    return c=='+' ||  c=='-' ||  c=='*' || c=='/';
}


int main(int argc, char **argv)
{
	
int i=0;
//int ret;
	
//datatype number; // double описан в stack.c
char s[MAX_STACK_SIZE]={0};
//scanf("%s", s);
//int n = strlen(s);
 if (fgets(s, sizeof(s), stdin) == NULL) return 1;
 
    while (s[i] != '\0' && s[i] != '\n'&&s[i]!='.') {
        
        if (s[i] == ' ') { i++; continue; }
        
        if (isDigit(s[i])) {
            datatype num = 0;
            // Поддержка многозначных чисел
            while (isDigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            push(num);
            continue;  // i уже на следующей позиции
        }
        else if (isOperator(s[i])) {
            operate(s[i]);
        }
        i++;
    }

	//printf("pst =%d\n", pst);
	printf("%d\n",pop());
	return 0;
}

