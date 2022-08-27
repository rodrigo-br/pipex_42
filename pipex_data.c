#include "pipex.h"

void	init_data(t_pipex_data *pipata)
{
	pipata->fork_id[0] = -1;
	pipata->fork_id[1] = -1;
	pipata->fd[0] = -1;
	pipata->fd[1] = -1;
	pipata->cmds = NULL;
	pipata->files = NULL;
	pipata->paths = NULL;
}

void	pick_path(char **envp, t_pipex_data *pipata)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH", 4))
		{
			pipata->paths = ft_split(envp[i] + 5, ':');
			break ;
		}
		i++;
	}
}