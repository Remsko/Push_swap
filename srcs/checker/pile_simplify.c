/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_simplify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:19:35 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/07 18:29:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	pile_simply(t_env *e)
{
	int		i;
	int		j;
	long	tmp;

	tmp = 2147483648;
	i = 0;
	while (i < e->elem_nb)
	{
		j = 0;
		while (j < e->elem_nb)
		{
			if (e->a[j] < tmp)
			{
				tmp = (long)e->a[j];
			}
			else
				j++;
		}
		e->b[j] = ++i;
	}
}