

#ifndef MY_HEADER
#define MY_HEADER

#include <stdio.h>


typedef double (*func_t)(double);


float root(float xl, float xr, float eps, func_t f, func_t g, int* quantity );


float integral( func_t f, float xl, float xr, size_t n );


void test();



double f(double x);

double g (double x);

double z(double x);

double h(func_t f, func_t g, double x);

int sign(float x);


#endif
