/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbruyant <mbruyant@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 21:48:55 by mbruyant          #+#    #+#             */
/*   Updated: 2023/12/25 21:11:40 by mbruyant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FD_H
# define FT_PRINTF_FD_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf_fd(int fd, const char *str, ...);
int		ft_printf_hex(unsigned int nb, const char type, int fd);
int		ft_printf_char(int c, int fd);
int		ft_printf_str(char *str, int fd);
int		ft_printf_uns(unsigned int nb, int fd);
int		ft_printf_ptr(unsigned long long int ptr, int fd);
int		ft_printf_nb(long int nb, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);

#endif
