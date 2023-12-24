/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quoting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 16:59:24 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/24 17:14:22 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* returns the quoting char, or NULL if no quotes has been found */
char	ft_quoting_char(char *str)
{
	int		i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && !ft_char_in_base(str[i], BASE_QUOTES))
		i++;
	if (ft_char_in_base(str[i], BASE_QUOTES))
		return (str[i]);
	else
		return (NULL);
}

/* ft_quoting_char is only ran if str exists, so if it returns NULL it means
 no quoting char but is still valid*/
bool	ft_even_nb_quotes(char *str)
{
	char	quote_char;

	if (!str)
		return (false);
	quote_char = ft_quoting_char(str);
	if (!quote_char)
		return (true);
	if (ft_strocc(str, quote_char) % 2 != 0)
		return (false);
	else
		return (true);
}
