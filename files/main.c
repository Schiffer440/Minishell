/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:35:48 by adugain           #+#    #+#             */
/*   Updated: 2023/12/25 13:09:54 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	visualizer(t_parse *parse)
{
	int	i;
	int	j;
	t_cmd	*tmp;
	
	tmp = parse->cmds;
	i = 0;
	j = 0;
	while(parse->cmds)
	{
		P("cmd:");
		if (parse->cmds->cmd)
			P(parse->cmds->cmd);
		else
			P("N/A");
		P("cmd_w_arg");
		if (parse->cmds->cmd_w_arg)
		{
			j = 0;
			while (parse->cmds->cmd_w_arg[j])
			{
				P(parse->cmds->cmd_w_arg[j]);
				j++;
			}
		}
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
	P("---- command number ");
	Pint(i);
}

/* COMMENTS : data->input is safe (not causing leaks) */
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
		visualizer(parse);
		// visualizer_prev(parse);
		check_builtin(data, parse);
		endloop(data, parse);
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
