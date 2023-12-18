/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:36:11 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/18 13:42:47 by mbruyant         ###   ########.fr       */
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
	pipe_ = 5,
	dollar = 6,
	question = 7
}t_tokens;

typedef struct s_cmds {
	struct s_cmds	*previous;
	struct s_cmds	*next;
	t_tokens		prev_token;
	t_tokens		next_token;
	bool			b_redir;
	int				fd_in;
	int				fd_out;
	bool			abs_path;
	bool			b_builtin;
	char			*cmd;
	char			*cmd_w_arg;
}	t_cmds;

typedef struct s_parse {
	int			token_nb;
	t_cmds		*cmds;
}	t_parse;

typedef struct s_env_node {
	char				*n_tag;
	char				*n_content;
	struct s_env_node	*next;
}	t_env_node;

typedef struct s_env {
	char		**env;
	t_env_node	*node_;
}	t_env;

/*======================= ENV FOLDER =======================*/
/* env_del.c */
void		ft_free_node(t_env_node *curr);
void		ft_env_free(t_env_node *envi);
t_env_node	*ft_find_node(t_env_node **envi, char *tag_);
t_env_node	*ft_find_prev_node(t_env_node **envi, char *tag_);
void		ft_env_del_elem(t_env_node *envi, char *tag_);
/* env_display.c */
void		ft_env_update(t_env_node *envi, char *tag_, char *cont);
void		ft_env_display(t_env_node **envi);
/* env_init.c */
t_env		*ft_init_envi(char **envp);
t_env_node	*ft_create_node(char *content_);
void		ft_add_envi_node(t_env_node **src, t_env_node *to_add);

/*======================= UTILS PART =======================*/
/* ft_2d_array.c */
int			ft_2d_lines(char **array);
void		ft_free_2d_array(char **array);
char		**ft_copy_2d_array(char **arr, int from, int len);
int			ft_len_2d_array(char **arr);
int			ft_2d_has_doubles(char **arr);

/* ft_strdup_limiters.c */
char		*ft_strdup_limiters(char *str, int from, int until);

#endif