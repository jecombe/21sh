/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/23 06:42:06 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/23 08:50:31 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/init.h"

static char			*found_slash(int i[2], char *bin, char **tmp_1, char **tmp)
{
	char		*tmp_2;

	if (i[0] > 0 && bin[i[0] - 1] == '/')
	{
		while (i[0] > 0 && bin[i[0]] == '/')
			i[0] = i[0] - 1;
		i[0] = i[0] + 1;
	}
	if (!(i[0] == 0 || (i[0] == 1 && bin[0] == '.')))
	{
		if (bin[0] == '/' || bin[0] == '.')
		{
			while (bin[i[1]] == '.')
				i[1] = i[1] + 1;
			while (bin[i[1]] == '/')
				i[1] = i[1] + 1;
		}
		tmp_2 = ft_strsub(bin, i[1], i[0] - i[1]);
		*tmp_1 = ft_strjoin("/", tmp_2);
		ft_strdel(&tmp_2);
		tmp_2 = ft_strjoin(*tmp, *tmp_1);
		ft_strdel(tmp_1);
		return (tmp_2);
	}
	return (NULL);
}

char				*search_path_of_101sh(char *bin)
{
	char		*tmp;
	char		*tmp_1;
	char		*tmp_2;
	char		buff[4096];
	int			i[2];

	i[1] = 0;
	tmp_1 = NULL;
	tmp = ft_strdup(getcwd(buff, sizeof(buff)));
	if (bin)
	{
		i[0] = ft_strlen(bin);
		while (i[0] >= 0)
		{
			if (bin[i[0]] == '/')
			{
				tmp_2 = found_slash(i, bin, &tmp_1, &tmp);
				tmp_2 ? ft_strdel(&tmp) : 0;
				return (tmp_2 ? tmp_2 : tmp);
			}
				i[0] = !(bin[i[0]] == '/') ? i[0] = i[0] - 1 : i[0];
		}
	}
	return (tmp);
}

char				*concat_name_value(char *name, char *value)
{
	char		*str;
	char		*str2;

	str = NULL;
	str2 = NULL;
	if (!name || !value)
		return (NULL);
	str2 = ft_strjoin(name, "=");
	str = ft_strjoin(str2, value);
	return (str);
}
