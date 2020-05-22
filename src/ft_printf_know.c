#include "../includes/ft_printf.h"

void	ft_know_flags(t_point *ptf) // définis le flags
{
	ptf->fag = ptf->fmt[ptf->i + ptf->u];
	ptf->u = ptf->u + 1;
}

void	ft_know_width(t_point *ptf) // définis la largeur (width)
{
	if (ptf->fmt[ptf->i + ptf->u] == '*')
	{
		ptf->wdh = va_arg(ptf->ap, int);
		ptf->u = ptf->u + 1;
		if (ptf->wdh < 0)
		{
			ptf->wdh = ptf->wdh * -1;
			ptf->fag = '-';
		}
	}
	else
	{
		ptf->wdh = ft_atoi(&ptf->fmt[ptf->i + ptf->u]);
		while (ft_isdigit(ptf->fmt[ptf->i + ptf->u]) == 1)
			ptf->u = ptf->u + 1;
	}
}

void	ft_know_precision(t_point *ptf) // précision (pco)
{
	ptf->u = ptf->u + 1; // skip le "." de début grâce à ça
	if (ptf->fmt[ptf->i + ptf->u] == '*')
	{
		ptf->pco = va_arg(ptf->ap, int);
		ptf->u = ptf->u + 1;
	}
	else
	{
		ptf->pco = ft_atoi(&ptf->fmt[ptf->i + ptf->u]);
		while (ft_isdigit(ptf->fmt[ptf->i + ptf->u]) == 1)
			ptf->u = ptf->u + 1;
	}
}
