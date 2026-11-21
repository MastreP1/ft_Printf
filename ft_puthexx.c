/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:25:50 by omejri            #+#    #+#             */
/*   Updated: 2026/11/20 13:53:47 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexx(unsigned int d, unsigned int *count)
{
	char	*t;
	int		temp;

	t = "0123456789ABCDEF";
	if (d / 16 != 0)
	{
		temp = ft_puthexx(d / 16, count);
		if (temp == -1)
			return (-1);
	}
	if (write(1, t + (d % 16), 1) == -1)
		return (-1);
	(*count)++;
	return (1);
}
