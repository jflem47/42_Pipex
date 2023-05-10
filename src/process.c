/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 15:40:52 by jlemieux          #+#    #+#             */
/*   Updated: 2023/05/10 14:10:08 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
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
	res = ft_split(path, ':');
	return (res);
}

void	error_msg(void)
{
	ft_putendl_fd("command not found", 2);
	ft_putendl_fd("command not found", 2);
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
	char	*cmd1;
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
		cmd1 = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(cmd1, cmdargs[0]);
		execve(cmd, cmdargs, envp);
		free(cmd);
		free(cmd1);
	}
	free_all(paths);
	free_all(cmdargs);
	ft_putendl_fd("command not found.", 2);
	exit(EXIT_FAILURE);
}

void	child_process2(int fd, char *cmd, char **envp, int end[2])
{
	char	**paths;
	char	**cmdargs;
	char	*cmd1;
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
		cmd1 = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(cmd1, cmdargs[0]);
		execve(cmd, cmdargs, envp);
		free(cmd);
		free(cmd1);
	}
	free_all(paths);
	free_all(cmdargs);
	ft_putendl_fd("command not found.", 2);
	exit(EXIT_FAILURE);
}
