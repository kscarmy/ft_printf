#ifndef PRINTF_H
# define PRINTF_H
# include "../libft/src/libft.h"
# include <stdarg.h>

# include <stdio.h> // à enlever !

typedef	struct	s_point
{
	va_list ap;
	int ret; // valeur retournée
	int i; // valeur du curseur de lecture dans format à %
	int u; // valeur du curseur de lecture dans format de % à type
	int wdh; // un entier décimal ou "*" avec sa valeur dans un argument après
	int pco; // un entier décimal ou "*" avec sa valeur dans un argument après
	char *str; // récupe un arg,
	char *fmt; // *format de base
	char typ; // contient le type
	char fag; // flags : "-" ou "0"  peut etre mettre un int avec des valeurs corres
}					t_point;


int ft_printf(const char *format, ...);
void ft_init_ptf(t_point	*ptf, char *format);
void	ft_putchar_printf(char c, t_point *ptf);
void	ft_putstr_printf(char *str, t_point *ptf);



#endif
