/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:36:50 by adugain           #+#    #+#             */
/*   Updated: 2023/12/21 22:13:01 by mbruyant         ###   ########.fr       */
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
static int	get_cmd_n_args(t_parse *parse, char **tmp, int i, int token)
{
	if (token == 0)
	{
		parse->cmds->cmd = ft_strdup(tmp[i]);
		i++;
	}
	while (tmp[i] && ft_strncmp(tmp[i], "-", 1) == 0)
	{
		parse->cmds->cmd = ft_strjoin_Mshell(parse->cmds->cmd, " ", 1);
		parse->cmds->cmd = ft_strjoin_Mshell(parse->cmds->cmd, tmp[i], 1);
		i++;
	}
	/*supprime l'assignement dans la condition de boucle
	et il y avait une parenthese en trop */
	while (tmp[i] && check_token(tmp[i]) == 0)
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

/* j'ai change ton split avec le miens pour voir si ca changeait qqch 
j'ai laisse pour double protec au cas de str vide */
/* ici j'ai ajoute visualizer par rapport a ce que tu avais ajoute */
void	get_lst_cmds(t_data *data, t_parse *parse)
{
	char	**tmp;
	int		i;
	int		token;
	t_cmd	*tmp_cmd;

	i  = 0;
	token = 0;
	tmp = ft_split(data->input, ' ');
	if (!tmp)
		return ;
	parse->cmds = create_lst_cmd();
	tmp_cmd = parse->cmds;
	while (tmp[i])
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
	visualizer(parse);
	ft_free_tab_c(tmp);
	// ft_memcpy(parse->cmds, tmp_cmd, sizeof(tmp_cmd));
	parse->cmds = tmp_cmd;
}
