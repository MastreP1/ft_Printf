/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:06:52 by omejri            #+#    #+#             */
/*   Updated: 2026/11/21 14:19:45 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	puthex(unsigned long d, unsigned int *count)
{
	char	*t;
	int		temp;

	t = "0123456789abcdef";
	if (d == 0)
	{
		temp = ft_putstr("(nil)", count);
		if (temp == -1)
			return (-1);
		else
			return (1);
	}
	if (d / 16 != 0)
	{
		temp = puthex(d / 16, count);
		if (temp == -1)
			return (-1);
	}
	if (write(1, t + (d % 16), 1) == -1)
		return (-1);
	(*count)++;
	return (1);
}

int	ft_putptr(void *g, unsigned int *count)
{
	unsigned long	nb;
	int				temp;

	nb = (unsigned long)g;
	if (nb == 0)
		return (puthex(nb, count));
	temp = write(1, "0x", 2);
	if (temp == -1)
		return (-1);
	(*count) += 2;
	return (puthex(nb, count));
}
