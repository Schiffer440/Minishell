/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:41:40 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/23 16:00:32 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* Need to malloc protec ft_create_node and ft_add_envi_node */
t_env	*ft_init_envi(char **envp)
{
	int			i;
	t_env		*struct_env;
	t_env_node	*ret;
	t_env_node	*buff;

	if (!envp || !*envp)
		return (NULL);
	struct_env = malloc(sizeof(*struct_env));
	if (!struct_env)
		return (NULL);
	struct_env->env = envp;
	ret = NULL;
	i = 0;
	while (envp[i])
	{
		buff = ft_create_node(envp[i], NULL, NULL);
		if (!ret)
			ret = buff;
		else
			ft_add_envi_node(&ret, buff);
		i++;
	}
	struct_env->node_ = ret;
	return (struct_env);
}

/* tested : OK*/
t_env_node	*ft_go_to_last(t_env_node *env_node)
{
	while (env_node)
	{
		if (!env_node->next)
			return (env_node);
		env_node = env_node->next;
	}
	return (NULL);
}

/* adds at the end */
/* tested : OK */
void	ft_add_envi_node(t_env_node **src, t_env_node *to_add)
{
	t_env_node	*end;

	if (!src)
	{
		*src = to_add;
		return ;
	}
	end = ft_go_to_last(*src);
	end->next = to_add;
}

/* tested : OK */
/* needs to me modified so it takes tag and content sep */
/* si ft_get_tag_or_cont renvoie null, quel cas ? arreter ?*/
t_env_node	*ft_create_node(char *content_, char *tag_, char *cont)
{
	t_env_node	*new;

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);
	if (!tag_ || !cont)
	{
		new->n_tag = ft_get_tag_or_cont(content_, 't');
		new->n_content = ft_get_tag_or_cont(content_, 'c');
	}
	if (!content_ && tag_ && cont)
	{
		new->n_tag = ft_strdup(tag_);
		new->n_content = ft_strdup(cont);
	}
//	if (!new->n_tag || !new->n_content)
//		print error;
	new->next = NULL;
	return (new);
}

/*
int	main(int argc, char **argv, char **envp)
{
	t_env	*ret;

	ret = ft_init_envi(envp);
	if (!argc || !argv || !ret)
		printf("oopsie\n");
	if (argc == 3)
		ft_env_update(ret->node_, argv[1], argv[2]);
	ft_env_display(&ret->node_);
	ft_env_free(ret->node_);
	free(ret);
	return (0);
}
*/
/*
void	ft_init_no_envi(t_env *envi)
{
	//si no env ici, est-ce qu'une liste chainee ne serait pas mieux justeeeeee
}
*/
