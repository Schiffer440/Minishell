/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_misc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 13:48:46 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/23 16:20:45 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strendswith(char *str, char *end)
{
	int	str_len;
	int	end_len;
	int	i;

	str_len = ft_strlen(str);
	end_len = ft_strlen(end);
	i = 0;
	while (str[str_len - end_len + i])
	{
		if (str[str_len - end_len + i] != end[i])
			return (0);
		i++;
	}
	return (1);
}

/* check if the str is only filled w sep char, used to prot splits var */
int	ft_str_only_sep(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != sep)
			return (0);
		i++;
	}
	return (1);
}
