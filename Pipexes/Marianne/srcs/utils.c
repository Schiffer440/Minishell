/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:22:32 by mbruyant          #+#    #+#             */
/*   Updated: 2023/10/31 22:15:56 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exit_msg(int err, t_pipex *pipex)
{
	if (pipex)
	{
		if (pipex->paths)
			ft_free_2d_array(pipex->paths);
		if (!access(".doc.tmp", F_OK))
			unlink(".doc.tmp");
		ft_db_close(pipex->fd_infile);
		ft_db_close(pipex->fd_outfile);
		if (pipex->ret != err && err != 0)
			pipex->ret = err;
	}
	exit(err);
}

int	ft_err_msg(char *m1, char *m2, char *m3, int erno)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(m1, STDERR_FILENO);
	ft_putstr_fd(m2, STDERR_FILENO);
	ft_putendl_fd(m3, STDERR_FILENO);
	return (erno);
}

void	ft_db_close(int fd)
{
	if (fd >= 0)
		close(fd);
}

void	ft_close_fds(t_pipex *pipex)
{
	if (pipex->fd_infile > 2)
		if (close(pipex->fd_infile) == -1)
			ft_err_msg("close error3", "", "", errno);
	if (pipex->fd_outfile > 2)
		if (close(pipex->fd_outfile) == -1)
			ft_err_msg("close error4", "", "", errno);
	if (pipex->fd_pipe[READ_END] > 2)
		if (close(pipex->fd_pipe[READ_END]) == -1)
			ft_err_msg("close error5", "", "", errno);
	if (pipex->fd_pipe[WRITE_END] > 2)
		if (close(pipex->fd_pipe[WRITE_END]) == -1)
			ft_err_msg("close error6", "", "", errno);
}
