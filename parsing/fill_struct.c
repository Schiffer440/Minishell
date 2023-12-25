/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:15:41 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/24 23:34:42 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

bool	ft_is_token(char *str, char c)
{
	return (ft_char_in_base(c, BASE_TOKEN));
}

int	ft_get_valid_token_nb(char *str)
{
	int	correct_tokens;
	int	incorrect_tokens;
	int	buff;
	int	i;

	correct_tokens = 0;
	incorrect_tokens = 0;
	buff = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_token(str, str[i]))
		{
			buff++;
			i++;
		}

		i++;
	}
}

t_tokens	*ft_fill_token_tab(char *str)
{
	
}

t_cmd	*ft_fill_struct(char *str)
{

}