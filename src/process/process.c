/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:40:52 by jlemieux          #+#    #+#             */
/*   Updated: 2023/04/20 13:56:33 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**get_paths(char **envp)
{
	char	*path;
	char	**res;
	int		i;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			path = envp[i];
			break ;
		}
		i++;
	}
	if (!path)
	{
		ft_putstr_fd("pipex: no PATH variable is set.\n", 2);
		exit(FAILURE);
	}
	res = ft_split(path, ':');
	return (res);
}

static char	**get_args(char *cmd)
{
	char	**res;

	res = ft_split(cmd, ' ');
	return (res);
}

void	child_process1(int fd, char *cmd, char **envp, int end[2])
{
	char	**paths;
	char	**cmdargs;
	int		i;

	paths = get_paths(envp);
	cmdargs = get_args(cmd);
	dup2(fd, STDIN_FILENO);
	dup2(end[1], STDOUT_FILENO);
	close(end[0]);
	close(fd);
	i = -1;
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(cmd, cmdargs[0]);
		execve(cmd, cmdargs, envp);
		free(cmd);
	}
	exit(FAILURE);
}

void	child_process2(int fd, char *cmd, char **envp, int end[2])
{
	char	**paths;
	char	**cmdargs;
	int		i;

	paths = get_paths(envp);
	cmdargs = get_args(cmd);
	dup2(fd, STDOUT_FILENO);
	dup2(end[0], STDIN_FILENO);
	close(end[1]);
	close(fd);
	i = -1;
	while (paths[++i])
	{
		cmd = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(cmd, cmdargs[0]);
		execve(cmd, cmdargs, envp);
		free(cmd);
	}
	exit(FAILURE);
}
