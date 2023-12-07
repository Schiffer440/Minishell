/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:33:23 by adugain           #+#    #+#             */
/*   Updated: 2023/12/07 16:08:01 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_target(t_data *data, char **tmp, int j, int i)
{
	if (tmp[j])
	{
		data->cmd[i].target = ft_strdup(tmp[j]);
		j++;
		while(tmp[j])
		{
			data->cmd[i].target = ft_strjoin_Mshell(data->cmd[i].target, \
				tmp[j], 2);
			j++;
		}
	}
	else
		data->cmd[i].target = NULL;
}

void	get_cmds(t_data *data, char **cmds, int	pipes)
{
	int	i;
	int	j;
	int	k;
	char	**tmp;
	
	i = 0;
	data->cmd = malloc(sizeof(t_cmd) * pipes);
	while(i < pipes)
	{
		j = 1;
		k = 0;
		tmp = ft_split(cmds[i], ' ');
		while (tmp[j])
		{
			if (tmp[j][0] == '-')
				j++;
			else
				break ;
		}
		data->cmd[i].cl_cmd = malloc(sizeof(char *) * j + 1);
		get_target(data, tmp, j, i);
		while (k <= j)
		{
			P(tmp[k]);
			data->cmd[i].cl_cmd[k] = ft_strdup(tmp[k]);
			k++;
		}
		ft_free_tab_c(tmp);
		i++;
	}
}

void	get_pipes(t_data *data)
{
	char **part;
	int	pipes;
	
	pipes = 0;
	part = ft_split(data->input, '|');
	while (part[pipes])
	{
		pipes++;
	}
	get_cmds(data, part, pipes);
}