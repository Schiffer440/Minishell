/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:15:03 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/17 18:42:26 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

/* NOT TESTED */
void	ft_env_update(t_env *envi, char *tag_, char *cont)
{
	if (!envi || !tag_)
		return ;
	while (envi->node_)
	{
		if (!ft_strncmp(envi->node_->n_tag, tag_, \
		ft_strlen(envi->node_->n_tag)))
		{
			free(envi->node_->n_content);
			envi->node_->n_content = ft_strdup(cont);
			if (!envi->node_->n_content)
			{
				printf("Update envi node failed !\n");
				/* ft_free_all(envi); */
			}
			break ;
		}
		envi->node_ = envi->node_->next;
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
