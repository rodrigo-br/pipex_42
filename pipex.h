/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 23:27:06 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 03:50:32 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft_42/printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

typedef struct s_pipex_data
{
	pid_t	parent;
	int		pipe[2];
	int		outfile;
	int		infile;
	char	**paths;
	char	**cmd_1;
	char	**cmd_2;
}	t_pipex_data;

void	check_argc_error(int n);
void    pipex(t_pipex_data *p);
void	parent_process(t_pipex_data *p);
void	child_process(t_pipex_data *p);
int		fill_data(const char **argv, char **envp, t_pipex_data *p);

#endif
