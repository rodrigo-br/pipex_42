#include "pipex.h"
#include <stdio.h>

int	main (int argc, const char **argv, char **envp)
{
	t_pipex_data	p;
	int i;

	i = 0;
	check_argc_error(argc);
	if (!fill_data(argv, envp, &p))
		return (-1);
	pipex(&p);
}
