/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:36:11 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/26 13:59:33 by mbruyant         ###   ########.fr       */
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
# define SYNTAX_ERR "minishell: syntax error near unexpected token '"

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

/*======================= QUOTES FOLDER =======================*/
/* quotes/quoting.c */
char		ft_quoting_char(char *str);
bool		b_closing_quotes(char *str);

/*======================= UTILS FOLDER =======================*/
char		**ft_split_unbase(char const *s, char *base);
char		**ft_split_base(char const *s, char *base);
char		**ft_split_entry_exit(char *str);
bool		ft_only_sep_base(char *str, char *base);
bool		ft_only_sep_unbase(char *str, char *base);
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

/*======================= PARSING FOLDER =======================*/
/* parsing/parse_input.c */
/* parsing/token_parse.c */
bool		ft_is_valid_token(char *str);
int			ft_get_valid_token_nb(char **token_arr);
/* parsing/print_error.c */
void		ft_msg_end(char *str, char type, bool del_struct, t_parse *ms);
void		ft_free_cmds(t_cmd **cmds);
void		ft_free_all(t_parse *ms);
#endif