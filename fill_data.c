/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:59:31 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 19:27:50 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pick_path(char **envp, t_pipex_data *p)
{
	int		i;
	char	**temp;

	i = 0;
	temp = NULL;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5))
		{
			temp = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
	if (temp == NULL)
		ft_perror("PATH not found", 0);
	i = 0;
	while (temp[i])
		i++;
	p->paths = (char **)malloc((i + 1) * sizeof(*temp));
	p->paths[i] = NULL;
	while (i--)
		p->paths[i] = ft_strjoin(temp[i], "/");
}

void	fill_data(const char **argv, char **envp, t_pipex_data *p)
{
	p->erro = -2;
	p->erro_2 = 0;
	p->infile = open(argv[1], O_RDONLY);
	if (p->infile == -1)
	{
		p->erro_2 = 1;
		p->infile = open("/dev/null", O_RDONLY);
		write(2, "bash: ", 6);
		perror(argv[1]);
	}
	p->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	p->cmd_1 = ft_split(argv[2], ' ');
	p->cmd_2 = ft_split(argv[3], ' ');
	pick_path(envp, p);
}
