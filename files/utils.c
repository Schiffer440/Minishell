/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:33:23 by adugain           #+#    #+#             */
/*   Updated: 2023/12/14 18:55:27 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_cmd_struc(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->pipes)
	{
		ft_free_tab_c(data->cmd[i].exec);
		i++;
	}
	free(data->cmd);
}

void	get_cmds(t_data *data, char **cmds, int	pipes)
{
	int		i;
	int		j;
	char	**tmp;

	i = 0;
	Pint(pipes);
	/*leak ici apparemment lorsque l'on entre au moins une cmd avant d'exit*/
	data->cmd = malloc(sizeof(t_cmd) * pipes + 1);
	while (i < pipes)
	{
		j = 0;
		tmp = ft_split(cmds[i], ' ');
		while (tmp[j])
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
		data->cmd[i].exec[j] = '\0';
		ft_free_tab_c(tmp);
		i++;
	}
	// free(data->cmd);
	ft_free_tab_c(cmds);
}

void	get_pipes(t_data *data)
{
	char	**cmds;

	cmds = ft_split(data->input, '|');
	while (cmds[data->pipes])
	{
		data->pipes++;
	}
	get_cmds(data, cmds, data->pipes);
}