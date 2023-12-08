/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:33:23 by adugain           #+#    #+#             */
/*   Updated: 2023/12/08 23:59:22 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_cmds(t_data *data, char **cmds, int	pipes)
{
	int	i;
	int	j;
	char **tmp;
	
	i = 0;
	data->cmd = malloc(sizeof(t_cmd) * pipes);
	while(i < pipes)
	{
		j = 0;
		tmp = ft_split(cmds[i], ' ');
		while(tmp[j])
			j++;
		data->cmd[i].exec = malloc(sizeof(char *) * (j + 1));
		if (!data->cmd[i].exec)
		{
			P("malloc error");
			exit(0);
		}
		j = 0;
		while (tmp[j])
		{
			data->cmd[i].exec[j] = ft_strdup(tmp[j]);
			j++;
		}
		ft_free_tab_c(tmp);
		i++;
	}
}

void	get_pipes(t_data *data)
{
	char **cmds;
	int	pipes;
	
	pipes = 0;
	cmds = ft_split(data->input, '|');
	while (cmds[pipes])
	{
		pipes++;
	}
	get_cmds(data, cmds, pipes);
}