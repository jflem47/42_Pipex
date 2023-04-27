/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:28:16 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/21 12:54:29 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	get_len_add(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 16;
		i++;
	}
	return (i);
}

void	print_base(unsigned long num, int flag)
{
	if (num >= 16)
	{
		print_base(num / 16, flag);
		print_base(num % 16, flag);
	}
	else if (flag == 'x')
		write(1, &"0123456789abcdef"[num % 16], 1);
	else if (flag == 'X')
		write(1, &"0123456789ABCDEF"[num % 16], 1);
}

int	print_hexa(va_list toprint, int flag)
{
	unsigned long	num;

	num = va_arg(toprint, unsigned int);
	if (!num)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	if (num == 0)
		return (write(1, "0", 1));
	print_base(num, flag);
	return (get_len_add(num));
}

int	print_ptr(va_list toprint)
{
	unsigned long	num;

	num = va_arg(toprint, unsigned long);
	if (!num)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	print_base(num, 'x');
	return (get_len_add(num) + 2);
}
