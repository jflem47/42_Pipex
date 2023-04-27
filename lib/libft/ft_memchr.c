/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:34:13 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/14 15:53:43 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	tlf;
	unsigned int	i;
	char			*ptr;

	tlf = c;
	i = 0;
	ptr = (char *)s;
	if (!s)
		return (NULL);
	while (i < n)
	{
		if ((unsigned char)ptr[i] == tlf)
			return ((void *)&ptr[i]);
		i++;
	}
	return (NULL);
}
