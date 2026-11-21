/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:20:17 by omejri            #+#    #+#             */
/*   Updated: 2026/11/20 14:38:37 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_output(int i, va_list args, unsigned int *count)
{
	if (i == 0)
		return (ft_putchar(va_arg(args, int), count));
	else if (i == 1)
		return (ft_putstr(va_arg(args, char *), count));
	else if (i == 2)
		return (ft_putptr(va_arg(args, void *), count));
	else if (i == 3 || i == 4)
		return (ft_putnbr(va_arg(args, int), count));
	else if (i == 5)
		return (ft_putunbr(va_arg(args, unsigned int), count));
	else if (i == 6)
		return (ft_puthex(va_arg(args, unsigned int), count));
	else if (i == 7)
		return (ft_puthexx(va_arg(args, unsigned int), count));
	else if (i == 8)
		return (ft_putchar('%', count));
	return (-1);
}

static int	check(char s)
{
	unsigned int	i;
	char			*d;

	d = "cspdiuxX%";
	i = 0;
	while (d[i])
	{
		if (d[i] == s)
		{
			return (i);
		}
		i++;
	}
	return (-1);
}

static int	helper(const char *s, va_list args, unsigned int *j,
		unsigned int *i)
{
	int	temp;

	if (*s == '%' && check(*(s + 1)) != -1)
	{
		temp = check_output(check(*(s + 1)), args, j);
		(*i)++;
		if (temp == -1)
			return (-1);
		return (1);
	}
	temp = ft_putchar(*s, j);
	if (temp == -1)
		return (-1);
	return (0);
}

int	ft_printf(const char *s, ...)
{
	unsigned int	i;
	va_list			args;
	int				temp;
	unsigned int	j;

	if (!s)
		return (-1);
	va_start(args, s);
	i = 0;
	j = 0;
	while (s[i])
	{
		temp = helper(s + i, args, &j, &i);
		if (temp == -1)
		{
			va_end(args);
			return (-1);
		}
		i++;
	}
	va_end(args);
	return (j);
}
