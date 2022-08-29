/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 03:38:06 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 17:51:28 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(t_pipex_data *p)
{
	int		i;
	char	*cmd;

	i = -1;
	access_errors(p, p->cmd_1);
	dup2(p->infile, STDIN_FILENO);
	dup2(p->pipe[1], STDOUT_FILENO);
	close(p->pipe[0]);
	close(p->infile);
	if (p->erro != -2)
	{
		while (p->paths[++i])
		{
			cmd = ft_strjoin(p->paths[i], p->cmd_1[0]);
			p->erro = execve(cmd, p->cmd_1, p->paths);
		}
		ft_perror(ft_strrchr(cmd, '/') + 1, p->erro);
	}
}

void	parent_process(t_pipex_data *p)
{
	char	*cmd;
	int		status;
	int		i;

	i = -1;
	access_errors(p, p->cmd_2);
	waitpid(-1, &status, 0);
	dup2(p->outfile, STDOUT_FILENO);
	dup2(p->pipe[0], STDIN_FILENO);
	close(p->pipe[1]);
	close(p->outfile);
	if (p->erro != -2)
	{
		while (p->paths[++i])
		{
			cmd = ft_strjoin(p->paths[i], p->cmd_2[0]);
			p->erro = execve(cmd, p->cmd_2, p->paths);
		}
		ft_perror(ft_strrchr(cmd, '/') + 1, p->erro);
	}
	exit(127);
}
