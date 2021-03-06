/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   binary.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: jecombe <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/01 01:45:49 by jecombe      #+#   ##    ##    #+#       */
/*   Updated: 2018/11/21 05:53:50 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "heart.h"

int			isbuiltin(char *cmd)
{
	static char	*builtins[] = {"cd", "setenv", "unsetenv", "export", "unset",
		"exit", "echo", "env", "set", "ft_assign", "hash", "read", NULL };
	int			i;

	i = -1;
	while (builtins[++i])
		if (ft_strcmp(builtins[i], cmd) == 0)
			return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static int	ft_check_direct_bin(const char *cmd)
{
	if (access(cmd, F_OK) == -1)
		return (EXIT_FAILURE);
	if (cmd[0] == '/' || !ft_strncmp(cmd, "./", 2))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}

static char	*ft_check_path_bin(const char *cmd)
{
	char		*path;
	char		**grid;
	int			i;
	char		buff[BUFF_SIZE];

	path = NULL;
	grid = NULL;
	i = -1;
	ft_bzero(buff, BUFF_SIZE);
	if (!(path = ft_getenv("PATH", g_env)))
		return (NULL);
	if (!(grid = ft_strsplit(path, ':')))
		return (NULL);
	ft_strdel(&path);
	while (grid[++i])
	{
		ft_strcpy(buff, grid[i]);
		(buff[ft_strlen(buff) - 1] != '/') ? ft_strcat(buff, "/") : 0;
		if (access(ft_strcat(buff, cmd), F_OK) == 0)
			path = ft_strdup(buff);
		ft_strclr(buff);
		ft_strdel(&grid[i]);
	}
	free(grid);
	return (path);
}

int			ft_check_hash_bin(const char *cmd, char **buff)
{
	t_hashtable	*hashtable;
	t_hashcase	*hashcase;
	int			hash;

	hashtable = NULL;
	hashcase = NULL;
	hash = 0;
	ft_save_hash(&hashtable);
	hash = ft_hash(cmd);
	if (hashtable[hash].hashcase)
	{
		hashcase = hashtable[hash].hashcase;
		while (hashcase)
		{
			if (ft_strcmp(cmd, hashcase->raccmd) == 0)
			{
				*buff = ft_strdup(hashcase->command);
				return (EXIT_SUCCESS);
			}
			hashcase = hashcase->next;
		}
	}
	return (EXIT_FAILURE);
}

char		*ft_search_bin(char *cmd)
{
	char	*buff;

	buff = NULL;
	if (!isbuiltin(cmd))
		return (ft_strdup(cmd));
	if (!(ft_check_direct_bin(cmd)))
		return (ft_strdup(cmd));
	if (!(ft_check_hash_bin(cmd, &buff)))
		return (buff);
	if (!(buff = ft_check_path_bin(cmd)))
		ft_strdel(&buff);
	return (buff);
}
