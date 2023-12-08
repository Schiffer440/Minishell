/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:30 by adugain           #+#    #+#             */
/*   Updated: 2023/12/08 23:57:49 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_paths(t_data *data)
{
	int		i;
	char	**mypath;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PATH", 4) == 0)
			break ;
		else
			i++;
	}
	data->env[i] += 5;
	mypath = ft_split(data->env[i], ':');
	return (mypath);
}

char	*get_exec(char **paths, char **cl_cmd)
{
	char	*exec;
	char	*cl_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		cl_path = ft_strjoin_pipex(paths[i], "/", 0);
		exec = ft_strjoin_pipex(cl_path, cl_cmd[0], 1);
		if (access(exec, F_OK | X_OK) == 0)
			break ;
		else
		{
			free(exec);
			exec = NULL;
			i++;
		}
	}
	return (exec);
}

void	ft_exec(t_data *data)
{
	int	pid;
	char	**path;
	char	*cl_path;

	pid = fork();
	if (pid == -1)
		P("Erreur a gerer + free");
	if (pid == 0)
	{
		path = get_paths(data);
		cl_path = get_exec(path, data->cmd[0].exec);
		if (execve(cl_path, data->cmd[0].exec, data->env) == -1)
		{
			ft_free_tab_c(path);
			free(cl_path);
			exit(0);
		}
	}
	wait(NULL);
}
