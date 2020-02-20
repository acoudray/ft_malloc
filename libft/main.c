#include <stdio.h>
#include "includes/ft_printf.h"
#include <float.h>
#include <limits.h>

int main(void)
{
	int w;
	int y;


	printf("---------Partie double---------\n\n");
	y = printf("printf = %f\n", DBL_MAX - 2);
	w = ft_printf("ft_print = %f\n",  DBL_MAX - 2);
	w = ft_printf("ft_print = %f\n",  (double)-0);
	w = ft_printf("ft_print = %f\n",  NAN);
	w = ft_printf("ft_print = %f\n",  -NAN);
	w = ft_printf("ft_print = %lf\n",  (long double)INFINITY);
	w = ft_printf("ft_print = %lf\n",  LDBL_MAX);
	w = ft_printf("ft_print = %lf\n",  LDBL_MIN);
	w = ft_printf("ft_print = %lf\n",  (long double)NAN);
	w = ft_printf("ft_print = %lf\n",  (long double)99985851717179119119.0);
	w = ft_printf("ft_print = %lf\n",  (long double)9998.0);
	w = ft_printf("%f\n",  0.00685);
	w = ft_printf("\n partie fraction de 0.00685 \n%f\n", 0.00685);
	w = ft_printf("ft_print = %0.1lf\n",  (long double)0.049);
	return (0);
}
