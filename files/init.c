/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:27:28 by adugain           #+#    #+#             */
/*   Updated: 2023/12/21 17:42:39 by adugain          ###   ########.fr       */
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
	data->cwd = malloc(((size_t)PATH_MAX) * 2);
	if (!data->cwd)
		perror("cwd buffer");
	data->input = 0;
	data->prompt = 0;
}

void	initloop(t_data *data)
{	
	if (getcwd(data->cwd, (size_t)PATH_MAX) != NULL)
	{
		data->prompt = ft_strjoin(data->cwd, "->");
	}
	else
		perror("getcwd");
}