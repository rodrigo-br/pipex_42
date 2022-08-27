#include "pipex.h"
#include <stdio.h>

char	**pick_commands(int n, char **args, t_pipex_data *pipata)
{
	int		counter;
	char	**cmds;

	counter = 0;
	cmds = malloc(sizeof(char *) * n - 2);
	cmds[n - 3] = NULL;
	while (counter < n - 3)
	{
		cmds[counter] = ft_strjoin("/bin/", args[counter + 2]);
		counter++;
	}
	pipata->files = malloc(sizeof(char *) * 4);
	pipata->files[0] = ft_strdup("fill");
	pipata->files[1] = ft_strdup(args[1]);
	pipata->files[2] = ft_strdup(args[n - 1]);
	pipata->files[3] = NULL;
	return (cmds);
}

int katchau (int argc, char **argv, char **envp, t_pipex_data pipata)
{
	char	**files;
	int		i;
	int		fd;
	i = 0;
	ft_printf("ARQUIVOS :\n");
	while (pipata.paths[i])
	{
		ft_printf("path %d = %s\n", i, pipata.paths[i]);
		i++;
	}
	i = 1;
	while (pipata.files[i])
	{
		ft_printf("%s\n", pipata.files[i]);
		i++;
	}
	i = 0;
	ft_printf("\nCOMANDOS :\n");
	while (pipata.cmds[i])
	{
		ft_printf("%s\n", pipata.cmds[i]);
		i++;
	}
	ft_printf("\nEXECVE :\n");
	execve(pipata.cmds[0], pipata.files, envp);
	perror("execve");
	exit(EXIT_FAILURE);
	return (0);
}

int main (int argc, char **argv, char **envp)
{
	t_pipex_data	pipata;

	check_argc_error(argc);
	init_data(&pipata);
	pipata.cmds = pick_commands(argc, argv, &pipata);
	pick_path(envp, &pipata);
	open_pipex_files(&pipata);
	pipe_na_pipata(&pipata);
	// katchau(argc, argv, envp, pipata);
	return (0);
}
