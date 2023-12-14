/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:24:30 by adugain           #+#    #+#             */
/*   Updated: 2023/12/14 18:56:44 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

static void	exec_error(char **paths, t_data *data)
{
	char	*msg;

	msg = ft_strjoin_pipex(ft_strdup("command not found: "), \
	ft_strdup(data->cmd[0].exec[0]), 3);
	ft_free_tab_c(data->cmd[0].exec);
	ft_free_tab_c(paths);
	perror(msg);
	free(msg);
	exit(127);
}

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
	int		pid;
	char	**path;
	char	*cl_path;

	pid = fork();
	if (pid == -1)
		P("Erreur a gerer + free");
	if (pid == 0)
	{
		path = get_paths(data);
		cl_path = get_exec(path, data->cmd[0].exec);
		if (!cl_path || execve(cl_path, data->cmd[0].exec, data->env) == -1)
		{
			exec_error(path, data);
		}
		free_cmd_struc(data);
		// ft_free_tab_c(data->cmd[0].exec);
		ft_free_tab_c(path);
		// free(data->cmd);
	}
	while (wait(NULL) > 0)
			;
}
