/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:55:24 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/29 19:10:59 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_handler(void)
{
	ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2\n", 1);
	exit(EXIT_FAILURE);
}

void	exit_handler_here_doc(void)
{
	ft_putstr_fd("Usage: ./pipex here_doc LIMITER cmd cmd1 file\n", 1);
	exit(EXIT_FAILURE);
}

int	open_here_doc(void)
{
	int	fd;

	fd = open(".here_doc.tmp", O_RDONLY);
	if (fd == -1)
	{
		unlink(".here_doc.tmp");
		perror_message(".here_doc.tmp file open failure");
	}
	return (fd);
}

void	result_handler(int argc)
{
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		wait(NULL);
		i++;
	}
	unlink(".here_doc.tmp");
}
