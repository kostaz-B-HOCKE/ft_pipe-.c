/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eabradol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 14:57:22 by eabradol          #+#    #+#             */
/*   Updated: 2022/01/30 14:57:27 by eabradol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	n;

	i = 0;
	if (!s)
		return (NULL);
	n = ft_strlen(&s[i]);
	if (n < len)
		len = n;
	if (start > n)
		len = 0;
	str = malloc(sizeof(char ) * (len + 1));
	if (!str)
		return (NULL);
	n = 0;
	while (s[start] && n < len)
		str[n++] = s[start++];
	str[n] = '\0';
	return (str);
}

void	spl_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
	}
	free(str);
}

char	*chek_cmd_file(char **env, char	*cmd, char **av)
{
	int		i;
	char	*str;
	char	**str_split;
	char	**chek_split;
	char	*str_chek;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	str_split = ft_split(env[i] + 5, ':');
	chek_split = ft_split(cmd, ' ');
	i = 0;
	while (str_split[i])
	{
		str = ft_strjoin(str_split[i], "/");
		str_chek = ft_strjoin(str, chek_split[0]);
		free(str);
		if (access(str_chek, F_OK) == 0)
			return (str_chek);
		i++;
		free(str_chek);
	}
	spl_free(str_split);
	spl_free(chek_split);
	return (0);
}

int	main(int argc, char *argv[], char **env)
{
	int		fdd1;
	int		fdd2;
	pid_t	pid;

	if (argc == 5)
	{
		fdd1 = open_file(argv[1], 5);
		fdd2 = open_file(argv[argc - 1], 2);
		dup2(fdd1, 0);
		dup2(fdd2, 1);
		pid = proses();
		cmd_2(argv, env, pid, argc);
	}
	else
		write(1, "argument error\n", 16);
	return (1);
}
