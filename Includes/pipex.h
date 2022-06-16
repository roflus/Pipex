/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rharing <rharing@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/22 12:39:39 by rharing       #+#    #+#                 */
/*   Updated: 2022/03/30 19:09:50 by rharing       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <libft.h>

typedef struct s_vars {
	char	*path_from_envp;
	char	**split_paths;
	char	**commands;
	char	*correct_path;
	int		argument_count;
	int		fd1;
	int		fd2;
}				t_vars;	

// Utils
void	get_path_from_envp(t_vars *vars, char **envp);
void	pexit(char *str, int exit_code);
void	find_path(t_vars *vars);

#endif