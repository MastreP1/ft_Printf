/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:32:21 by omejri            #+#    #+#             */
/*   Updated: 2026/11/19 14:16:08 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int i, unsigned int *count)
{
	long	num;
	int		temp;

	num = i;
	if (num < 0)
	{
		temp = ft_putchar('-', count);
		if (temp == -1)
			return (-1);
		num = -num;
	}
	if (num > 9)
	{
		temp = ft_putnbr(num / 10, count);
		if (temp == -1)
			return (-1);
	}
	if (ft_putchar((num % 10) + '0', count) == -1)
		return (-1);
	return (1);
}
