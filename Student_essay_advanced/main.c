
#include "Numerical_methods.h"
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <stdlib.h>




void print_help(const char *prog_name) {
	
printf("Usage: %s [OPTIONS]\n", prog_name);
printf("Options:\n");
printf("  -r       print x-coordinates of intersection points\n");
printf("  -c       print number of iterations for root finding\n");
printf("  -i       compute definite integral\n");
printf("  -t       test functions\n");
printf("  -e <value>   computation accuracy (default: 0.001)\n");
printf("  -h       show this help message\n");
    

}



int main(int argc, char **argv)
{

	float eps=0.001;
	int flag_root=0; int flag_count=0; int flag_integral=0; int flag_test=0;

	int options=0;
	 while ( (options = getopt(argc,argv,"rcite:h")) != -1)
    {
		
        switch (options)
        {
            case 'h': 
            print_help(argv[0]);
            return 0;
            case 'e': 
            printf("found argument %s\n",optarg);
            eps=atof(optarg);
            
            case 'r': flag_root=1; break;
            
            case 'c': flag_count=1;  break;
            
			case 'i': flag_integral = 1;  break;
			
            case 't': flag_test = 1; break;
            
            default: printf("command is not existed \n");  return 1;
        }
     
    }
   
   
    if (!flag_root && !flag_count && !flag_integral && !flag_test) 
    {
        printf("command is not found\n");
        return 0;
    }
    
    
      if (flag_test)test();
       
  //  float intsect_f_z=0, intsect_z_g=0, intsect_g_f=0;
    if (flag_root||flag_count)
	{
		//float xl=0;
	     // float xr=2;
		int quantity = 0;
		 float x_root=root(-6.0,  -5.0, eps, z, f, &quantity );
		 
		 if (flag_root)printf("Root of F=z(x)-f(x) on [%.1f, %.1f]: %.2f\n",-6.0,-5.0, x_root); 
		 if(flag_count)printf("Quantity of iterations of F=z(x)-f(x) : %d\n",quantity);
		 quantity = 0;
		 x_root=root(0.5,  1.0, eps, z, f, &quantity );
		// intsect_f_z=x_root;
		 if (flag_root)printf("Root of F=z(x)-f(x) on [%.1f, %.1f]: %.2f\n",0.5, 1.0, x_root); 
		 if(flag_count)printf("Quantity of iterations of F=z(x)-f(x) : %d\n",quantity);
		
		quantity = 0;
		 x_root=root(-1.0,  0, eps, z, g, &quantity );
		 if (flag_root)printf("Root of F=z(x)-g(x) on [%.1f, %.1f]: %.2f\n",-1.0, 0.0, x_root); 
		 if(flag_count)printf("Quantity of iterations of F=z(x)-g(x) : %d\n",quantity);
		 
		quantity = 0;
		 x_root=root(2.0,  4.0, eps, z, g, &quantity );
		// intsect_z_g=x_root;
		 if (flag_root)printf("Root of F=z(x)-g(x) on [%.1f, %.1f]: %.2f\n",2.0, 4.0, x_root); 
		 if(flag_count)printf("Quantity of iterations of F=z(x)-g(x) : %d\n",quantity);
		 
		 
		 quantity = 0;
		 x_root=root(2.5,  4.0, eps, g, f, &quantity );
		// intsect_g_f=x_root;
		 if (flag_root)printf("Root of F=g(x)-f(x) on [%.1f, %.1f]: %.2f\n",2.5, 4.0, x_root); 
		 if(flag_count)printf("Quantity of iterations of F=g(x)-f(x) : %d\n",quantity);
		
	}
   
       if (flag_integral)
        {
			int n= 1/eps;
		
			float xl=0.85;
	
	        float xr=3.85;
			double result_f = integral(f, xl, xr, n);
			printf("Define integral of f(x) on [%.1f, %.1f]: %.3f\n", xl, xr, result_f);
		
			xr=3.24;
			double result_z = integral(z, xl, xr, n);
			printf("Define integral of z(x) on [%.1f, %.1f]: %.3f\n", xl, xr, result_z);
			xl=3.24;
			xr=3.85;
			double result_g = integral(g, xl, xr, n);
			printf("Define integral of g(x) on [%.1f, %.1f]: %.3f\n", xl, xr, result_g);

			double result=result_f-result_z-result_g;
			
			printf("The area: %.2f\n",  result);

        }
    
	return 0;
}

