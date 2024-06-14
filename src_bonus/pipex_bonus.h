/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xiaxu <xiaxu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 14:05:37 by xiaxu             #+#    #+#             */
/*   Updated: 2024/06/14 17:58:31 by xiaxu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <unistd.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

void	exit_handler(void);
void	perror_message(char *error);
char	*ft_getenv(char *path, char **envp);
char	*get_command(char *path, char *cmd);
void	free_tab(char **tab);
size_t	gnl_strlen(const char *s);
size_t	gnl_strchr(const char *s);
void	gnl_strlcpy(char *dst, const char *src, size_t len);
char	*gnl_substr(char const *s, size_t start, size_t len);
char	*get_next_line(int fd);
int		open_file(char *file, int n);

#endif
