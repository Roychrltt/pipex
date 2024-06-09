/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:28:31 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/09 18:03:13 by roychrltt        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	exit_handler(void)
{
	ft_putstr_fd("Usage: ./pipex <infile> <cmd1> <cmd2> <outfile>\n", 2);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv, char **envp)
{
	(void) argv;
	(void) envp;
	if (argc != 5)
		exit_handler();
}
