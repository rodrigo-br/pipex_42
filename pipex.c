/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 03:37:21 by ralves-b          #+#    #+#             */
/*   Updated: 2022/09/02 15:45:54 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_child(t_pipex_data *p)
{
	int	i;

	i = -1;
	while (p->cmd_1[++i])
		free(p->cmd_1[i]);
	free(p->cmd_1);
	i = -1;
	while (p->cmd_2[++i])
		free(p->cmd_2[i]);
	free(p->cmd_2);
	i = -1;
	while (p->paths[++i])
		free(p->paths[i]);
	free(p->paths);
}

void	pipex(t_pipex_data *p)
{
	pipe(p->pipe);
	p->parent = fork();
	if (p->parent < 0)
		return (perror("FORK"));
	if (!p->parent)
	{
		child_process(p);
		free_child(p);
	}
	else
		parent_process(p);
}
