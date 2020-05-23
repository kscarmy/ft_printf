#include "../includes/ft_printf.h"

void	ft_printf_itoa_ll(t_point *ptf)
{
	// printf ("t %d\n", ptf->t);
	long long u;
	long long i;
	long long t;
	i = 0;
	t = ptf->t;
	// printf ("t %lld\n", t);
	// printf("\nb %d\n", ptf->b);
	u = (t > 0) ? t : (t * -1);
	ptf->d[0] = (t > 0) ? '+' : '-';
	while (u >= ptf->b)
	{
		u = u / ptf->b;
		i++;
	}
	i = (u > 0) ? (i + 1) : i;
	ptf->siz = (ptf->t < 0) ? (i + 1) : i;
	u = (t > 0) ? t : (t * -1);
	while (i > 0)
	{
		ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
		u = u / ptf->b;
		i--;
	}
	// printf("%c%c%c%c\n", ptf->d[0], ptf->d[1], ptf->d[2], ptf->d[3]);
	// printf("%c %c %c\n", ptf->d[0], ptf->d[1], ptf->d[2]);
}

void	ft_printf_percent(t_point *ptf)
{
	ptf->siz = 1;
	while (ptf->wdh > ptf->siz && ptf->fag != '-' && ptf->wdh != 0)
	{
		if (ptf->fag == '0')
			ft_putchar_printf('0', ptf);
		else
			ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
	ft_putchar_printf('%', ptf);
	while (ptf->wdh > ptf->siz && ptf->fag == '-')
	{
		ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
