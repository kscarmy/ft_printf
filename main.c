#include "./includes/ft_printf.h"
#include <stdio.h>
#include <unistd.h>


// typedef	struct	s_point
// {
// char d[64];
// int t;
// int b;
// int maj;
// }					t_point;

// void	ft_printf_itoa_init(t_point *ptf)
// {
// 	int x;
//
// 	x = 0;
// 	while (x < 64)
// 	{
// 		ptf->d[x] = '\0';
// 		x++;
// 	}
//
// }

// void	ft_putchar_printf(char c) // remettre t_point *ptf en plus
// {
// 	write(1, &c, 1);
// }



// void	ft_printf_d_disp(t_point *ptf)
// {
// 	int x;
//
// 	x = 0;
//
// 	while (ptf->d[x] != '\0')
// 	{
// 	ft_putchar_printf((ptf->d[x]));
// 	x++;
// 	}
// }

// void	ft_printf_itoa(t_point *ptf)
// {
// 	int u;
// 	int i;
//
// 	ft_printf_itoa_init(ptf);
// 	i = 0;
// 	u = (ptf->t > 0) ? ptf->t : (ptf->t * -1);
// 	ptf->d[0] = (ptf->t > 0) ? '+' : '-';
// 	while (u >= ptf->b)
// 	{
// 		u = u / ptf->b;
// 		i++;
// 	}
// 	i = (u > 0) ? (i + 1) : i;
// 	u = (ptf->t > 0) ? ptf->t : (ptf->t * -1);
// 	while (i > 0)
// 	{
// 		ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
// 		u = u / ptf->b;
// 		i--;
// 	}
// 	ft_printf_d_disp(ptf);
// }

// int	main(void)
// {
// 	t_point ptf;
//
// int ptn;
// ptn = 1234;
// ptf.t = ptn;
// ptf.b = 12;
// ptf.maj = 'a' - 10;
// ft_printf_itoa(&ptf);
//
// printf("\n");
// }




int	main(void)
{

	int i = 0;
	int l = 0;
	char *s;
	char *str1;
	char *str2;
	char c;
	// int a = 10;
	int *p;
	int *j;
	int x;
	unsigned int u;
	// unsigned long long ull = 12;

	s = "abc";
	str1 = "a la prochaine";
	str2 = NULL;
	c = 'A';
	p = NULL;
	j = &i;
	x = 198;
	u = 13;

	i = ft_printf("-->|%-3.*x|<--\n", -1, x);
	l = printf("-->|%-3.*x|<--\n", -1, x);
	printf("ret = %d\n", i);
	printf("ret = %d\n", l);

}
