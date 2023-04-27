/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:24:57 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/20 12:36:04 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(int f1, int f2, char **av, char **envp)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	pipe(end);
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		child_process1(f1, av[2], envp, end);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		child_process2(f2, av[3], envp, end);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}
