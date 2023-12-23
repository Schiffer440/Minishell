/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_env_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 16:59:48 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/23 17:13:44 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	main(int argc, char **argv)
{
	char *env_ex[] = {
		"USER=marianne",
		"TEST=coucou",
		NULL
	};
	t_env	*myEnv = ft_init_envi(env_ex);
	if (myEnv && argc >= 2)
	{
		printf("Initial Environment:\n");
 		ft_env_display(&(myEnv->node_));
		printf("\n");
		ft_env_del_elem(myEnv->node_, argv[1]);
		printf("Updated Environment:\n");
		ft_env_display(&(myEnv->node_));
		printf("\n");
		ft_env_free(myEnv->node_);
		free(myEnv);		
	}
}
