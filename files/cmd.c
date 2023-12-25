/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:36:50 by adugain           #+#    #+#             */
/*   Updated: 2023/12/25 13:13:26 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_cmd	*create_lst_cmd(void)
{
	t_cmd	*n_cmd;

	n_cmd = malloc(sizeof(*n_cmd));
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

/* Note pour Marianne : ajouter condition de parse apres ici pour handle les quotes */
static int	get_cmd_n_args(t_parse *parse, int i, int token)
{
	int	save;
	
	save = 0;
	if (token == 0)
	{
		save = i;
		parse->cmds->cmd = ft_strdup(parse->arr_input[i]);
		i++;
		while (parse->arr_input[i] && strncmp(parse->arr_input[i], "-", 1) == 0)
		{
			parse->cmds->cmd = ft_strjoin_Mshell(parse->cmds->cmd, parse->arr_input[i], 1);
			i++;
		}
		while (parse->arr_input[i] && (token = check_token(parse->arr_input[i])) == 0)
			i++;
		parse->cmds->cmd_w_arg = ft_copy_2d_array(parse->arr_input, save, i);
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

/*Leak réparé tu peux test echo lol puis exit ou cmd x | ... | exit ça foncitonne 
dis moi si tu trouve une erreur*/
void	get_lst_cmds(t_data *data, t_parse *parse)
{
	int	i;
	int	token;

	i  = 0;
	token = 0;
	parse->arr_input = ft_split(data->input, ' ');
	if (!parse->arr_input)
		return ;
	parse->cmds = create_lst_cmd();
	parse->tmp_cmd = parse->cmds;
	while(parse->arr_input[i])
	{
		token = check_token(parse->arr_input[i]);
		if (token != 0 && i == 0)
		{
			parse->cmds->prev_token = token;
			token = 0;
			i++;
		}
		i = get_cmd_n_args(parse, i, token);
		i = next_cmd(parse, i, token);
	}
	ft_free_tab_c(parse->arr_input);
	parse->cmds = parse->tmp_cmd;
}