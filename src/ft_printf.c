#include "../includes/ft_printf.h"

void ft_init_ptf(t_point	*ptf, char *format)
{
	ptf->fmt = format;
	ptf->i = 0;
	ptf->u = 0;
	ptf->ret = 0;
	ptf->wdh = 0;
	ptf->pco = -1;
	ptf->siz = -1;
	ptf->str = NULL;
	ptf->c = 0;
	ptf->b = 10;
	ptf->maj = 'a' - 10;
	ft_printf_itoa_init(ptf);
	ptf->g = 0;
	ptf->fag = 0;
	ptf->ui = 0;
}

void	ft_clear_ptf(t_point *ptf)
{
	ptf->u = 0;
	ptf->ui = 0;
	ptf->wdh = 0;
	ptf->pco = -1;
	ptf->typ = 0;
	ptf->fag = 0;
	ptf->siz = -1;
	ptf->str = NULL;
	ptf->c = 0;
	ptf->b = 10;
	ptf->maj = 'a' - 10;
	ft_printf_itoa_init(ptf);
	ptf->g = 0;
}

int ft_printf(const char *format, ...)
{
	t_point ptf; // déclare la structure ptf

	ft_init_ptf(&ptf, (char *)format); //init ptf
	va_start(ptf.ap, format);
	while (ptf.fmt[ptf.i] != '\0')
	{
		if (ptf.fmt[ptf.i] == '%')
			ft_ana_flags(&ptf);
		else
		{
			ft_putchar_printf(ptf.fmt[ptf.i], &ptf);
			ptf.i = ptf.i + 1;
		}
	}
	// printf("\ntyp:%c fag:%c\n", ptf.typ, ptf.fag);// A SUPPRIMER
	va_end(ptf.ap);
	return (ptf.ret);
}
