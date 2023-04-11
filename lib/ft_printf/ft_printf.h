/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:27:05 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/21 11:53:51 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
char	parse_format(const char *str);
int		print_factory(va_list toprint, char flag);
int		print_ptr(va_list toprint);
int		print_hexa(va_list toprint, int flag);
int		print_num(va_list toprint);
int		print_unsigned(va_list toprint);

#endif