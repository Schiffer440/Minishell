/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:35:48 by adugain           #+#    #+#             */
/*   Updated: 2023/12/08 23:58:41 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	visualizer(t_data *data)
{
	int	i;
	
	i = 0;
	while(data->cmd[0].exec[i])
	{
		P(data->cmd[0].exec[i]);
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
		/*ft nb de pipe si il y en a*/
		/*Parsing*/
		get_pipes(data);
		// visualizer(data);
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
