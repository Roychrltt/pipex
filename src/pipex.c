/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:28:31 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/14 18:37:21 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child1(char **argv, char **envp, int *fd, char *path)
{
	int		infile;
	char	*command;
	char	**command_args;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		perror_message("Infile open failure");
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(infile);
	close(fd[0]);
	command_args = ft_split(argv[2], ' ');
	command = get_command(path, command_args[0]);
	if (!command)
	{
		free_tab(command_args);
		free(command);
		error_message("Invalid command.\n");
	}
	execve(command, command_args, envp);
	perror_message("Pipex");
}

static void	child2(char **argv, char **envp, int *fd, char *path)
{
	int		outfile;
	char	*command;
	char	**command_args;

	outfile = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	if (outfile == -1)
		perror_message("Outfile open failure");
	dup2(outfile, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(outfile);
	close(fd[1]);
	command_args = ft_split(argv[3], ' ');
	command = get_command(path, command_args[0]);
	if (!command)
	{
		free_tab(command_args);
		free(command);
		error_message("Invalid command.\n");
		exit(EXIT_FAILURE);
	}
	execve(command, command_args, envp);
	perror_message("pipex");
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid[2];
	char	*path;

	if (argc != 5)
		error_message("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n");
	if (pipe(fd) == -1)
		perror_message("Pipe");
	path = ft_getenv("PATH", envp);
	pid[0] = fork();
	if (pid[0] == -1)
		perror_message("Fork");
	else if (pid[0] == 0)
		child1(argv, envp, fd, path);
	pid[1] = fork();
	if (pid[1] == -1)
		perror_message("Fork");
	else if (pid[1] == 0)
		child2(argv, envp, fd, path);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	return (0);
}
