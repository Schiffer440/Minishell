/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:28:48 by adugain           #+#    #+#             */
/*   Updated: 2023/11/08 12:24:35 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	end_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		free(data->env[i]);
		i++;
	}
	free(data->env);
}

void	endloop(t_data *data)
{
	free(data->input);
	free(data->prompt);
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
