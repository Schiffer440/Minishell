/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:35:48 by adugain           #+#    #+#             */
/*   Updated: 2023/12/21 17:43:36 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	visualizer(t_parse *parse)
{
	int	i;
	t_cmd	*tmp;
	
	tmp = parse->cmds;
	i = 0;
	while(parse->cmds)
	{
		P("cmd:");
		if (parse->cmds->cmd)
			P(parse->cmds->cmd);
		else
			P("N/A");
		P("cmd_w_arg");
		if (parse->cmds->cmd_w_arg)
			P(parse->cmds->cmd_w_arg);
		else
			P("N/A");
		P("prev_token");
		Pint(parse->cmds->prev_token);
		P("next_token");
		Pint(parse->cmds->next_token);
		parse->cmds = parse->cmds->next;
		i++;
	}
	parse->cmds = tmp;
	Pint(i);
}

// void	visualizer_prev(t_parse *parse)
// {
// 	int	i;
	
// 	i = 0;
// 	while(parse->cmds->next)
// 	{
// 		P("---------------------------------------------------");
// 		P("prev cmd:");
// 		if (parse->cmds->previous->cmd)
// 			P(parse->cmds->previous->cmd);
// 		else
// 			P("N/A");
// 		P("prev cmd_w_arg");
// 		if (parse->cmds->previous->cmd_w_arg)
// 			P(parse->cmds->previous->cmd_w_arg);
// 		else
// 			P("N/A");
// 		P("prev prev_token");
// 		Pint(parse->cmds->previous->prev_token);
// 		P("prev next_token");
// 		Pint(parse->cmds->previous->next_token);
// 		parse->cmds = parse->cmds->next;
// 		i++;
// 	}
// 	Pint(i);
// }

void	process(t_data *data, t_parse *parse)
{
	while (1)
	{
		initloop(data);
		data->input = readline(data->prompt);
		add_history(data->input);
		/*Parsing*/
		/*ft nb de pipe */
		/*ft nb de redir*/
		// get_pipes(data, parse);
		get_lst_cmds(data, parse);
		// visualizer(parse);
		// visualizer_prev(parse);
		check_builtin(data, parse);
		endloop(data);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;
	t_parse parse;

	(void)ac;
	(void)av;
	init_all(&data, envp);
	process(&data, &parse);

}
