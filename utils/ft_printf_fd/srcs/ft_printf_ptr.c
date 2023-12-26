/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 12:22:47 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/26 12:24:16 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf_fd.h"

static void	ft_print_hex_ptr(unsigned long long int nb, int fd)
{
	if (nb <= 9)
		ft_putchar_fd((nb + '0'), fd);
	if (nb >= 10 && nb < 16)
	{
		ft_putchar_fd((nb - 10 + 'a'), fd);
	}
}

static void	ft_print_hex_recurs(unsigned long long int nb, int fd)
{
	if (nb >= 16)
		ft_print_hex_recurs(nb / 16, fd);
	ft_print_hex_ptr(nb % 16, fd);
}

static int	ft_hex_len_ptr(unsigned long long int nb)
{
	long long int	len;

	len = 0;
	while (nb != 0)
	{
		nb = nb / 16;
		len++;
	}
	return (len);
}

int	ft_printf_ptr(unsigned long long int ptr, int fd)
{
	int	len;
	int	compile_error_fix;

	len = 2;
	if (ptr == 0)
	{
		ft_putstr_fd("(nil)", fd);
		return (5);
	}
	compile_error_fix = write(fd, "0x", 2);
	if (compile_error_fix == -1)
		ft_putstr_fd("ft_printf_ptr error\n", 2);
	ft_print_hex_recurs(ptr, fd);
	len += ft_hex_len_ptr(ptr);
	return (len);
}
