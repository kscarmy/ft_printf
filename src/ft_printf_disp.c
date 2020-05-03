#include "printf.h"

void	ft_putchar_printf(char c, t_point *ptf)
{
	write(1, &c, 1);
	ptf->ret = ptf->ret + 1;
}

void	ft_putstr_printf(char *str, t_point *ptf)
{
	int i;
	long maxi;

	i = 0;
	maxi = ptf->pco;
	while (str[i] != '\0' && (maxi > 0 || maxi == -1))
	{
		write(1, &str[i], 1);
		i++;
		if (maxi != -1)
			maxi = maxi - 1;
	}
	ptf->ret = ptf->ret + i;
}
