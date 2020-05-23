#include "../includes/ft_printf.h"

void	ft_printf_s_disp(char *str, t_point *ptf)
{
	int i;

	i = 0;
	// printf ("wdh :%d\n", ptf->wdh); // A SUPPRIMER
	// printf ("siz :%d\n", ptf->siz); // A SUPPRIMER
	// printf ("pco :%d\n", ptf->pco); // A SUPPRIMER
	while (ptf->wdh > ptf->pco && ptf->pco < 0
		&& ptf->fag == '0' && ptf->wdh > ptf->siz)
		ft_printf_d_incre('0', ptf);
	while (ptf->wdh > ptf->siz && ptf->fag != '-' && ptf->wdh != 0)
	{
		ft_putchar_printf(' ', ptf);
		// printf("NON\n"); // A SUPPRIMER
		ptf->wdh = ptf->wdh - 1;
	}
	// printf ("wdh :%d\n", ptf->wdh); // A SUPPRIMER
	if (ptf->pco < 0 || ptf->pco > ptf->siz)
		ft_putstr_printf(ptf->str, ptf);
	// printf ("pco :%d\n", ptf->pco); // A SUPPRIMER
	while (ptf->pco > 0 && ptf->pco <= ptf->siz)
	{
		ft_putchar_printf(str[i], ptf);
		i++;
		if (ptf->pco != -1)
			ptf->pco = ptf->pco - 1;
	}
	// printf ("pco :%d\n", ptf->pco); // A SUPPRIMER
	while (ptf->wdh > ptf->siz && ptf->fag == '-')
	{
		ft_putchar_printf(' ', ptf);
		ptf->wdh = ptf->wdh - 1;
	}
}

int	ft_printf_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_printf_s(t_point *ptf) // soccupe de modifier %s si besoin
{
	// char *str;

	// str = ptf->str;
	// printf("alors tonton ?\n");// A SUPPRIMER
	ptf->str = va_arg(ptf->ap, char*);
	if (ptf->str == NULL) // si va_arg = NULL
		ptf->str = "(null)";
	// printf("str :%s\n", ptf->str);// A SUPPRIMER
	// printf ("\n'%s'\n", ptf->str); // A SUPPRIMER
	if (ft_printf_strlen(ptf->str) < ptf->pco || ptf->pco < 0)
		ptf->siz = ft_printf_strlen(ptf->str);
	else
		ptf->siz = ptf->pco;
	// printf("%d", ptf->siz);// A SUPPRIMER
	// ptf->siz = ((int)ft_strlen(ptf->str) < ptf->pco) ? (int)ft_strlen(ptf->str) : ptf->pco;

	ft_printf_s_disp(ptf->str, ptf);
	ptf->i = ptf->i + ptf->u;
	ft_clear_ptf(ptf);
}
