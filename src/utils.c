/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roychrltt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:21:59 by roychrltt         #+#    #+#             */
/*   Updated: 2024/06/11 15:18:02 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "../libft/libft.h"

void	perror_message(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

void	error_message(char *error)
{
	write(2, error, ft_strlen(error));
	exit(EXIT_FAILURE);
}

char	*ft_getenv(char *path, char **envp)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		s = ft_substr(envp[i], 0, j);
		if (!s)
			return (NULL);
		if (ft_strncmp(s, path, j) == 0)
		{
			free(s);
			return (envp[i] + j + 1);
		}
		free(s);
		i++;
	}
	return (NULL);
}

char	*get_command(char *path, char *cmd)
{
	char	**paths;
	int		i;
	char	*try;
	char	*command;

	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		try = ft_strjoin(paths[i], "/");
		command = ft_strjoin(try, cmd);
		free(try);
		if (access(command, 0) == 0)
			return (command);
		free(command);
		i++;
	}
	return (NULL);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
