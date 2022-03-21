/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:59:28 by eabradol          #+#    #+#             */
/*   Updated: 2022/01/30 14:59:30 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <errno.h>
# include <dirent.h>

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

void	ft_child(int *p, char **argv, char **env);
void	strt_cmd(char *part_argv, char **env, char *command);
int		open_file(char	*file_name, int flag);
void	cmd_2(char **argv, char **env, pid_t pid, int argc);
char	*chek_cmd_file(char **env, char	*cmd, char **argv);
pid_t	proses(void);

//libft
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
char	**ft_split(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *str);

#endif
