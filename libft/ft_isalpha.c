/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 09:24:09 by guderram          #+#    #+#             */
/*   Updated: 2019/11/08 09:25:13 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_isalpha(int c)
{
	if (((65 <= c) && (c <= 90)) || ((97 <= c) && (c <= 122)))
		return (1);
	else
		return (0);
}