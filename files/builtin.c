/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:15:21 by adugain           #+#    #+#             */
/*   Updated: 2023/12/14 18:52:43 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// static void	ft_echo(t_data *data)
// {
// 	char	**str;
// 	char	*n_str;
// 	int		i;

// 	i = 1;
// 	n_str = 0;
// 	if (strncmp(data->input, "echo", 4) == 0)
// 	{
// 		str = ft_split(data->input, ' ');
// 		if (str[1])
// 		{
// 			if(!ft_strncmp(str[1], "-n", 3))
// 			{
// 				n_str = ft_strdup(str[i]);
// 				while (str[++i] && ft_strncmp(str[i], "|", 2))
// 					n_str = ft_strjoin_Mshell(n_str, str[i], 1);
// 				ft_free_tab_c(str);
// 				printf("%s", n_str);
// 			}
// 			else
// 			{
// 			n_str = ft_strdup(str[i]);
// 			while (str[++i] && ft_strncmp(str[i], "|", 2))
// 				n_str = ft_strjoin_Mshell(n_str, str[i], 1);
// 				ft_free_tab_c(str);
// 				P(n_str);
// 			}
// 			free(n_str);
// 		}
// 	}
// }

static void	exit_shell(t_data *data)
{
	char **tab;

	tab = ft_split(data->input, ' '); 
	if (/*data->cmd->pipe == 0 &&*/(ft_strncmp(tab[0], "exit", sizeof(tab[0])) == 0))
	{
		write(1, "exit\n", 5);
		ft_free_tab_c(tab);
		endloop(data);
		end_all(data);
		exit(0);
	}
}

void	builtin(t_data *data)
{
	char **path;

	path = ft_split("/usr/bin", ' ');
	exit_shell(data);
	ft_echo(data, path);
}