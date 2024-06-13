/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:41:50 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/13 19:49:51 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "pipex_bonus.h"
#include "libft.h"

void	ft_pipe(char *path, char **envp)
{
	int		fd[2];
	pid_t	pid;
	char	*command;
	char	**command_args;	

	if (pipe(fd) == -1)
		perror_message("Pipe");
	pid = fork();
	if (pid == -1)
		perror_message("Fork");

}

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc < 5)
		error_message("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		if (argc < 6)
			error_message("Usage: ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2\n");
		i = 3;
		outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | IWUSR);
		if (outfile == -1)
			perror_message("Outfile open failure");
		ft_here_doc(argv);
	}
	else
	{
		i = 2;
	}
	while (i < argc - 2)
		ft_here_doc(argv[i++], envp);
	dup2(outfile, 1);
}
