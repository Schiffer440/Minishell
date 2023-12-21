/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:59:03 by adugain           #+#    #+#             */
/*   Updated: 2023/12/21 17:51:02 by adugain          ###   ########.fr       */
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
# include "../libft/libft.h"
# include <sys/types.h>
# include "parsing.h"
# include "exec.h"
# define P(str) (printf("%s\n", str))
# define Pint(int) (printf("%d\n", int))

// typedef	struct s_cmd
// {
// 	char	**exec;
// }t_cmd;

typedef struct s_data
{
	char	*input;
	char	*cwd;
	char	*prompt;
	char	**env;
	// int	pipes;
}t_data;

void	ft_exec(t_data *data);
void	end_all(t_data *data, t_parse *parse);
void	endloop(t_data *data);
void	free_token(char *s1, char *s2, int token);
void	process(t_data *data, t_parse *parse);
char	**get_env(char **envp);
void	init_all(t_data *data, char **envp);
void	initloop(t_data *data);
// void	exit_shell(t_data *data);
char	**get_paths(t_data *data);
// void	ft_echo(t_data *data);
void	check_builtin(t_data *data ,t_parse *parse);
void	get_lst_cmds(t_data *data, t_parse *parse);
void	free_cmd_struc(t_data *data);
void	free_all(t_parse *parse);
void	visualizer(t_parse *parse);

#endif 