/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:27:28 by adugain           #+#    #+#             */
/*   Updated: 2023/12/14 18:56:15 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**get_env(char **envp)
{
	int		i;
	char	**env;

	i = 0;
	while (envp[i])
	{
		i++;
	}
	env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}

void	init_all(t_data *data, char **envp)
{
	data->env = get_env(envp);
	data->input = 0;
	data->prompt = 0;
	data->pipes = 0;
}

// void	initloop_cmd(t_data *data)
// {
// }

void	initloop(t_data *data)
{
	getcwd(data->cwd, sizeof(data->cwd));
	data->prompt = ft_strjoin(data->cwd, "->");
}
