/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:31:31 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/14 15:31:32 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	slength;
	size_t	dlength;

	j = 0;
	i = 0;
	if (dst == NULL && dstsize == 0)
		return (ft_strlen(src));
	while (dst[j] != '\0')
		j++;
	dlength = j;
	slength = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dlength)
		return (slength + dstsize);
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (dlength + slength);
}
