/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 11:56:25 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/15 17:21:16 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	tw;
	unsigned int	i;
	unsigned char	*ptr;

	if (!b)
		return (NULL);
	ptr = b;
	i = 0;
	tw = c;
	while (i < len)
	{
		*ptr++ = tw;
		i++;
	}
	return (b);
}
