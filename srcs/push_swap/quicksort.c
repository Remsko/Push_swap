/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:25:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/04 17:02:27 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		median(t_env *e, int len, char stack_id)
{
	int		*stack;
	long	min;
	int		max;
	int		index;


	stack = stack_id == 'a' ? e->a : e->b;
	min = (long)2147483648;
	max = 0;
	index = 0;
	while (index < len) 
	{
		if (stack[index] < min)
			min = stack[index];
		if (stack[index] > max)
			max = stack[index];
		++index;
	}
	return ((min + max) / 2 + (index % 2 != 0));
}

void	quicksort(t_env *e)
{
	int pivot;
	int loop;

	while (e->a_len > 3)
	{
		pivot = median(e, e->a_len, 'a');
		loop = e->a_len;
		while (loop--)
		{
			if (e->a[0] < pivot)
				pb(e);
			else
				ra(e);
		}
	}
}
