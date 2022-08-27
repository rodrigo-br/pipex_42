/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipex_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 02:59:21 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/27 22:19:08 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	open_pipex_files(t_pipex_data *pipata)
{
	pipata->input_fd = open(pipata->files[1], O_RDONLY);
	if (pipata->input_fd < 0)
	{
		ft_printf("deu ruim abrindo o infile véi\n");
		exit(0);
	}
	pipata->output_fd = open(pipata->files[2], O_CREAT 
		| O_RDWR | O_TRUNC, 0000644);
	if (pipata->output_fd < 0)
	{
		ft_printf("deu ruim abrindo/criando o outfile véi\n");
		exit(0);
	}
}
