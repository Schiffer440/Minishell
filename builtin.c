/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:15:21 by adugain           #+#    #+#             */
/*   Updated: 2023/11/08 15:34:47 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strjoin_echo(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 2);
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = ' ';
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

// static char	*ft_strdup_echo(char *src)
// {
// 	char	*a;

// 	a = 0;
// 	a = malloc(sizeof(char) * (ft_strlen(src) + 1));
// 	if (!a)
// 		return (NULL);
// 	else
// 		ft_strcpy(a, src);
// 	return (a);
// }


static void	ft_echo(t_data *data)
{
	char	**str;
	char	*n_str;
	int		i;

	i = 1;
	n_str = 0;
	if (strncmp(data->input, "echo", 4) == 0)
	{
		str = ft_split(data->input, ' ');
		n_str = ft_strdup(str[i]);
		while (str[++i] && ft_strncmp(str[i], "|", 2))
			n_str = ft_strjoin_echo(n_str, str[i]);
		ft_free_tab_c(str);
		P(n_str);
		free(n_str);
	}
}

static void	exit_shell(t_data *data)
{
	if (ft_strncmp(data->input, "exit", 4) == 0)
	{
		endloop(data);
		end_all(data);
		exit(0);
	}
}

void	builtin(t_data *data)
{
	ft_echo(data);
	exit_shell(data);
}