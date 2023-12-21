/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:28:48 by adugain           #+#    #+#             */
/*   Updated: 2023/12/21 17:41:43 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_all(t_parse *parse)
{
	t_cmd	*current_cmd;
	t_cmd	*next_cmd;

	current_cmd = parse->cmds;
	while (current_cmd)
	{
		next_cmd = current_cmd->next;
		free(current_cmd->cmd);
		free(current_cmd->cmd_w_arg);
		free(current_cmd);
		current_cmd = next_cmd;
	}
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
	free_all(parse);
}

void	endloop(t_data *data)
{
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
