/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:59:31 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 21:50:12 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	clean_space(char *str)
{
	size_t	i;
	int		value;

	i = 0;
	while (str[i] != 39 && str[i] != 34 && str[i])
		i++;
	if (i == ft_strlen(str))
		return ;
	value = str[i];
	while (str[++i] != value)
	{
		if (str[i] == ' ')
			str[i] = 1;
	}
}

void	revert_space(char **str, t_rev_spc rs)
{
	while (str[rs.word])
	{
		rs.i = 0;
		while (str[rs.word][rs.i] != 39 && str[rs.word][rs.i] != 34
			&& str[rs.word][rs.i])
			rs.i++;
		if (rs.i != ft_strlen(str[rs.word]))
		{	
			rs.value = str[rs.word][rs.i];
			while (str[rs.word][++rs.i] != rs.value)
			{
				if (str[rs.word][rs.i] == 1)
				{
					str[rs.word][rs.i] = ' ';
					if (rs.map == -1)
						rs.map = rs.word;
				}
			}
		}
		rs.word++;
	}
	if (rs.map != -1)
		str[rs.map] = ft_substr(str[rs.map], 1, ft_strlen(str[rs.map]) - 2);
}

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

void	fill_data(char **argv, char **envp, t_pipex_data *p)
{
	t_rev_spc	rs;

	rs.word = 0;
	rs.map = -1;
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
	clean_space(argv[2]);
	clean_space(argv[3]);
	p->cmd_1 = ft_split(argv[2], ' ');
	p->cmd_2 = ft_split(argv[3], ' ');
	revert_space(p->cmd_1, rs);
	revert_space(p->cmd_2, rs);
	pick_path(envp, p);
}
