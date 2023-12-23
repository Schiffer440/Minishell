/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:23:33 by mbruyant          #+#    #+#             */
/*   Updated: 2023/11/01 16:52:48 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* close, read, write, access, dup, dup2, pipe, unlink, fork, execve, exit */
# include <unistd.h>
/* perror */
# include <stdio.h>
/* open */
# include <fcntl.h>
/* strerror */
# include <string.h>
/* wait, waitpid */
# include <sys/wait.h>
/* errno */
# include <errno.h>
# include "../my_libft/libft.h"

# define WRITE_END 1
# define READ_END 0
# define GEN_ERR 1
# define CMD_NO_EXEC 126
# define CMD_NOT_FOUND 127

typedef struct s_pipex
{
	char	**paths;
	int		fd_pipe[2];
	int		fd_infile;
	int		fd_outfile;
	int		path_found;
	int		gc;
	char	**gv;
	char	**e;
	int		abs_cmd_1;
	int		abs_cmd_2;
	pid_t	pid_1;
	pid_t	pid_2;
	int		ret;
	int		ww_gv;
}	t_pipex;

/* main.c */

/* utils.c */
void	ft_exit_msg(int err, t_pipex *pipex);
int		ft_err_msg(char *m1, char *m2, char *m3, int erno);
void	ft_db_close(int fd);
void	ft_close_fds(t_pipex *pipex);

/* child.c */
char	*ft_access_cmd(t_pipex *pipex, char *cmd);
char	*ft_path_cmd(t_pipex *pipex, int ap, char *cmd);
void	ft_execve(t_pipex *pipex, int w_gv, int fd_in, int fd_out);

/* init.c */
void	ft_init_paths(t_pipex *pipex, char **envp);
void	ft_init(t_pipex *pipex, char **argv, char **envp);
void	ft_open_infile(t_pipex *pipex, char **argv);
void	ft_open_outfile(t_pipex *pipex, char **argv);

/* parse.c */
void	ft_parse(t_pipex *pipex, int argc, char **argv, char **envp);
int		ft_absolute_path(char *gv);
int		ft_has_path_in_env(t_pipex *pipex, char **envp);
void	ft_parse_path(t_pipex *pipex, char **argv, char **envp);

/* wait.c */
void	ft_pipex_process(t_pipex *pipex);
int		ft_return_exit(t_pipex *p);
void	ft_wait(t_pipex *pipex);

#endif
