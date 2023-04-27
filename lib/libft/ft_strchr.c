/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:17:16 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:21 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	tlf;

	tlf = c;
	if (!s)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == tlf)
			return ((char *)s);
		s++;
	}
	if (*s == '\0' && tlf == '\0')
		return ((char *)s);
	return (NULL);
}
