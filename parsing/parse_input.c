/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:45:08 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/26 18:44:10 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/*
int	ft_parse_cmds_vs_tokens(int nb_tokens, int nb_cmds)
{
	if (nb_tokens == -1)
		return (R_EX_OK);
	if (nb_tokens > 0 && nb_tokens != nb_cmds - 1)
}
*/
/* retourne un code erreur ou non, si !ft_parse_input, correct 
init dans t_parse arr_token et arr_cmds */
int	ft_parse_input(char *str, t_parse *ms)
{
	char	**arr_token;
	char	**arr_cmds;
	int		nb_tokens;

	arr_token = ft_split_unbase(str, BASE_TOKEN);
	ar_cmds = ft_split_base(str, BASE_TOKEN);
	if (!arr_token || !arr_cmds)
	{
		ft_printf_fd(2, "malloc error ft_parse_input\n");
		return (R_ERR_GEN);
	}
	nb_tokens = ft_get_valid_token_nb(arr_token, str);
	if (!nb_tokens)
	{
//		ft_free_prompt_data(ms);
		return (R_ERR_SH_B);
	}
	ms->arr_token = ft_copy_2d_array(arr_token);
	ms->arr_cmds = ft_copy_2d_array(arr_cmds);
	ms->token_nb = nb_tokens;
	ft_free_2d_array(arr_token);
	ft_free_2d_array(ar_cmds);
//	ft_parse_cmds_vs_tokens(nb_tokens);
	return (R_EX_OK);
}

t_cmd	*ft_go_to_last_cmd_node(t_cmd *cmd_node)
{
	while (cmd_node)
	{
		if (!cmd_node->next)
			return (cmd_node);
		cmd_node = cmd_node->next;
	}
	return (NULL);
}

t_cmd	*ft_fill_cmd_struct(t_parse *ms)
{
	int		i;
	t_cmd	*struct_cmd;
	t_cmd	*buff;

	i = 0;
	struct_cmd = malloc(sizeof(*struct_cmd));
	if (!struct_cmd)
		return (NULL);
	buff = NULL;
	
}

t_cmd	*ft_create_cmd_node(t_parse *ms, int i)
{
	t_cmd	*ret;

	if (!ms)
		return (NULL);
	ret = malloc(sizeof(*ret));
	if (!ret)
		return (NULL);
	if (i == 0)
		ret->previous = NULL;
	if (i > 0)
	{
		ret->previous = ft_go_to_last_cmd_node(ms->cmd);
		ret->previous->next = ret;
	}
	ret->next = NULL;
	ret->cmd_w_arg =
}
