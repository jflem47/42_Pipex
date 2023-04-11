/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:35:28 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/21 12:52:25 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

static int	get_len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n == LONG_MIN)
		return (21);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

// static int	get_len_unsigned(unsigned long n)
// {
// 	int	i;

// 	i = 0;
// 	if (n == 0)
// 		return (1);
// 	while (n > 0)
// 	{
// 		n /= 16;
// 		i++;
// 	}
// 	return (i);
// }

static void	ft_putnbr_unsigned(unsigned int n, int fd)
{
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		return ;
	}
	else
		ft_putnbr_unsigned(n / 10, fd);
	ft_putnbr_unsigned(n % 10, fd);
}

int	print_num(va_list toprint)
{
	long int	num;

	num = va_arg(toprint, int);
	ft_putnbr_fd(num, 1);
	return (get_len(num));
}

int	print_unsigned(va_list toprint)
{
	unsigned int	num;

	num = va_arg(toprint, unsigned int);
	ft_putnbr_unsigned(num, 1);
	return (get_len(num));
}
