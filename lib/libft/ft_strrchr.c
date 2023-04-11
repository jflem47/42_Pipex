/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:58:19 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/15 17:25:56 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	tlf;
	int		s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	tlf = c;
	s += s_len;
	if (*s == '\0' && tlf == '\0')
		return ((char *)s);
	while (s_len >= 0)
	{
		if (*s == tlf)
			return ((char *)s);
		s--;
		s_len--;
	}
	return (NULL);
}
