/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:44:18 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/14 16:32:12 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	unsigned int	c;
	unsigned int	d;

	c = 0;
	if (!to_find || !str)
		return (NULL);
	if (to_find[0] == '\0')
		return (str);
	while (str[c] != '\0' && c < n)
	{
		d = 0;
		while ((str[c + d] == to_find[d] && str[c + d] != '\0') && c + d < n)
		{
			if (to_find[d + 1] == '\0')
				return (&str[c]);
			d++;
		}
		c++;
	}
	return (NULL);
}
