/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:59:03 by adugain           #+#    #+#             */
/*   Updated: 2023/11/10 11:23:01 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include <sys/types.h>
# define P(str) (printf("%s\n", str))

typedef	struct s_cmd
{
	int	pid;
	char	**path;
	char	**cl_cmd;
	char	*exec;
	int	pipe;
}t_cmd;

typedef struct s_data
{
	t_cmd	*cmd;
	char	*input;
	char	cwd[PATH_MAX];
	char	*prompt;
	char	**env;
}t_data;

void	ft_exec(t_data *data);
void	end_all(t_data *data);
void	endloop(t_data *data);
void	free_token(char *s1, char *s2, int token);
void	process(t_data *data);
char	**get_env(char **envp);
void	init_all(t_data *data, char **envp);
void	initloop(t_data *data);
// void	exit_shell(t_data *data);
char	**get_paths(t_data *data);
// void	ft_echo(t_data *data);
void	builtin(t_data *data);

#endif 