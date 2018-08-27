/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_params.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/13 07:07:52 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/08/27 03:36:35 by dewalter    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "includes/ft_select.h"

int		ft_count_params(t_line *line)
{
	int		i;

	i = 0;
	while (line)
	{
		line = line->next;
		i++;
	}
	return (i);
}
