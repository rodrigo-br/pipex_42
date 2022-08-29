/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:59:31 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 02:05:33 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pick_path(char **envp, t_pipex_data *pipata)
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
	pipata->paths = (char **)malloc((i + 1) * sizeof(*temp));
	pipata->paths[i] = NULL;
	while (i--)
		pipata->paths[i] = ft_strjoin(temp[i], "/");
}
