// #include <stdio.h>
#include "printf.h"

// int ft_printf(const char *format, ...);

int	main(void)
{
	int i = 0;
	int u = 0;
	char *str;
	char c;

	str = "jean";
	c = 'c';

/*	ft_putstr("ft_printf :\n");
	i = ft_printf("'%-4s suis'\n", str);
	printf("ret = %d\n", i);

	ft_putstr("printf :\n");
	u = printf("'%-4s suis'\n", str);
	printf("ret = %d\n", u);*/

	i = ft_printf("salut moi c'est michel\n");
	u = printf("salut moi c'est michel\n");
	printf("ret = %d\n", i);
	printf("ret = %d\n", u);



}
