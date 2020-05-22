#include "../includes/ft_printf.h"

int		ft_printf_u_disp_suite(int *m, int *a, int *u, t_point *ptf)
{
	int x;

	x = 0;
	while (ptf->d[x] != '\0' && ptf->ui != 0)
	{
		while (x >= 0 && *m > ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz))
		{
			ft_putchar_printf('0', ptf);
			*m = *m - 1;
			*a = *a + 1;
		}
		while (*u > ptf->siz + ptf->g && ptf->pco < 0 && ptf->fag == '0')
		{
			ft_putchar_printf('0', ptf);
			*a = *a + 1;
			*u = *u - 1;
		}
		ft_putchar_printf((ptf->d[x]), ptf);
		x = x + 1;
	}
	return (x);
}

void	ft_printf_u_disp(t_point *ptf)
{
	int x;
	int m;
	int a;
	int u;

	u = ptf->wdh;
	m = ptf->pco;
	a = 0;
	if (ptf->ui == 0 && ptf->pco < 0)
	{
		ft_putchar_printf('0', ptf);
		a++;
	}
	while (ptf->ui == 0 && m > 0)
	{
		ft_putchar_printf('0', ptf);
		m--;
		a++;
	}
	x = ft_printf_u_disp_suite(&m, &a, &u, ptf);
	ptf->siz = (ptf->ui == 0) ? 1 : ptf->siz + a;
}

void	ft_printf_itoa_u(t_point *ptf)
{
	unsigned int u;
	unsigned int i;

	i = 0;
	u = ptf->ui;
	// u = (ptf->ui > 0) ? ptf->ui : (ptf->ui * -1);
	// ptf->d[0] = (ptf->ui > 0) ? '+' : '-';
	while (u >= (unsigned int)ptf->b)
	{
		u = u / ptf->b;
		i++;
	}
	// i = (u > 0) ? (i + 1) : i;
	ptf->siz = (ptf->ui < 10) ? 1 : i + 1;
	// u = (ptf->ui > 0) ? ptf->ui : (ptf->ui * -1);
	u = ptf->ui;
	while (i > 0)
	{
		ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
		u = u / ptf->b;
		i--;
	}
	ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
}

void	ft_printf_u_suite(t_point *ptf)
{
	while (ptf->ui == 0 && ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == '0' && ptf->wdh > ptf->siz)
		ft_printf_d_incre('0', ptf);
	while (ptf->ui == 0 && ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == 0 && ptf->wdh > ptf->siz)
		ft_printf_d_incre(' ', ptf);
	while (ptf->ui == 0 && ptf->wdh > ptf->pco && ptf->pco > 0
		&& ptf->fag != '-' && ptf->wdh > ptf->siz && ptf->wdh > ptf->pco)
		ft_printf_d_incre(' ', ptf);
	while (ptf->ui == 0 && ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == 0 && ptf->wdh > ptf->siz)
		ft_printf_d_incre(' ', ptf);
	while (ptf->wdh > ptf->siz + ptf->g && ptf->fag != '-'
	&& ptf->wdh != 0 && ptf->fag != '0' && ptf->ui != 0 && ptf->wdh > ptf->pco)
		ft_printf_d_incre(' ', ptf);
	while (ptf->wdh > ptf->siz + ptf->g && ptf->fag == '0'
	&& ptf->wdh > ptf->pco && ptf->pco >= 0)
		ft_printf_d_incre(' ', ptf);
	while (ptf->ui == 0 && ptf->wdh > 0 && ptf->wdh > ptf->pco
		&& (ptf->fag != '-') && ptf->wdh > ptf->siz)
		ft_printf_d_incre(' ', ptf);
}

void	ft_printf_u(t_point *ptf)
{
	ptf->ui = va_arg(ptf->ap, unsigned int);
	// printf("\n%u\n", ptf->ui);
	// printf("\%d\n", ptf->d[0]);
	ft_printf_itoa_u(ptf);
	// printf("\%d\n", ptf->d[0]);
	// printf("%d\n", ptf->siz);
	// printf("\nsiz %d\n", ptf->siz);
	ptf->siz = (ptf->ui == 0) ? 1 : ptf->siz;
	// printf("%d\n", ptf->siz);
	// if (ptf->pco > ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz))
	// 	ptf->g = ptf->pco - ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz);
	// printf
	// printf("\nsiz %d\n", ptf->siz);
	ft_printf_u_suite(ptf);
	// printf("\%d\n", ptf->d[0]);
	// printf("%d\n", ptf->siz);
	// printf("\nsiz %d\n", ptf->siz);
	ft_printf_u_disp(ptf);
	// printf("\nsiz %d\n", ptf->siz);
	while (ptf->wdh > ptf->siz && ptf->fag == '-' && ptf->wdh > ptf->pco)
		ft_printf_d_incre(' ', ptf);
	while (ptf->ui == 0 && ptf->wdh > ptf->pco && ptf->pco >= 0)
		ft_printf_d_incre(' ', ptf);
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
