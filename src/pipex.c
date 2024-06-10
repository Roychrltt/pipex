/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:28:31 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/10 10:03:34 by roychrltt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int *fd_tab)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)

}

int	main(int argc, char **argv, char **envp)
{
	int		fd_tab[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_putstr_fd("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd_tab) == -1)
	{
		perror("pipe");
		exit(EXIT_FAILURE);
	}
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		child(argv, fd_tab, envp);
	parent(argv, fd_tab, envp);
}
