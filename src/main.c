/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:25:04 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/27 17:51:08 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int		f1;
	int		f2;
	char	**path_test;

	if (ac < 5)
		return (ft_putstr_fd("pipex: not enough arguments.\n", 2), FAILURE);
	if (ac > 5)
		return (ft_putstr_fd("pipex: too many arguments.\n", 2), FAILURE);
	path_test = get_paths(envp);
	if (!path_test)
		return (error_msg(), FAILURE);
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (ft_putstr_fd("pipex: Cannot open file.\n", 2), FAILURE);
	pipex(f1, f2, av, envp);
	free_all(path_test);
	return (SUCCESS);
}
