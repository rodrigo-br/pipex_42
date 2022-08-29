/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:35:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 17:49:26 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argc_error(int n)
{
	if (n != 5)
	{
		write(2, "Invalid number of arguments\n", 28);
		exit(69);
	}
}

void	ft_perror(char *msg, int erro)
{
	write(2, "bash: ", 6);
	perror(msg);
	exit(erro);
}

void	access_errors(t_pipex_data *p, char **parent_cmd)
{
	int		i;
	char	*cmd;

	i = -1;
	while (p->paths[++i])
	{
		cmd = ft_strjoin(p->paths[i], parent_cmd[0]);
		if (!access(cmd, F_OK))
			p->erro = access(cmd, X_OK);
	}
	if (p->erro == -2)
	{
		write(2, "bash: ", 6);
		write(2, parent_cmd[0], ft_strlen(parent_cmd[0]));
		write(2, ": command not found\n", 20);
	}
}
