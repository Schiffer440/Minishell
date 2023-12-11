/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:35:48 by adugain           #+#    #+#             */
/*   Updated: 2023/12/11 16:36:49 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	visualizer(t_data *data)
{
	int	i;
	
	i = 0;
	while(i < data->pipes)
	{
		if (data->cmd[i].exec[0])
			P(data->cmd[i].exec[0]);
		i++;
	}
}

void	process(t_data *data)
{
	while (1)
	{
		initloop(data);
		data->input = readline(data->prompt);
		add_history(data->input);
		/*Parsing*/
		/*ft nb de pipe */
		/*ft nb de redir*/
		get_pipes(data);
		// visualizer(data);
		builtin(data);
		ft_exec(data);
		endloop(data);
	}
}

int	main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)ac;
	(void)av;
	init_all(&data, envp);
	process(&data);

}
