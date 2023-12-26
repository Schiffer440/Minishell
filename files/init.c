/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:27:28 by adugain           #+#    #+#             */
/*   Updated: 2023/12/26 14:17:06 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
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
*/

int	init_all(t_data *data, char **envp)
{
	data->env_struct = ft_init_envi(envp);
	if (!data->env_struct)
	{
		ft_msg_end("env init fail (init_all fct)", 'm', false, NULL);
		return (1);
	}
	data->cwd = malloc(((size_t)PATH_MAX) * 2);
	if (!data->cwd)
	{
		ft_msg_end("cwd init fail (init_all fct)", 'm', false, NULL);
		ft_env_free(data->env_struct->node_);
		return (1);
	}
	data->input = 0;
	data->prompt = 0;
	return (0);
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