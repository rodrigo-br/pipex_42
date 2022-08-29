/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 03:37:21 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 03:59:10 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipex(t_pipex_data *p)
{
	pipe(p->pipe);
	p->parent = fork();
	if (p->parent < 0)
		return (perror("FORK"));
	if (!p->parent)
		child_process(p);
	else
		parent_process(p);
}
