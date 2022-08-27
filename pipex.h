/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:27:06 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/27 01:02:19 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft_42/printf/ft_printf.h"

typedef struct s_pipex_data
{
	int		fork_id[2];
	int		fd[2];
	char	**paths;
	char	**cmds;
	char	**files;
}	t_pipex_data;

void	check_argc_error(int n);
void	pick_path(char **envp, t_pipex_data *pipata);
void	init_data(t_pipex_data *pipata);

#endif