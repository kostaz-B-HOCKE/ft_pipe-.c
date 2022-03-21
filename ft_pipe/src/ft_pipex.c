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

int	cheak_space(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	open_file(char	*file_name, int flag)
{
	if (flag == 5)
	{
		if (access(file_name, F_OK))
		{
			write(2, "No F_OK\n", 8);
			exit(1);
		}
		if (access(file_name, R_OK))
		{
			write(2, "No R_OK\n", 8);
			exit(1);
		}
		return (open(file_name, O_RDONLY, 0));
	}
	else
		return (open(file_name, O_CREAT + O_WRONLY + O_TRUNC, 0777));
}

void	strt_cmd(char *part_argv, char **env, char *command)
{
	execve(command, ft_split(part_argv, ' '), env);
	free(command);
}

void	cmd_2(char **argv, char **env, pid_t pid, int argc)
{
	char	*comand;

	if (pid)
	{
		comand = chek_cmd_file(env, argv[argc - 2], argv);
		strt_cmd(argv[argc - 2], env, comand);
	}
	else
	{
		comand = chek_cmd_file(env, argv[2], argv);
		strt_cmd(argv[2], env, comand);
	}
}

pid_t	proses(void)
{
	int		peper[2];
	pid_t	pid;

	pipe(peper);
	pid = fork();
	if (pid)
	{
		close(peper[1]);
		dup2(peper[0], 0);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(peper[0]);
		dup2(peper[1], 1);
	}
	return (pid);
}
