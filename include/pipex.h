/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:25:13 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/27 10:37:13 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "fcntl.h"
# include "ft_printf.h"
# include "libft.h"
# include <sys/errno.h>

# define SUCCESS 0
# define FAILURE 1

//UTILS
void	child_process1(int fd, char *cmd, char **envp, int end[2]);
void	child_process2(int fd, char *cmd, char **envp, int end[2]);

//PIPEX
void	pipex(int f1, int f2, char **av, char **envp);

#endif
