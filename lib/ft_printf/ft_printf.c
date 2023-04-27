/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:26:28 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/21 13:08:56 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	char	flag;
	int		i;

	i = 0;
	if (!str)
		return (0);
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			flag = parse_format(str);
			i += print_factory(args, flag);
			str += 2;
		}
		else
		{
			ft_putchar_fd((char)*str, 1);
			str++;
			i++;
		}
	}
	va_end(args);
	return (i);
}
