/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:28:48 by adugain           #+#    #+#             */
/*   Updated: 2023/12/25 13:04:15 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_parse *parse)
{
	t_cmd	*buff;
	
	buff = NULL;
	parse->cmds = parse->tmp_cmd;
	while (parse->cmds)
	{
		buff = parse->cmds;
		parse->cmds =parse->cmds->next;
		free(buff->cmd);
		ft_free_2d_array(buff->cmd_w_arg);
	}
	free(buff);
}

void	end_all(t_data *data, t_parse *parse)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		free(data->env[i]);
		i++;
	}
	free(data->env);
	free(data->cwd);
	endloop(data, parse);
}

void	endloop(t_data *data, t_parse *parse)
{
	free_all(parse);
	free(data->prompt);
	free(data->input);
}

void	free_token(char *s1, char *s2, int token)
{
	if (token == 1)
		free(s1);
	if (token == 2)
		free(s2);
	if (token == 3)
	{
		free(s1);
		free(s2);
	}
}
