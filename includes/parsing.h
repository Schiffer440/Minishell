/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:36:11 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/16 18:52:57 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdbool.h>

/* respectivement < > << >> | $ ? */
typedef enum s_tokens
{
	redir_in = 1,
	redir_out = 2,
	redir_in_app = 3,
	redir_out_app = 4,
	pipe = 5,
	dollar = 6,
	question = 7
}t_tokens;

typedef struct s_cmd {
	t_cmd		*previous;
	t_cmd		*next;
	t_tokens	prev_token;
	t_tokens	next_token;
	bool		b_redir;
	int			fd_in;
	int			fd_out;
	bool		abs_path;
	bool		b_builtin;
	char		*cmd;
	char		*cmd_w_arg;
}	t_cmd;

typedef struct s_parse {
	int			token_nb;
	t_cmd		*cmds;
}	t_parse;

typedef struct s_env {
	char	**env;
}	t_env;

/* ft_2d_array.c */
int		ft_2d_lines(char **array);
void	ft_free_2d_array(char **array);
char	**ft_copy_2d_array(char **arr, int from, int len);
int		ft_len_2d_array(char **arr);
int		ft_2d_has_doubles(char **arr);

#endif