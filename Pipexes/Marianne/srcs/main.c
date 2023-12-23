/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 07:22:39 by mbruyant          #+#    #+#             */
/*   Updated: 2023/11/01 16:31:07 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	if (argc == 5)
	{
		ft_parse(&pipex, argc, argv, envp);
		ft_init(&pipex, argv, envp);
		if (pipe(pipex.fd_pipe) == -1)
			ft_exit_msg(ft_err_msg(strerror(errno), ": ", \
			argv[1], errno), &pipex);
		ft_pipex_process(&pipex);
		ft_wait(&pipex);
		ft_exit_msg(ft_return_exit(&pipex), &pipex);
	}
	else
	{
		ft_putendl_fd("Wrong input", 2);
		return (0);
	}
}
