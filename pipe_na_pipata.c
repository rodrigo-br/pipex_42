/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_na_pipata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 17:03:32 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/27 17:36:15 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_na_pipata(t_pipex_data *pipata)
{
	if (pipe(pipata->fd) == -1)
	{
		ft_printf("deu ruim no pipe, véi");
		exit(0);
	}
	pipata->fork_id[0] = fork();
	if (pipata->fork_id[0] < 0)
	{
		ft_printf("deu ruim no primeiro fork, véi");
		exit(0);
	}
	if (pipata->fork_id[0] == 0)
	{
		dup2(pipata->fd[1], STDOUT_FILENO);
		close(pipata->fd[0]);
		close(pipata->fd[1]);
		execve(pipata->cmds[0], pipata->files, NULL);
	}
	pipata->fork_id[1] = fork();
	if (pipata->fork_id[1] < 0)
	{
		ft_printf("deu ruim no segundo fork, véi");
		exit(0);
	}
	if (pipata->fork_id[1] == 0)
	{
		dup2(pipata->fd[0], STDIN_FILENO);
		close(pipata->fd[0]);
		close(pipata->fd[1]);
		execve(pipata->cmds[1], pipata->files, NULL);
	}
	waitpid(pipata->fork_id[0], NULL, 0);
	waitpid(pipata->fork_id[1], NULL, 0);
}