#include "pipex.h"

void	check_argc_error(int n)
{
	if (n != 5)
	{
		ft_printf("tá errado o número de argumentos, véi\n");
		exit(0);
	}
}