/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:39:57 by adugain           #+#    #+#             */
/*   Updated: 2023/11/08 15:16:00 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*a;

	a = 0;
	a = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!a)
		return (NULL);
	else
		ft_strcpy(a, src);
	return (a);
}
