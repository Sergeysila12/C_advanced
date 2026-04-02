

#include "Numerical_methods.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>



float root(float xl, float xr, float eps, func_t f, func_t g, int* quantity ) 
{
 int stepcount=0; //число шагов
 float xm;

 while(fabs(xr-xl)>eps) { //вещественный модуль разницы или floatabs
 stepcount++;
 xm=(xl+xr)/2; // середина отрезка
 if(sign(h(f,g, xl)) != sign(h(f,g, xm))) //если знак отличается
 xr=xm;
 else
 xl=xm;
 }

 *quantity=stepcount;

 return (xl+xr)/2;
}



float integral( func_t f, float xl, float xr, size_t n ) 
{
    float sum = 0;
    float h = (xr-xl)/n;
    for(size_t i = 0; i < n; i++) 
    {
        float x = xl + i * h;
        sum += 0.5 * h * (f(x) + f(x + h));
    }
    return sum;
}





void test() {
	
    printf("\n=== Testing the functions ===\n");
    
    int quantity = 0;
    double eps = 0.001;
    
 
   printf("\n=== f(x) = 0.6x + 3, g(x) = (x-2)^3 - 1, z(x) = 3/x; ===\n");

   printf("\n=== TEST 1: Root of function  f(x) , g(x)  on the segment [2, 4]; === \n");

   double x_root = root(2.0,  4.0, eps, f, g, &quantity );
   
   
   printf("Root of F=f(x)-g(x) on [%.1f, %.1f]: %.2f\n",2.0,4.0, x_root); 
   printf("Quantity of iterations of F=f(x)-g(x) : %d\n",quantity); 
    
   printf("\n=== TEST 2: integral(0.6x + 3)dx on the segment [ 0, 2]; === \n");
   double result = integral(f, 0.0, 2.0, 1000); 
   printf("Define integral of f(x) on [%.1f, %.1f]: %.3f\n", 0.0, 2.0, result);

}







double f(double x)
{
	return 0.6*x+3;
}

double g (double x)
{
	return ((x-2)*(x-2)*(x-2))-1;
}

double z(double x)
{
	return 3/x;
}

double h(func_t f, func_t g, double x) {
    return f(x) - g(x);
}




int sign(float x){
     if (x > 0)
        return 1;
    else if (x < 0)
        return -1;
    else
        return 0;
}






