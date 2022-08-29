/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dantavar <dantavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:08:01 by dantavar          #+#    #+#             */
/*   Updated: 2022/08/10 00:46:12 by dantavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *err)
{
	write(2, err, ft_strlen(err));
	exit (1);
}

void	parent_free(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex -> cmd_paths[i])
	{
		free(pipex -> cmd_paths[i]);
		i++;
	}
	free(pipex -> cmd_paths);
}

char	*find_path(char **envp)
{
	while (ft_strncmp("PATH", *envp, 4))
		envp++;
	return (*envp + 5);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex -> tube[0]);
	close(pipex -> tube[1]);
	close(pipex -> infile);
	close(pipex -> outfile);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pipex	pipex;

	if (argc != 5)
		error("Invalid input");
	pipex.infile = open(argv[1], O_RDONLY);
	if (pipex.infile < 0)
		error("Invalide file");
	pipex.outfile = open(argv[argc - 1], O_CREAT | O_WRONLY | O_RDONLY, 777);
	if (pipex.outfile < 0)
		error("Invalid outfile");
	if (pipe(pipex.tube) < 0)
		error("Invalid pipe");
	pipex.paths = find_path(envp);
	pipex.cmd_paths = ft_split(pipex.paths, ':');
	pipex.pid1 = fork();
	if (pipex.pid1 == 0)
		child1(pipex, argv, envp);
	pipex.pid2 = fork();
	if (pipex.pid2 == 0)
		child2(pipex, argv, envp);
	close_pipes(&pipex);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	parent_free(&pipex);
	return (0);
}
