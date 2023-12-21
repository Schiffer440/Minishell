/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:36:50 by adugain           #+#    #+#             */
/*   Updated: 2023/12/21 17:40:43 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*create_lst_cmd()
{
	t_cmd	*n_cmd;
	
	n_cmd = malloc(sizeof(t_cmd));
	if (!n_cmd)
		P("cmds alloc err");
	n_cmd->cmd = 0;
	n_cmd->cmd_w_arg = 0;
	n_cmd->next = NULL;
	// n_cmd->previous = NULL;
	n_cmd->prev_token = 0;
	n_cmd->next_token = 0;
	return (n_cmd);
}

static int	check_token(char *str)
{
	if (ft_strncmp(str, "<", sizeof(str)) == 0)
		return (1);
	if (ft_strncmp(str, ">", sizeof(str)) == 0)
		return (2);
	if (ft_strncmp(str, "<<", sizeof(str)) == 0)
		return (3);
	if (ft_strncmp(str, ">>", sizeof(str)) == 0)
		return (4);
	if (ft_strncmp(str, "|", sizeof(str)) == 0)
		return (5);
	if (ft_strncmp(str, "$", sizeof(str)) == 0)
		return (6);
	if (ft_strncmp(str, "?", sizeof(str)) == 0)
		return (7);
	return (0);
}

static int	get_cmd_n_args(t_parse *parse, char **tmp, int i, int token)
{
	if (token == 0)
	{
		parse->cmds->cmd = ft_strdup(tmp[i]);
		i++;
	}
	while (tmp[i] && strncmp(tmp[i], "-", 1) == 0)
	{
		parse->cmds->cmd = ft_strjoin_Mshell(parse->cmds->cmd, " ", 1);
		parse->cmds->cmd = ft_strjoin_Mshell(parse->cmds->cmd, tmp[i], 1);
		i++;
	}
	while (tmp[i] && (token = check_token(tmp[i])) == 0)
	{
		parse->cmds->cmd_w_arg = ft_strjoin_Mshell(parse->cmds->cmd, " ", 0);
		parse->cmds->cmd_w_arg = ft_strjoin_Mshell(parse->cmds->cmd_w_arg, tmp[i], 1);
		i++;
	}
	return (i);
}

static int	next_cmd(t_parse *parse, int i, int token)
{
	if (token != 0)
	{
		parse->cmds->next = create_lst_cmd();
		parse->cmds->next_token = token;
		parse->cmds->next->prev_token = token;
		parse->cmds = parse->cmds->next;
		i++;
	}
	return (i);
}

void	get_lst_cmds(t_data *data, t_parse *parse)
{
	char 	**tmp;
	int	i;
	int	token;
	t_cmd	*tmp_cmd;

	i  = 0;
	token = 0;
	tmp = ft_split(data->input, ' ');
	if (!tmp)
		return ;
	parse->cmds = create_lst_cmd();
	tmp_cmd = parse->cmds;
	while(tmp[i])
	{
		token = check_token(tmp[i]);
		if (token != 0 && i == 0)
		{
			parse->cmds->prev_token = token;
			token = 0;
			i++;
		}
		i = get_cmd_n_args(parse, tmp, i, token);
		i = next_cmd(parse, i, token);
	}
	ft_free_tab_c(tmp);
	// ft_memcpy(parse->cmds, tmp_cmd, sizeof(tmp_cmd));
	parse->cmds = tmp_cmd;
}