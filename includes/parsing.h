/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:36:11 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/23 21:50:16 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H
# include <stdbool.h>

# define BASE_QUOTES "\'\""
# define S_QUOTE '\''
# define D_QUOTE '\"'
/* COMMENT : test with bash but not so sure about the space */
# define CHAR_END_INPUT "<>|& \t\n"
# define BASE_TOKEN "<>|"

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

/* CMD_W_ARGS should be char** dsl */
typedef struct s_cmd {
	struct s_cmd	*previous;
	struct s_cmd	*next;
	t_tokens		prev_token;
	t_tokens		next_token;
	bool			b_redir;
	int				fd_in;
	int				fd_out;
	bool			b_abs_path;
	bool			b_builtin;
	char			**cmd_w_arg;
	char			*cmd;
	int				nb_s_quote;
	int				nb_d_quote;
	bool			b_has_quote;
	char			quote_used;
}	t_cmd;

typedef struct s_parse {
	int			token_nb;
	t_cmd		*cmds;
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
/* env_actual.c */
bool		ft_exists_in_env(t_env_node *envi, char *tag_);
char		*ft_get_tag_or_cont(char *str, char t_or_c);
void		ft_actualize_env(t_env_node *envi, char *str);
/* env_del.c */
t_env_node	*ft_find_node(t_env_node **envi, char *tag_);
t_env_node	*ft_find_prev_node(t_env_node **envi, char *tag_);
void		ft_env_del_elem(t_env_node **envi, char *tag_);
/* env_display.c */
void		ft_env_update(t_env_node *envi, char *tag_, char *cont);
void		ft_env_display(t_env_node **envi);
/* env_free.c */
void		ft_free_node(t_env_node *curr);
void		ft_env_free(t_env_node *envi);
/* env_init.c */
t_env		*ft_init_envi(char **envp);
t_env_node	*ft_create_node(char *content_, char *tag_, char *cont);
void		ft_add_envi_node(t_env_node **src, t_env_node *to_add);
t_env		*ft_init_no_envi(void);
/*======================= UTILS PART =======================*/
/* files/ft_2d_array.c */
int			ft_2d_lines(char **array);
void		ft_free_2d_array(char **array);
char		**ft_copy_2d_array(char **arr, int from, int len);
int			ft_len_2d_array(char **arr);
int			ft_2d_has_doubles(char **arr);

/* files/ft_str_utils.c */
int			ft_strocc(char *str, char c);
char		*ft_strdup_limiters(char *str, int from, int until);
int			ft_strindex(char *str, char c);
int			ft_strbase(char *str, const char *base);
int			ft_char_in_base(char c, const char *base);

/*======================= QUOTES FOLDER =======================*/
bool		b_closing_quotes(char *str);

#endif