/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_save_raw_off.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: gmadec <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/01 04:22:15 by gmadec       #+#   ##    ##    #+#       */
/*   Updated: 2018/09/10 03:10:06 by dzonda      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "heart.h"

t_term		ft_save_raw_off(t_select **t)
{
	static int		nb_call = 0;
	static t_term	raw_off;

	if (nb_call == 0)
		if (tcgetattr(STDIN_FILENO, &raw_off) == -1)
			ft_error("tcgetattr", &(*t));
	nb_call = 101;
	return (raw_off);
}