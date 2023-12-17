/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_limiters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:59:44 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/17 14:00:22 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_strdup_limiters(char *str, int from, int until)
{
	char		*dup;
	int			len;
	int			i;

	if (until > (int) ft_strlen(str) || from >= until || from < 0 || until < 0)
	{
		return (0);
	}
	len = until - from;
	i = 0;
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (0);
	while (str[from + i] != '\0' && (from + i < until))
	{
		dup[i] = str[from + i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
