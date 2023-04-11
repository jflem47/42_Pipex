/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:31:48 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/15 13:42:58 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	res;

	res = 0;
	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static char	*str_factory(int *n, int *len, int *index)
{
	char	*res;

	if (*n < 0)
		*index += 1;
	res = malloc(*index * sizeof(char) + 1);
	if (!res)
		return (NULL);
	if (*n < 0)
	{
		res[0] = '-';
		if (*n == -2147483648)
		{
			res[1] = '2';
			*len -= 1;
			*n = -147483648;
		}
		*n = *n * -1;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		index;
	int		i_len;

	i_len = num_len(n);
	index = i_len;
	res = str_factory(&n, &i_len, &index);
	if (!res)
		return (NULL);
	res[index] = '\0';
	index--;
	while (i_len > 0)
	{
		res[index--] = (char)(n % 10) + '0';
		n /= 10;
		i_len--;
	}
	return (res);
}
