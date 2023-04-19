/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:25:04 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/19 17:42:18 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	f1;
	int	f2;

	if (ac < 5)
		return (ft_printf("pipex: not enough arguments.\n"), FAILURE);
	f1 = open(av[1], O_RDONLY);
	f2 = open(av[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
		return (ft_printf("pipex: Cannot open file.\n"), FAILURE);
	pipex(f1, f2, av, envp);
	return (SUCCESS);
}
