/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:01:18 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/24 16:58:43 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
/* return the index of the closing quote, return 0 if encounters an input that
ends the entry, see includes/parsing.h */
static int	ft_find_closing_quote(char *str, char quote, int i)
{
	int	str_len;
	int	index_closing_q;

	str_len = ft_strlen(str);
	if (!str || i >= str_len - 1 || ft_strindex(BASE_QUOTES, quote) == -1)
		return (0);
	index_closing_q = i + 1;
	while (index_closing_q < str_len && str[index_closing_q])
	{
		if (ft_char_in_base(str[index_closing_q], CHAR_END_INPUT))
			return (-1);
		if (str[index_closing_q] == quote)
			return (index_closing_q);
		index_closing_q++;
	}
	return (0);
}

static void	ft_inc_nb_s_q(char *str, int *i, int *quote_group)
{
	*i = ft_find_closing_quote(str, S_QUOTE, *i);
	*quote_group++;
}

static void	ft_inc_nb_d_q(char *str, int *i, int *quote_group)
{
	*i = ft_find_closing_quote(str, D_QUOTE, *i);
	*quote_group++;
}

static bool	b_simple_quit(char *str)
{
	if ((ft_strocc(str, S_QUOTE) % 2 != 0) || ft_strocc(str, D_QUOTE) % 2 != 0)
		return (false);
	else
		return (true);
}

/* Comment : When heredoc (GNL) needs to be adjusted */
/* Comment : dans l'idee, on peut utiliser mon ft_strdup_limiters avec 
ft_find_closing_quote 
Avec quote_group on peut malloc le nb de sous arg*/
/* est-ce que on peut inclure char space dans single quote ?*/
bool	b_closing_quotes(char *str)
{
	int	len_str;
	int	i;
	int	quote_group;

	i = 0;
	quote_group = 0;
	len_str = ft_strlen(str);
	if (!str || len == 0)
		return (false);
	while (i < len_str)
	{
		if ((str[i] == S_QUOTE && !ft_find_closing_quote(str, S_QUOTE, i)) \
		|| (str[i] == D_QUOTE && !ft_find_closing_quote(str, D_QUOTE, i)))
			return (false);
		if (str[i] == S_QUOTE && ft_find_closing_quote(str, S_QUOTE, i))
			ft_inc_nb_s_q(str, &i, &quote_group);
		if (str[i] == D_QUOTE && ft_find_closing_quote(str, D_QUOTE, i))
			ft_inc_nb_d_q(str, &i, &quote_group);
		i++;
	}
	return (true);
}
*/
