/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:17:37 by omejri            #+#    #+#             */
/*   Updated: 2026/11/19 14:49:31 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int i, unsigned int *count)
{
	int	temp;

	if (i > 9)
	{
		temp = ft_putunbr(i / 10, count);
		if (temp == -1)
			return (-1);
	}
	if (ft_putchar((i % 10) + '0', count) == -1)
		return (-1);
	return (1);
}
