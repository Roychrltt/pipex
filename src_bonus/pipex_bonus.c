/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:41:50 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/14 15:31:59 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	exec_command(char *param, char **envp)
{
	char	*path;
	char	**command_args;
	char	*command;

	command_args = ft_split(param, ' ');
	path = ft_getenv("PATH", envp);
	command = get_command(path, command_args[0]);
	if (!command)
	{
	//	free_tab(command_args);
	//	free(command);
		error_message("Invalid command.\n");
	}
	execve(command, command_args, envp);
	perror_message("Pipex");
}

static void	get_here_doc_input(char **argv, int *fd)
{
	char	*input;
	int		file;

	close(fd[0]);
	file = open(".here_doc.tmp", O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	while (1)
	{
		input = get_next_line(STDIN_FILENO);
		if (!input)
			perror_message("Invalid input");
		if (ft_strncmp(input, argv[2], ft_strlen(argv[2])) == 0)
		{
		//	free(input);
			break ;
		}
		write (file, input, ft_strlen(input));
		write (file, "\n", 1);
	}
//	free(input);
	close(file);
}

static void	ft_here_doc(char **argv)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		perror_message("Pipe");
	write (1, "here_doc>", 9);
	pid = fork();
	if (pid == -1)
		perror_message("Fork");
	if (pid == 0)
		get_here_doc_input(argv, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

static void	ft_pipe(char *param, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		perror_message("Pipe");
	pid = fork();
	if (pid == -1)
		perror_message("Fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exec_command(param, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	int		infile;
	int		outfile;

	if (argc < 5)
		error_message("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			error_message("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n");
		i = 3;
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND,
				S_IRUSR | S_IWUSR);
		if (outfile == -1)
			perror_message("Outfile open failure");
		ft_here_doc(argv);
	}
	else
	{
		i = 2;
		infile = open(argv[1], O_RDONLY);
		if (infile == -1)
			perror_message("Infile open failure");
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
				S_IRUSR | S_IWUSR);
		if (outfile == -1)
			perror_message("Outfile open failure");
		dup2(infile, STDIN_FILENO);
	}
	while (i < argc - 2)
		ft_pipe(argv[i++], envp);
	dup2(outfile, STDOUT_FILENO);
	exec_command(argv[argc - 2], envp);
}
