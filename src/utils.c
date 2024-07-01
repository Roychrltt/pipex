/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roychrltt <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:21:59 by roychrltt         #+#    #+#             */
/*   Updated: 2024/07/01 17:11:42 by xiaxu            ###   ########.fr       */
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

char	*ft_getenv(char **envp)
{
	int		i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
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
		if (access(command, 1) == 0)
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
