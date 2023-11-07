/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adugain <adugain@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 14:35:48 by adugain           #+#    #+#             */
/*   Updated: 2023/11/07 17:00:26 by adugain          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env(char **envp)
{
	char	**env;
	int	i;

	i = 0;
	while (envp[i])
	{
		i++;
	}
	env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envp[i])
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	return (env);
}

static char	**get_paths(t_data *data)
{
	int		i;
	char	**mypath;

	i = 0;
	while (data->env[i])
	{
		if (ft_strncmp(data->env[i], "PATH", 4) == 0)
			break ;
		else
			i++;
	}
	data->env[i] += 5;
	mypath = ft_split(data->env[i], ':');
	return (mypath);
}

static void	free_token(char *s1, char *s2, int token)
{
	if (token == 1)
		free(s1);
	if (token == 2)
		free(s2);
	if (token == 3)
	{
		free(s1);
		free(s2);
	}
}

char	*ft_strjoin_pipex(char *s1, char *s2, int token)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!s1 || !s2)
		return (0);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	free_token(s1, s2, token);
	return (str);
}


static char	*get_exec(char **paths, char **cl_cmd)
{
	char	*exec;
	char	*cl_path;
	int		i;

	i = 0;
	while (paths[i])
	{
		cl_path = ft_strjoin_pipex(paths[i], "/", 0);
		exec = ft_strjoin_pipex(cl_path, cl_cmd[0], 1);
		if (access(exec, F_OK | X_OK) == 0)
			break ;
		else
		{
			free(exec);
			exec = NULL;
			i++;
		}
	}
	return (exec);
}

void	endloop(t_data *data)
{
	free(data->input);
	free(data->prompt);
}

void	initloop(t_data *data)
{
	getcwd(data->cwd, sizeof(data->cwd));
	data->prompt = ft_strjoin(data->cwd, "->");
}

void	ft_exec(t_data *data)
{
	int	pid;
	char	**path;
	char	*exec;

	pid = fork();
	if (pid == -1)
		P("Erreur a gerer + free");
	if (pid == 0)
	{
		path = get_paths(data);
		exec = get_exec(path, ft_split(data->input, ' '));
		P(exec);
		if (execve(exec, ft_split(data->input, ' '), data->env) == -1)
		{
			ft_free_tab_c(path);
			free(exec);
			exit(0);
		}
	}
	wait(NULL);
}

void	process(t_data *data)
{
	while (1)
	{
		initloop(data);
		data->input = readline(data->prompt);
		add_history(data->input);
		ft_exec(data);
		endloop(data);
	}
}

void	init_all(t_data *data, char **envp)
{
	data->env = get_env(envp);
	data->input = 0;
	data->prompt = 0;
}

void	end_all(t_data *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		free(data->env[i]);
		i++;
	}
	free(data->env);
	exit(0);
}

int	main(int ac, char **av, char **envp)
{
	t_data data;
	(void)ac;
	(void)av;
	init_all(&data, envp);
	process(&data);

}
