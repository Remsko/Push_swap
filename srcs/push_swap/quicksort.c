/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:25:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/03 14:59:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	mover(t_env *e, t_move *move, int len, int pivot, char stack_id)
{
	while (len)
	{
		if ((stack_id == 'a' ? e->a[0] : e->b[0]) <= pivot)
		{
			stack_id == 'a' ? pb(e) : pa(e);
			++move->push;
		}
		else
		{
			stack_id == 'a' ? ra(e) : rb(e);
			++move->rotate;
		}
		--len;
	}
}

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
	return ((min + max) / 2);
}

void	new_move_link(t_move **begin)
{
	t_move *new;

	if (*begin == NULL)
	{
		if ((new = (t_move*)ft_memalloc(sizeof(t_move))) == NULL)
			return /* free properly please */;
		*begin = new;
	}
	else
	{
		if ((new = (t_move*)ft_memalloc(sizeof(t_move))) == NULL)
			return /* free properly please */;
		new->next = *begin;
		*begin = new;
	}
}

void	quicksort(t_env *e)
{
	t_move	*move;
	int		pivot;
	char	stack_id;

	move = NULL;
	while (e->a_len)
	{
		new_move_link(&move);
		stack_id = 'a';
		pivot = median(e, e->a_len, stack_id);
		mover(e, move, e->a_len, pivot, stack_id);
	}
}