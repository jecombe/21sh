/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/25 06:50:50 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/28 00:59:36 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "heart.h"

int		set(t_op *exec)
{
	int		i;

	i = 0;
	if (!exec->cmd[1])
		while (g_set[i])
			ft_putendl_fd(g_set[i++], 1);
	return (0);
}
