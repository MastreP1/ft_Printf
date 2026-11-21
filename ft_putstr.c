/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:04:32 by omejri            #+#    #+#             */
/*   Updated: 2026/11/20 14:53:14 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, unsigned int *count)
{
	int	i;

	if (!s)
	{
		i = ft_putstr("(null)", count);
		if (i == -1)
			return (-1);
		return (1);
	}
	i = 0;
	while (s[i])
		i++;
	if (write(1, s, i) == -1)
		return (-1);
	(*count) += i;
	return (1);
}
