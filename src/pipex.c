/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rharing <rharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 10:34:28 by rharing           #+#    #+#             */
/*   Updated: 2022/04/06 12:49:55 by rharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(t_vars *vars, char **argv, char **envp)
{
	vars->commands = ft_split(argv[vars->argument_count + 1], ' ');
	if (!vars->commands)
		pexit("Failed to split commands", 1);
	find_path(vars);
	if (execve(vars->correct_path, vars->commands, envp) < 0)
		pexit("Failed to execute execve", 1);
}

static void	utils(t_vars *vars, char **argv, char **envp)
{
	pid_t	forkvalue;
	int		end[2];

	if (pipe(end) == -1)
		pexit("Failed to create pipe", 1);
	forkvalue = fork();
	if (forkvalue == -1)
		pexit("Failed to create fork", 1);
	if (forkvalue == 0)
	{
		close(end[0]);
		if (dup2(end[1], STDOUT_FILENO) == -1)
			pexit("Failed to dup end[1]", 1);
		child(vars, argv, envp);
	}
	else
	{
		close(end[1]);
		if (dup2(end[0], STDIN_FILENO) == -1)
			pexit("Failed to dup end[0]", 1);
	}
	close(end[0]);
	close(end[1]);
}

static void	pipex(t_vars *vars, int argc, char **argv, char **envp)
{
	vars->argument_count = 1;
	while (vars->argument_count < (argc - 3))
	{
		utils(vars, argv, envp);
		vars->argument_count++;
	}
	child(vars, argv, envp);
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	vars;

	if (argc < 5)
		pexit("Too few arguments", 1);
	vars.fd1 = open(argv[1], O_RDONLY, 0644);
	vars.fd2 = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (vars.fd2 < 0)
		pexit(argv[argc - 1], 1);
	if (vars.fd1 < 0)
		pexit(argv[1], 1);
	if (dup2(vars.fd1, STDIN_FILENO) == -1)
		pexit("Failed to dup infile", 1);
	if (dup2(vars.fd2, STDOUT_FILENO) == -1)
		pexit("Failed to dup outfile", 1);
	get_path_from_envp(&vars, envp);
	pipex(&vars, argc, argv, envp);
	close(vars.fd1);
	close(vars.fd2);
	return (0);
}
