/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 12:21:19 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/14 14:07:27 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	const char		*s;
	unsigned int	i;

	i = 0;
	d = dst;
	s = src;
	if (!dst || !src)
		return (dst);
	while (i < n)
	{
		*d++ = *s++;
		i++;
	}
	return (dst);
}
