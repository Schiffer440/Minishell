/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:15:03 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/18 18:06:44 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* TESTED : WORKS don't seem to leak */
void	ft_env_update(t_env_node *envi, char *tag_, char *cont)
{
	if (!envi || !tag_)
		return ;
	if (!cont)
	{
		cont = ft_strdup("");
		if (!cont)
			return ;
	}
	/* ici */
	if (!ft_exists_in_env(envi, tag))
		return (ft_add_envi_node(*envi, ft_create_node()));
	while (envi)
	{
		if (!ft_strncmp(envi->n_tag, tag_, ft_strlen(envi->n_tag)))
		{
			free(envi->n_content);
			envi->n_content = ft_strdup(cont);
			if (!envi->n_content)
			{
				printf("Update envi node failed !\n");
				ft_env_free(envi);
			}
			break ;
		}
		envi = envi->next;
	}
}

/* tested : OK */
void	ft_env_display(t_env_node **envi)
{
	t_env_node	*curr;

	curr = *envi;
	while (curr)
	{
		printf("%s \t %s\n", curr->n_tag, curr->n_content);
		curr = curr->next;
	}
}
