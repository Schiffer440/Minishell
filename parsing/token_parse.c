/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:15:41 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/25 22:04:21 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	ft_is_valid_token(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 2 || len == 0)
		return (false);
	if (len == 1)
		return (ft_char_in_base(*str, BASE_TOKEN));
	if (str[0] != str[1] || !ft_strbase(str, BASE_TOKEN))
		return (false);
	return (true);
}

/* if all are valids, return nb of it, if not returns 0
NOTE : DOIT AFFICHER MESSAGE D'ERREUR ICI */
int	ft_get_valid_token_nb(char **token_arr)
{
	int	i;
	int	nb;

	if (!token_arr || *token_arr == '\0')
		return (0);
	i = 0;
	nb = 0;
	while (token_arr[i])
	{
		if (!ft_is_valid_token(token_arr[i]))
			return (0);
		if (ft_is_valid_token(token_arr[i]))
			nb++;
		i++;
	}
	return (nb);
}

t_cmd	*ft_fill_struct(char *str)
{

}
