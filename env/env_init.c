/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:41:40 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/16 20:49:41 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_init_env(char **envp, t_env *env)
{
	if (!envp || !*envp)
		return ;
	env->env = ft_copy_2d_array(envp, 0, ft_len_2d_array(envp));
	if (!env->env)
	{
		ft_putendl_fd("ft_init_env fail", 2);
		return ;
	}
}
void	ft_init_no_env(t_env *env)
{
	//si no env ici, est-ce qu'une liste chainee ne serait pas mieux justeeeeee
}
