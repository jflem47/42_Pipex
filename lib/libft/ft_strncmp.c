/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:25:01 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/15 17:31:50 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	c;

	c = 0;
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while ((s1[c] != '\0' || s2[c] != '\0') && c < n)
	{
		if (s1[c] < 0)
			return (1);
		else if (s2[c] < 0)
			return (-1);
		else if (s1[c] > s2[c])
			return (1);
		else if (s1[c] < s2[c])
			return (-1);
		c++;
	}
	return (0);
}
