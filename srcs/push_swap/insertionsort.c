/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:37:19 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 18:21:11 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack_nb	get_closest_upper(t_env *e, t_stack_nb *actual)
{
	t_stack_nb	next;
	int			index;

	index = 0;
	next.index = 0;
	next.nb = 0x7FFFFFFF;
	while (index < e->a_len)
	{
		if (e->a[index] > actual->nb && e->a[index] < next.nb)
		{
			next.index = index;
			next.nb = e->a[index];
		}
		else
			++index;
	}
	return (next);
}

void		get_rotation(int *rot, t_bool *rot_rev, int index, int len)
{
	if (index < len / 2)
		*rot = index;
	else
	{
		*rot = len - index;
		*rot_rev = TRUE;
	}
}

void		get_both_rotation(t_env *e, t_stack_nb *actual,
		t_stack_nb *next, t_rotation *rot)
{
	(void)e;
	(void)actual;
	(void)next;
	if (rot->rev_a == rot->rev_b)
	{
		if (rot->a < rot->b)
			rot->both = rot->a;
		else
			rot->both = rot->b;
		rot->a -= rot->both;
		rot->b -= rot->both;
		rot->rev_both = rot->rev_a;
	}
	else
	{
		return ;
	}
}

int			move_for(t_env *e, t_stack_nb *actual, t_stack_nb *next, t_bool m)
{
	t_rotation	*rot;
	int			op;

	op = 0;
	rot = (t_rotation[1]){{0, 0, 0, FALSE, FALSE, FALSE}};
	get_rotation(&rot->b, &rot->rev_b, actual->index, e->b_len);
	get_rotation(&rot->a, &rot->rev_a, next->index, e->a_len);
	get_both_rotation(e, actual, next, rot);
	if (m == TRUE)
	{
		n_rotate(e, rot->a, rot->rev_a, 'a');
		n_rotate(e, rot->b, rot->rev_b, 'b');
		n_rotate(e, rot->both, rot->rev_both, '2');
		pa(e);
	}
	else
	{
		op += rot->a;
		op += rot->b;
		op += rot->both;
		++op;
	}
	return (op);
}

void		insertionsort(t_env *e, int turn)
{
	t_stack_nb	actual[2];
	t_stack_nb	final[2];
	int			index;
	int			op_nb;
	int			op_tmp;

	index = 0;
	op_tmp = 0;
	op_nb = 0x7FFFFFFF;
	if (e->b_len == 0)
		return (final_rotate(e));
	while (index < e->b_len)
	{
		actual[0] = (t_stack_nb){e->b[index], index};
		actual[1] = get_closest_upper(e, &actual[0]);
		if ((op_tmp = move_for(e, &actual[0], &actual[1], FALSE)) < op_nb)
		{
			op_nb = op_tmp;
			final[0] = actual[0];
		}
		++index;
	}
	final[1] = get_closest_upper(e, &final[0]);
	move_for(e, &final[0], &final[1], TRUE);
	insertionsort(e, turn + 1);
}
