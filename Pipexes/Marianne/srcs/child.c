/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:22:37 by mbruyant          #+#    #+#             */
/*   Updated: 2023/11/01 15:25:35 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_access_cmd(t_pipex *pipex, char *cmd)
{
	int		i;
	char	*path_cmd;

	i = 0;
	if (!cmd || !pipex->path_found)
		return (NULL);
	while (pipex->paths[i])
	{
		path_cmd = ft_strjoin(pipex->paths[i], cmd);
		if (access(path_cmd, F_OK) == 0)
			return (path_cmd);
		free(path_cmd);
		i++;
	}
	return (NULL);
}

char	*ft_path_cmd(t_pipex *pipex, int ap, char *cmd)
{
	if (ap == 0)
		return (ft_access_cmd(pipex, cmd));
	if (ap == 1)
	{
		if (!access(cmd, F_OK))
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	return (NULL);
}

static void	ft_leave(char **cmd, char *path_cmd, char *err)
{
	ft_err_msg(cmd[0], ": ", err, errno);
	ft_free_2d_array(cmd);
	free(path_cmd);
}

static void	ft_cleanup(t_pipex *pipex, char *path_cmd, char **cmd, int which)
{
	if (which == 0)
	{
		ft_err_msg(pipex->gv[pipex->ww_gv], " : command not found", "", \
		CMD_NOT_FOUND);
		ft_close_fds(pipex);
		ft_exit_msg(CMD_NOT_FOUND, pipex);
	}
	if (which == 1)
	{
		ft_leave(cmd, path_cmd, \
		"command not found (no such files or directory)");
		ft_close_fds(pipex);
		ft_exit_msg(CMD_NOT_FOUND, pipex);
	}
	if (which == 2)
	{
		ft_leave(cmd, path_cmd, "dup err");
		ft_exit_msg(GEN_ERR, pipex);
	}
	if (which == 3)
	{
		ft_leave(cmd, path_cmd, "execve error");
		ft_exit_msg(GEN_ERR, pipex);
	}
}

void	ft_execve(t_pipex *pipex, int w_gv, int fd_in, int fd_out)
{
	char	**cmd;
	char	*path_cmd;

	if (!pipex->gv[w_gv])
		return ;
	pipex->ww_gv = w_gv;
	cmd = ft_split(pipex->gv[w_gv], ' ');
	path_cmd = NULL;
	if (!cmd)
		ft_cleanup(pipex, path_cmd, cmd, 0);
	path_cmd = ft_path_cmd(pipex, ft_absolute_path(pipex->gv[w_gv]), cmd[0]);
	if (!path_cmd)
		ft_cleanup(pipex, path_cmd, cmd, 1);
	if (dup2(fd_in, STDIN_FILENO) == -1)
		ft_cleanup(pipex, path_cmd, cmd, 2);
	if (dup2(fd_out, STDOUT_FILENO) == -1)
		ft_cleanup(pipex, path_cmd, cmd, 2);
	ft_close_fds(pipex);
	if (execve(path_cmd, cmd, pipex->e) == -1)
		ft_cleanup(pipex, path_cmd, cmd, 3);
	return ;
}
