/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:27:33 by mbruyant          #+#    #+#             */
/*   Updated: 2023/10/31 21:08:02 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_has_path_in_env(t_pipex *pipex, char **envp)
{
	int		i;

	i = -1;
	if (!envp)
		return (0);
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->path_found = 1;
			return (1);
		}
	}
	return (0);
}

/* returns 1 if str is a AP and file exists, 
returns 0 if err, not AP or doesnt exist */
int	ft_absolute_path(char *gv)
{
	int		bol;
	char	**temp;

	bol = 0;
	temp = ft_split(gv, ' ');
	if (!temp)
		return (0);
	if ((ft_strncmp(temp[0], "/", 1) == 0) || \
	(ft_strncmp(temp[0], "./", 2) == 0) || \
	(ft_strncmp(temp[0], "../", 3) == 0))
		bol = 1;
	if ((access(temp[0], F_OK) != 0) && bol)
		bol = 0;
	ft_free_2d_array(temp);
	return (bol);
}

void	ft_parse(t_pipex *pipex, int argc, char **argv, char **envp)
{
	pipex->paths = NULL;
	pipex->gc = argc;
	pipex->gv = argv;
	pipex->e = envp;
	pipex->ret = 0;
	if (!access(argv[argc - 1], F_OK) && access(argv[argc - 1], W_OK))
	{
		ft_err_msg(strerror(errno), ": ", argv[argc - 1], 1);
		pipex->ret = CMD_NO_EXEC;
	}
	ft_parse_path(pipex, argv, envp);
}

void	ft_parse_path(t_pipex *pipex, char **argv, char **envp)
{
	pipex->path_found = -1;
	pipex->abs_cmd_1 = -1;
	pipex->abs_cmd_2 = -1;
	if (!ft_has_path_in_env(pipex, envp))
		pipex->path_found = 0;
	if (ft_has_path_in_env(pipex, envp))
		pipex->path_found = 1;
	if (ft_absolute_path(argv[2]))
		pipex->abs_cmd_1 = 1;
	if (!ft_absolute_path(argv[2]))
		pipex->abs_cmd_1 = 0;
	if (ft_absolute_path(argv[3]))
		pipex->abs_cmd_2 = 1;
	if (!ft_absolute_path(argv[3]))
		pipex->abs_cmd_2 = 0;
}
