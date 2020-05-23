#include "../includes/ft_printf.h"

int		ft_false_type(t_point *ptf)
{
	ptf->i = ptf->i;
	if ((ptf->fmt[ptf->i + ptf->u] != 's') && (ptf->fmt[ptf->i + ptf->u] != '%')
	 && (ptf->fmt[ptf->i + ptf->u] != 'c') && (ptf->fmt[ptf->i + ptf->u] != 'd')
	  && (ptf->fmt[ptf->i + ptf->u] != 'p') && (ptf->fmt[ptf->i + ptf->u] != 'u')
		 && (ptf->fmt[ptf->i + ptf->u] != 'i') && (ptf->fmt[ptf->i + ptf->u] != 'x')
		  && (ptf->fmt[ptf->i + ptf->u] != 'X')
			&& (ptf->fmt[ptf->i + ptf->u] != '0')
			&& (ptf->fmt[ptf->i + ptf->u] != '.')
			&& (ptf->fmt[ptf->i + ptf->u] != '-')
			&& (ptf->fmt[ptf->i + ptf->u] != '*')
			&& (ft_isdigit(ptf->fmt[ptf->i + ptf->u] == 1)))
			{
				// printf("\ni+u '%c'\n", ptf->fmt[ptf->i + ptf->u]);
				return (0);
			}
	return (1);
}

void	ft_ana_types(t_point *ptf) // envoie direct sur la fonction correspondant au type
{
	if (ptf->typ == 's')
		ft_printf_s(ptf);
	if (ptf->typ == '%')
		ft_printf_percent(ptf);
	if (ptf->typ == 'c')
		ft_printf_c(ptf);
	if (ptf->typ == 'd')
		ft_printf_d(ptf);
	if (ptf->typ == 'p')
		ft_printf_p(ptf);
	if (ptf->typ == 'u')
		ft_printf_u(ptf);
	if (ptf->typ == 'x')
		ft_printf_x(ptf);
	if (ptf->typ == 'X')
		ft_printf_x(ptf);
	// printf("go ds printfs\n");// A SUPPRIMER
}

int	ft_make_type(char type, t_point *ptf) // insere le type ds ptf->typ
{
	ptf->typ = type;
	ptf->u = ptf->u + 1;
	return (0);
}

int	ft_find_type(t_point *ptf) // trouve ici le type
{
	if (ptf->fmt[ptf->i + ptf->u] == 's' && ptf->u > 0)
		return (ft_make_type('s', ptf)); // == return (0) et a trouvé un "s"
	if (ptf->fmt[ptf->i + ptf->u] == '%' && ptf->u > 0)
		return (ft_make_type('%', ptf)); // == return (0) et a trouvé un "%"
	if (ptf->fmt[ptf->i + ptf->u] == 'c' && ptf->u > 0)
		return (ft_make_type('c', ptf)); // == return (0) et a trouvé un "c"
	if ((ptf->fmt[ptf->i + ptf->u] == 'd'
	|| ptf->fmt[ptf->i + ptf->u] == 'i') && ptf->u > 0)
		return (ft_make_type('d', ptf)); // == return (0) et a trouvé un "d"
	if (ptf->fmt[ptf->i + ptf->u] == 'p' && ptf->u > 0)
		return (ft_make_type('p', ptf)); // == return (0) et a trouvé un "p"
	if (ptf->fmt[ptf->i + ptf->u] == 'u' && ptf->u > 0)
		return (ft_make_type('u', ptf)); // == return (0) et a trouvé un "u"
	if (ptf->fmt[ptf->i + ptf->u] == 'x' && ptf->u > 0)
		return (ft_make_type('x', ptf)); // == return (0) et a trouvé un "x"
	if (ptf->fmt[ptf->i + ptf->u] == 'X' && ptf->u > 0)
		return (ft_make_type('X', ptf)); // == return (0) et a trouvé un "X"
	else
	{
		// printf("error type not support\n");// A SUPPRIMER
		ptf->u = ptf->u + 1;
	}
	return (ft_false_type(ptf));
}

void	ft_ana_flags(t_point *ptf) // soccupe de flags, width et précision
{
	// printf("i = %d, u = %d, fmt = %s\n", ptf->i, ptf->u, ptf->fmt);
	// ptf->i = ptf->i + 1; // tcheck pq ça fais disfonctionner %s
	while (ft_find_type(ptf) == 1)
	{
		if (ptf->fmt[ptf->i + ptf->u] == '-' || ptf->fmt[ptf->i + ptf->u] == '0')
			ft_know_flags(ptf); // définis le flags
		if (ptf->fmt[ptf->i + ptf->u] == '-')
			ft_know_flags(ptf); // définis le flags
		if (ft_isdigit(ptf->fmt[ptf->i + ptf->u]) || ptf->fmt[ptf->i + ptf->u] == '*')
			ft_know_width(ptf); // définis la largeur (width)
		if (ptf->fmt[ptf->i + ptf->u] == '.')
			ft_know_precision(ptf);
		if (ft_false_type(ptf) == 0)
			break;
	}
	// printf("ret :%d\n", ptf->ret);// A SUPPRIMER
	// printf("i :%d\n", ptf->i);// A SUPPRIMER
	// printf("ret :%u\n", ptf->u);// A SUPPRIMER
	// printf("typ :%c\n", ptf->typ);// A SUPPRIMER
	if (ft_false_type(ptf) == 1)
		ft_ana_types(ptf);
	else
	{
		// ft_putchar_printf(ptf->fmt[ptf->i + ptf->u], ptf);
		ptf->i = ptf->i + ptf->u;
	}
}
