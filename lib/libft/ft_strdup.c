/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:25:43 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/15 10:51:30 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!src)
		return (NULL);
	dest = (char *)malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, src, ft_strlen(src) + 1);
	return (dest);
}
