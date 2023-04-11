/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:19:06 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/14 17:13:32 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\n')
		return (1);
	else if (c == '\t' || c == '\v')
		return (1);
	else if (c == '\f' || c == '\r')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	c;
	int	signe;
	int	res;

	c = 0;
	signe = 1;
	res = 0;
	if (!str)
		return (0);
	while (ft_isspace(str[c]) == 1)
		c++;
	if (str[c] == '-' || str[c] == '+')
	{
		if (str[c] == '-')
			signe *= -1;
		if (ft_isdigit(str[c + 1]) != 1)
			return (0);
		c++;
	}
	while (str[c] >= '0' && str[c] <= '9')
	{
		res = (res * 10) + (str[c] - '0');
		c++;
	}
	return (res * signe);
}
