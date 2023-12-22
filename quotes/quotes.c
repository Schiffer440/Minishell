/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 09:01:18 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/22 12:05:41 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* return the index of the closing quote, return -1 if encounters an input that
ends the entry, see includes/parsing.h */
static int	ft_find_closing_quote(char *str, char quote, int i)
{
	int	str_len;
	int	index_closing_q;

	str_len = ft_strlen(str);
	if (!str || i >= str_len - 1 || ft_strindex(BASE_QUOTES, quote) == -1)
		return (-1);
	index_closing_q = i;
	while (index_closing_q < str_len && str[index_closing_q])
	{
		if (ft_char_in_base(str[index_closing_q], CHAR_END_INPUT))
			return (-1);
		if (str[index_closing_q] == quote)
			return (index_closing_q);
		index_closing_q++;
	}
	return (-1);
}

/* Comment : When heredoc (GNL) needs to be adjusted */
/* Comment : dans l'idee, on peut utiliser mon ft_strdup_limiters avec 
ft_find_closing_quote */
bool	b_parse_quotes(char *str)
{
	int	nb_s_q;
	int	nb_d_q;
	int	len_str;
	int	i;

	i = 0;
	len_str = ft_strlen(str);
	if (!str || len == 0)
		return (false);
	nb_s_q = 0;
	nb_d_q = 0;
	while (i < len_str)
	{
		if (str[i] == S_QUOTE && ft_find_closing_quote(str, S_QUOTE, i) != -1)
		{
			i = ft_find_closing_quote(str, S_QUOTE, i);
			nb_s_q += 2;
		}
		if (str[i] == D_QUOTE && ft_find_closing_quote(str, D_QUOTE, i) != -1)
		{
			i = ft_find_closing_quote(str, D_QUOTE, i);
			nb_d_q += 2;
		}
		i++;
	}
}
