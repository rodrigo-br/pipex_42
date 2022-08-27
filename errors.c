/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-b <ralves-b@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 03:35:20 by ralves-b          #+#    #+#             */
/*   Updated: 2022/08/27 03:35:21 by ralves-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check_argc_error(int n)
{
	if (n != 5)
	{
		ft_printf("tá errado o número de argumentos, véi\n");
		exit(0);
	}
}