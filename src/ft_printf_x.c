#include "../includes/ft_printf.h"

void	ft_printf_x_disp_suite(int *m, int *a, int *u, t_point *ptf)
{
	int x;
	// printf("%s\n", "test");
	// x = (ptf->b == 16 && ptf->ui == 0 && ptf->pco != 0) ? 0 : 1;
	// x = (ptf->ui == 0) ? 0 : 1;
	x = 1;
	// printf("\nd %c\n", ptf->d[0]);
	while (ptf->d[x] != '\0')
	{
		while (x > 0 && *m > ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz))
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
	if (ptf->ui == 0 && ptf->pco != 0)
		ft_putchar_printf((ptf->d[0]), ptf);
}

void	ft_printf_x_disp(t_point *ptf)
{
	int m;
	int a;
	int u;

	u = ptf->wdh;
	if (ptf->d[0] == '-' && ptf->typ == 'd' && ptf->ui != 0)
		ft_putchar_printf('-', ptf);
	m = ptf->pco;
	a = 0;
	// if (ptf->ui == 0 && ptf->pco < 0)
	// {
	// 	ft_putchar_printf('0', ptf);
	// 	a++;
	// }
	while (ptf->ui == 0 && m - 1 > 0)
	{
		ft_putchar_printf('0', ptf);
		m--;
		a++;
	}
	// printf("%s\n", "test");
	ft_printf_x_disp_suite(&m, &a, &u, ptf);
	// printf("%s\n", "test");
	ptf->siz = (ptf->ui == 0) ? 1 : ptf->siz + a;
}

void	ft_printf_itoa_x(t_point *ptf)
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
	i = (u > 0) ? (i + 1) : i;
	// i = i + 1;
	// printf ("i : %d\n", i);
	ptf->siz = (ptf->ui < 0) ? (i + 1) : i;
	u = (ptf->ui > 0) ? ptf->ui : (ptf->ui * -1);
	while (i > 0)
	{
		ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
		u = u / ptf->b;
		i--;
	}
	ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
	// printf("\n'%c %c %c'\n", ptf->d[0], ptf->d[1], ptf->d[2]);
	// ptf->d[i] = ((u % ptf->b) + ((u % ptf->b > 9) ? ptf->maj : '0'));
}

void	ft_printf_x_suite(t_point *ptf)
{
	// ptf->b = ptf->b;
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
	&& ptf->wdh != 0 && ptf->fag != '0' && ptf->ui != 0)
		ft_printf_d_incre(' ', ptf);
	while (ptf->wdh > ptf->siz + ptf->g && ptf->fag == '0'
	&& ptf->wdh > ptf->pco && ptf->pco >= 0)
		ft_printf_d_incre(' ', ptf);
	// printf("\ntyp %c\n", );
	while (ptf->ui == 0 && ptf->wdh > 0 && ptf->wdh > ptf->pco
		&& (ptf->fag != '-') && ptf->pco > 0)
		ft_printf_d_incre(' ', ptf);
}

void	ft_printf_x(t_point *ptf)
{
	ptf->b = (ptf->typ == 'x' || ptf->typ == 'X') ? 16 : 10;
	ptf->maj = (ptf->typ == 'X') ? 'A' - 10 : 'a' - 10;
	ptf->ui = va_arg(ptf->ap, int);
	// ptf->ui = (ptf->ui < 0) ? (2004318071 - (ptf->ui * -1) -1) : ptf->ui;
	// printf("%u\n", ptf->ui);
	ft_printf_itoa_x(ptf);
	// printf("\n1 ui %u,siz %d,wdh %d,pco %d\n", ptf->ui, ptf->siz, ptf->wdh, ptf->pco);
	// printf("\na %c\n", ptf->d[0]);
	// printf("\nsiz %d\n", ptf->siz);
	ptf->siz = (ptf->ui == 0) ? 1 : ptf->siz;
	// printf("\nsiz %d\n", ptf->siz);
	if (ptf->pco > ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz))
		ptf->g = ptf->pco - ((ptf->d[0] == '-') ? ptf->siz - 1 : ptf->siz);
	// printf("\nsiz %d\n", ptf->siz);
	ft_printf_x_suite(ptf);
	// printf("\nsiz %d\n", ptf->siz);
	// printf("\nd %c\n", ptf->d[0]);
	// printf("\n2 ui %u,siz %d,wdh %d,pco %d\n", ptf->ui, ptf->siz, ptf->wdh, ptf->pco);
	ft_printf_x_disp(ptf);
	// printf("\n3 ui %u,siz %d,wdh %d,pco %d\n", ptf->ui, ptf->siz, ptf->wdh, ptf->pco);
	// printf("\nsiz %d\n", ptf->siz);
	while (ptf->wdh > ptf->siz && ptf->fag == '-' && ptf->wdh > ptf->pco)
		ft_printf_d_incre(' ', ptf);
	while (ptf->ui == 0 && ptf->wdh > ptf->pco && ptf->pco >= 0)
		ft_printf_d_incre(' ', ptf);
	// printf("\nsiz %d\n", ptf->siz);
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
