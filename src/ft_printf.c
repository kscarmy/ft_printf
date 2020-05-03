#include "printf.h"

void ft_init_ptf(t_point	*ptf, char *format)
{
	ptf->fmt = format;
	ptf->i = 0;
	ptf->u = 0;
	ptf->ret = 0;
	ptf->wdh = 0;
	ptf->pco = 0;

}

int ft_printf(const char *format, ...)
{
	t_point ptf; // déclare la structure ptf

	ft_init_ptf(&ptf, (char *)format); //init ptf
	va_start(ptf.ap, format);
	while (ptf.fmt[ptf.i] != '\0')
	{
		ft_putchar_printf(ptf.fmt[ptf.i], &ptf);
		ptf.i = ptf.i + 1;
	}
	va_end(ptf.ap);
	return (ptf.ret);
}
