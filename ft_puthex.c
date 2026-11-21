/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:22:08 by omejri            #+#    #+#             */
/*   Updated: 2026/11/19 12:28:30 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int d, unsigned int *count)
{
	char	*t;
	int		temp;

	t = "0123456789abcdef";
	if (d / 16 != 0)
	{
		temp = ft_puthex(d / 16, count);
		if (temp == -1)
			return (-1);
	}
	if (write(1, t + (d % 16), 1) == -1)
		return (-1);
	(*count)++;
	return (1);
}
