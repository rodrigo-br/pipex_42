#include "pipex.h"
#include <stdio.h>

// void    pipex(int f1, int f2)
// {
//     int   end[2];
//     pid_t parent;
//     pipe(end);
//     parent = fork();
//     if (parent < 0)
//          return (perror("Fork: "));
//     if (!parent) // if fork() returns 0, we are in the child process
//         child_process(f1, cmd1);
//     else
//         parent_process(f2, cmd2);
// }

int	main (int argc, const char **argv, char **envp)
{
	t_pipex_data	p;
	int i;

	i = 0;
	check_argc_error(argc);
	pick_path(envp, &p);
	while(p.paths[i])
		ft_printf("%s\n", p.paths[i++]);
}
