/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:59:03 by adugain           #+#    #+#             */
/*   Updated: 2023/11/07 16:28:16 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/libft.h"
# include <sys/types.h>



#define P(str) (printf("ll%s\n", str))

typedef struct s_data
{
	char	*input;
	char	cwd[PATH_MAX];
	char	*prompt;
	char	**env;
}t_data;

#endif 