/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:34:48 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/20 18:40:01 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	parse_format(const char *str)
{
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			return ((char)*str);
		}
		str++;
	}
	return ('s');
}

static int	print_char(va_list toprint)
{
	ft_putchar_fd(va_arg(toprint, int), 1);
	return (1);
}

static int	print_str(va_list toprint)
{
	char	*res;

	res = va_arg(toprint, char *);
	if (!res)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(res, 1);
	return (ft_strlen(res));
}

int	print_factory(va_list toprint, char flag)
{
	if (flag == 'c')
		return (print_char(toprint));
	if (flag == 's')
		return (print_str(toprint));
	if (flag == 'p')
		return (print_ptr(toprint));
	if (flag == 'i' || flag == 'd')
		return (print_num(toprint));
	if (flag == 'u')
		return (print_unsigned(toprint));
	if (flag == 'x')
		return (print_hexa(toprint, flag));
	if (flag == 'X')
		return (print_hexa(toprint, flag));
	if (flag == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
