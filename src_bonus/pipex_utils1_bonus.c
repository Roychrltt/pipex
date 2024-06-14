/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:55:24 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/14 18:23:55 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	exit_handler(void)
{
	ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 ... cmdn file2\n", 1);
	exit(EXIT_FAILURE);
}
