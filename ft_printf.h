/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omejri <omejri@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:00:09 by omejri            #+#    #+#             */
/*   Updated: 2026/11/20 16:39:14 by omejri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(int c, unsigned int *count);
int	ft_puthex(unsigned int d, unsigned int *count);
int	ft_puthexx(unsigned int d, unsigned int *count);
int	ft_putnbr(int i, unsigned int *count);
int	ft_putptr(void *g, unsigned int *count);
int	ft_putstr(char *s, unsigned int *count);
int	ft_putunbr(unsigned int i, unsigned int *count);

#endif