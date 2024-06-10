/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:28:31 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/10 13:37:20 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_message("Infile open failure");
	dup2(fd[1], stdout);
	close(fd[0]);
	dup2(infile, stdin);
	execve(, , envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];

	if (argc != 5)
	{
		write (2, "Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 48);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
		error_message("Pipe");
	pid = fork();
	if (pid == -1)
		error_message("Fork");
	else if (pid == 0)
		child(argv, fd, envp);
	parent(argv, fd, envp);
}
