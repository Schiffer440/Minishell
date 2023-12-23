/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:22:39 by mbruyant          #+#    #+#             */
/*   Updated: 2023/10/31 21:55:00 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_init_paths(t_pipex *pipex, char **envp)
{
	int		i;

	i = -1;
	while (envp[++i])
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			pipex->paths = ft_mod_split(envp[i] + 5, ':', '/');
}

void	ft_open_infile(t_pipex *pipex, char **argv)
{
	if (access(argv[1], F_OK) || access(argv[1], R_OK))
	{
		ft_err_msg(strerror(errno), ": ", argv[1], errno);
		pipex->fd_infile = STDIN_FILENO;
	}
	else
		pipex->fd_infile = open(argv[1], O_RDONLY, 000644);
	if (pipex->fd_infile == -1)
		ft_exit_msg(ft_err_msg(strerror(errno), ": ", argv[1], errno), pipex);
}

void	ft_open_outfile(t_pipex *pipex, char **argv)
{
	if (!access(argv[pipex->gc - 1], F_OK) && \
	!access(argv[pipex->gc - 1], W_OK))
		unlink(argv[pipex->gc - 1]);
	if (!access(argv[pipex->gc - 1], F_OK) && \
	access(argv[pipex->gc - 1], W_OK))
		pipex->fd_outfile = open(".doc.tmp", O_RDWR | O_TRUNC | O_CREAT, \
		000644);
	else
		pipex->fd_outfile = \
		open(argv[pipex->gc - 1], O_RDWR | O_TRUNC | O_CREAT, 000644);
	if (pipex->fd_outfile == -1)
		ft_exit_msg(ft_err_msg(strerror(errno), ": ", \
		argv[pipex->gc - 1], errno), pipex);
}

void	ft_init(t_pipex *pipex, char **argv, char **envp)
{
	pipex->pid_1 = -1;
	pipex->pid_2 = -1;
	pipex->ww_gv = -1;
	ft_open_infile(pipex, argv);
	ft_open_outfile(pipex, argv);
	if (pipex->path_found)
		ft_init_paths(pipex, envp);
}
