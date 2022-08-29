/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   childs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 14:19:11 by dantavar          #+#    #+#             */
/*   Updated: 2022/08/05 14:15:11 by dantavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_cmd(char **paths, char *cmd)
{
	char	*tmp;
	char	*command;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		command = ft_strjoin(tmp, cmd);
		if (access(command, 0) == 0)
			return (command);
		paths++;
	}
	return (NULL);
}

void	child1(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.tube[1], 1);
	dup2(pipex.infile, 0);
	pipex.cmd_args = ft_split(argv[2], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
		error("Invalid command 1");
	close_pipes(&pipex);
	execve(pipex.cmd, pipex.cmd_args, envp);
	error("Invalid execve1");
}

void	child2(t_pipex pipex, char *argv[], char *envp[])
{
	dup2(pipex.tube[0], 0);
	dup2(pipex.outfile, 1);
	pipex.cmd_args = ft_split(argv[3], ' ');
	pipex.cmd = get_cmd(pipex.cmd_paths, pipex.cmd_args[0]);
	if (!pipex.cmd)
		error("Invalid command 2");
	close_pipes(&pipex);
	execve(pipex.cmd, pipex.cmd_args, envp);
	error("Invalid execve2");
}
