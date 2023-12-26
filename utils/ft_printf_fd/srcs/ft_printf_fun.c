/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fun.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 17:57:32 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/26 12:25:18 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_fd.h"

int	ft_printf_str(char *str, int fd)
{
	int	i;
	int	compile_error_fix;

	i = 0;
	if (!str)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	while (str[i] != '\0')
	{
		compile_error_fix = write(fd, &str[i], 1);
		if (compile_error_fix == -1)
			return (0);
		i++;
	}
	return (i);
}

int	ft_printf_char(int c, int fd)
{
	int	compile_error_fix;

	compile_error_fix = write(fd, &c, 1);
	if (compile_error_fix != -1)
		return (1);
	else
	{
		ft_putstr_fd("ft_printf_str error\n", 2);
		return (0);
	}
}
