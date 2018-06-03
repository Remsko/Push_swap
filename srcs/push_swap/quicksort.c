/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:25:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/03 18:44:36 by rpinoit          ###   ########.fr       */
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

void	quicksort(t_env *e, int len, char stack_id)
{
	int pivot;


	pivot = median(e, len , stack_id);

}
