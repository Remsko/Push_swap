/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_simplify.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 18:19:35 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 18:18:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void	next_min(t_env *e, long *previous, int nb)
{
	long	min;
	int		index;
	int		i;

	min = (long)2147483648;
	index = 0;
	i = 0;
	while (i < e->elem_nb)
	{
		if ((long)e->b[i] < min && (long)e->b[i] > *previous)
		{
			min = (long)e->b[i];
			index = i;
			i = 0;
		}
		else
			++i;
	}
	e->a[index] = nb;
	*previous = min;
}

void		pile_simplify(t_env *e)
{
	long previous;
	int i;

	previous = (long)-2147483649;
	i = 0;
	while (i < e->elem_nb)
		next_min(e, &previous, ++i);
	i = 0;
	while (i < e->elem_nb)
		e->b[i++] = 0;
}