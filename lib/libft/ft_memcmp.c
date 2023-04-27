/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:55:50 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/14 16:24:58 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	c;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	c = 0;
	if (n == 0)
		return (0);
	if (!s1)
		return (-1);
	if (!s2)
		return (1);
	while (c < n)
	{
		if (ptr1[c] != ptr2[c])
			return (ptr1[c] - ptr2[c]);
		c++;
	}
	return (0);
}
