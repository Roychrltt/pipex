/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:36:14 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/25 12:43:52 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	perror_message(char *error)
{
	perror(error);
	exit(EXIT_FAILURE);
}

int	open_file(char *file, int n)
{
	int	fd;

	fd = -1;
	if (n == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			perror_message("Infile open failure");
	}
	if (n == 1)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (fd == -1)
			perror_message("Outfile open failure");
	}
	if (n == 2)
	{
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR);
		if (fd == -1)
			perror_message("Outfile open failure");
	}
	if (n == 3)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
		{
			unlink(".here_doc.tmp");
			perror_message(".here_doc.tmp file open failure");
		}
	}
	return (fd);
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
