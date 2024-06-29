/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:55:24 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/29 11:28:48 by xiaxu            ###   ########.fr       */
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
