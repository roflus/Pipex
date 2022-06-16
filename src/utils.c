/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rharing <rharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 11:09:54 by rharing           #+#    #+#             */
/*   Updated: 2022/04/06 12:32:03 by rharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pexit(char *str, int exit_code)
{
	perror(str);
	exit(exit_code);
}

void	get_path_from_envp(t_vars *vars, char **envp)
{
	char	*temp;

	while (ft_strncmp(*envp, "PATH=", 5) && *(envp + 1))
		envp++;
	if (ft_strncmp(*envp, "PATH=", 5) != 0)
		pexit("Failed to find PATH=", 1);
	temp = ft_strtrim(*envp, "PATH=");
	if (!temp)
		pexit("Failed to trim PATH=", 1);
	vars->split_paths = ft_split(temp, ':');
	if (!vars->split_paths)
		pexit("Failed to split paths", 1);
	free(temp);
}

void	find_path(t_vars *vars)
{
	int		i;
	char	*temp_added_slash;
	char	*path_with_cmd;

	i = 0;
	if (access(vars->commands[0], X_OK) == 0)
		vars->correct_path = ft_strdup(vars->commands[0]);
	while (vars->split_paths[i] != '\0')
	{
		temp_added_slash = ft_strjoin(vars->split_paths[i], "/");
		if (!temp_added_slash)
			pexit("Failed to join / to path", 1);
		path_with_cmd = ft_strjoin(temp_added_slash, vars->commands[0]);
		if (!path_with_cmd)
			pexit("Failed to join command to path", 1);
		if (access(path_with_cmd, X_OK) == 0)
			vars->correct_path = ft_strdup(path_with_cmd);
		free(path_with_cmd);
		free(temp_added_slash);
		i++;
	}
	if (vars->correct_path == NULL)
		pexit("Command not found", 127);
}
