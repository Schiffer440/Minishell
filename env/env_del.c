/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_del.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:51:46 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/18 14:22:00 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_env_node	*ft_find_prev_node(t_env_node **envi, char *tag_)
{
	t_env_node	*ret;

	if (!envi || !*envi)
		return (NULL);
	ret = *envi;
	while (ret->next)
	{
		if (!ft_strncmp(ret->next->n_tag, tag_, ft_strlen(ret->next->n_tag)))
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}

t_env_node	*ft_find_node(t_env_node **envi, char *tag_)
{
	t_env_node	*ret;

	if (!envi || !*envi)
		return (NULL);
	ret = *envi;
	while (ret)
	{
		if (!ft_strncmp(ret->n_tag, tag_, ft_strlen(ret->n_tag)))
			return (ret);
		ret = ret->next;
	}
	return (NULL);
}

/* check if : not finding, only 1 node (check if leak looking for it)
void	ft_env_del_elem(t_env_node *envi, char *tag_)
{
	t_env_node	*prev;
	t_env_node	*curr;
	t_env_node	*next_next;

	if(!envi || !*envi)
		return;
	prev = ft_find_prev_node(*envi, tag_);
//only one node, doit free tout le tableau dans ce cas ? plutot mettre un vide ?	
	if (!prev)
	{
		ft_free_node(envi);
		return ;
	}
	curr = prev->next;
//si le node a delete est le dernier	
	if (!curr->next)
	{
		ft_free_node(curr);
		prev->next = NULL;
		return ;
	}
	else
	{
		prev->next = curr->next;
		ft_free_node(curr);
		return ;
	}
	
}
*/

void	ft_free_node(t_env_node *curr)
{
	free(curr->n_tag);
	free(curr->n_content);
	free(curr);
}

void	ft_env_free(t_env_node *envi)
{
	t_env_node	*curr;

	while (envi)
	{
		curr = envi;
		envi = envi->next;
		ft_free_node(curr);
	}
}
