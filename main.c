/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 03:57:42 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/29 17:45:45 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, const char **argv, char **envp)
{
	t_pipex_data	p;

	check_argc_error(argc);
	if (!fill_data(argv, envp, &p))
		return (-1);
	pipex(&p);
}
