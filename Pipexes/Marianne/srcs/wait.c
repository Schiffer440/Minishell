/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:22:37 by mbruyant          #+#    #+#             */
/*   Updated: 2023/11/01 16:51:26 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_pipex_process(t_pipex *pipex)
{
	pipex->pid_1 = fork();
	if (pipex->pid_1 == -1)
		ft_exit_msg(ft_err_msg("fork error", "", "", GEN_ERR), pipex);
	if (pipex->pid_1 == 0)
		ft_execve(pipex, 2, pipex->fd_infile, pipex->fd_pipe[WRITE_END]);
	if (close(pipex->fd_pipe[WRITE_END]) == -1)
		ft_exit_msg(ft_err_msg("close error1", "", "", GEN_ERR), pipex);
	else
		pipex->fd_pipe[WRITE_END] = -1;
	pipex->pid_2 = fork();
	if (pipex->pid_2 == -1)
		ft_exit_msg(ft_err_msg("fork error", "", "", GEN_ERR), pipex);
	if (pipex->pid_2 == 0)
		ft_execve(pipex, 3, pipex->fd_pipe[READ_END], pipex->fd_outfile);
	if (close(pipex->fd_pipe[READ_END]) == -1)
		ft_exit_msg(ft_err_msg("close error2", "", "", GEN_ERR), pipex);
	else
		pipex->fd_pipe[READ_END] = -1;
}

static void	ft_do(int which, char **cmd, char *path, int msg)
{
	if (which == 0)
		ft_free_2d_array(cmd);
	if (which == 1)
	{
		if (msg == 1)
			ft_err_msg(path, " : permission denied", "", CMD_NO_EXEC);
		free(path);
		ft_free_2d_array(cmd);
	}
}

int	ft_return_exit(t_pipex *p)
{
	char	**cmd;
	char	*path;

	if (access(p->gv[4], W_OK))
		return (GEN_ERR);
	cmd = ft_split(p->gv[3], ' ');
	if (!cmd)
		return (CMD_NOT_FOUND);
	if (cmd)
	{
		path = ft_path_cmd(p, ft_absolute_path(p->gv[3]), cmd[0]);
		if (!path)
		{
			ft_do(0, cmd, path, 0);
			return (CMD_NOT_FOUND);
		}
		if (access(path, X_OK))
		{
			ft_do(1, cmd, path, 1);
			return (CMD_NO_EXEC);
		}
		ft_do(1, cmd, path, 0);
	}
	return (0);
}

void	ft_wait(t_pipex *pipex)
{
	int		status;
	pid_t	ret;

	ret = 0;
	while (ret != -1)
	{
		if (ret == pipex->pid_2)
			status = ft_return_exit(pipex);
		ret = waitpid(-1, &status, 0);
	}
}
