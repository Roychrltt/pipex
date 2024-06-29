/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:28:31 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/29 22:39:45 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1(char **argv, char **envp, int *fd, int infile)
{
	char	*path;
	char	*command;
	char	**command_args;

	dup2(infile, STDIN_FILENO);
	close(infile);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	path = ft_getenv("PATH", envp);
	command_args = ft_split(argv[2], ' ');
	command = get_command(path, command_args[0]);
	if (!command)
	{
		free_tab(command_args);
		free(command);
		error_message("Invalid command.\n");
	}
	if (execve(command, command_args, envp))
		perror_message("execve");
}

static void	child2(char **argv, char **envp, int *fd, int outfile)
{
	char	*path;
	char	*command;
	char	**command_args;

	path = ft_getenv("PATH", envp);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	command_args = ft_split(argv[3], ' ');
	command = get_command(path, command_args[0]);
	if (!command)
	{
		free_tab(command_args);
		free(command);
		error_message("Invalid command.\n");
		exit(EXIT_FAILURE);
	}
	if (execve(command, command_args, envp))
		perror_message("execve");
}

static int	open_file(char *name, int n)
{
	int	file;

	if (n == 0)
	{
		file = open(name, O_RDONLY);
		if (file == -1)
			perror_message("Infile open failure");
	}
	if (n == 1)
	{
		file = open(name, O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
		if (file == -1)
			perror_message("Outfile open failure");
	}
	return (file);
}

static void	close_fds(int *fds)
{
	close(fds[0]);
	close(fds[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int		infile;
	int		outfile;
	int		fd[2];
	pid_t	pid[2];

	if (argc != 5)
		error_message("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n");
	infile = open_file(argv[1], 0);
	outfile = open_file(argv[4], 1);
	if (pipe(fd) == -1)
		perror_message("Pipe");
	pid[0] = fork();
	if (pid[0] == -1)
		perror_message("Fork");
	else if (pid[0] == 0)
		child1(argv, envp, fd, infile);
	pid[1] = fork();
	if (pid[1] == -1)
		perror_message("Fork");
	else if (pid[1] == 0)
		child2(argv, envp, fd, outfile);
	wait(NULL);
	wait(NULL);
	close_fds(fd);
	return (0);
}
