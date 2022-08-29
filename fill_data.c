/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:59:31 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 03:56:53 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pick_path(char **envp, t_pipex_data *p)
{
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	while (!temp)
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
			temp = ft_split(envp[i] + 5, ':');
		i++;
	}
	i = 0;
	while (temp[i])
		i++;
	p->paths = (char **)malloc((i + 1) * sizeof(*temp));
	p->paths[i] = NULL;
	while (i--)
		p->paths[i] = ft_strjoin(temp[i], "/");
}

int	fill_data(const char **argv, char **envp, t_pipex_data *p)
{
	p->infile = open(argv[1], O_RDONLY);
	p->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p->infile < 0 || p->outfile < 0)
		return (perror("ERRO NO ARQUIVO"), 0);
	p->cmd_1 = ft_split(argv[2], ' ');
	p->cmd_2 = ft_split(argv[3], ' ');
	pick_path(envp, p);
	return (1);
}
