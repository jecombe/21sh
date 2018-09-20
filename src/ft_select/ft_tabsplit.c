/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:14:20 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 13:36:19 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/heart.h"

static int			issep(const char *s, int i)
{
	if (ft_isseparator(s[i]) && (i == 0 || (i > 0 && s[i - 1] != '\\')))
		return (1);
	return (0);
}

static size_t		wordlen(const char *s, char c, size_t index, int *cursor_pos)
{
	int i = index;
	size_t	count;

	count = 0;
	if (ft_isseparator(c))
		while (s[i] == c)
		{
			count++;
			i++;
		}
	else if (ft_isblank(c))
	{
		while (ft_isblank(s[i]) && s[i] && !(i == *cursor_pos))
		{
			i++;
			count++;
		}
		*cursor_pos = i == *cursor_pos ? -1 : *cursor_pos;
	}
	else if (ft_isprint(c) && !ft_isblank(c))
		while (ft_isprint(s[i]) && !ft_isblank(s[i]) && s[i] && !issep(s, i))
//		while (ft_isprint(s[i]) && !ft_isblank(s[i]) && s[i])
		{
			i++;
			count++;
		}
	return (count);
}

char				**ft_tabsplit(const char *s, int cursor_pos)
{
	char	**tablo;
	size_t	i;
	char	*tmp;
	int		set_cursor[2];

	set_cursor[1] = cursor_pos;
	set_cursor[0] = cursor_pos;
	i = 0;
	tablo = NULL;
	if (s)
		while (s[i] != '\0')
		{
			tmp = ft_strsub(s, ((int)i), wordlen(s, s[i], i, &set_cursor[0]));
			ft_malloc_cmd(&tablo, tmp);
			ft_strdel(&tmp);
			i += wordlen(s, s[i], i, &set_cursor[1]);
		}
	return (tablo);
}