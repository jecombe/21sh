/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_manage_touch.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/27 13:28:15 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/20 18:47:58 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../include/ft_select.h"

int			ft_manage_touch(char **ret, t_select **t)
{
	if ((*ret)[0] == 27 && (*ret)[1] == 0)
	{
		ft_strdel(&(*ret));
		ft_disable_raw(0, &(*t));
		return (4);
	}
	else if (((*ret)[0] == 27 && (*ret)[1] == 91) ||
	((*ret)[0] == 9 && (*ret)[1] == 0))
		return (ft_arrows((*ret)[0] == 9 ? 66 : (*ret)[2], &(*t)));
	else if ((*ret)[0] == 13)
		return (ft_select_sp(&(*t)));
	return (-1);
}
