/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 17:58:52 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/09 18:13:10 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	n_rotate(t_env *e, int until, t_bool reverse, char stack_id)
{
	while (until > 0)
	{
		if (reverse == TRUE)
		{
			if (stack_id == 'a')
				rra(e);
			else if (stack_id == 'b')
				rrb(e);
			else
				rrr(e);
		}
		else
		{
			if (stack_id == 'a')
				ra(e);
			else if (stack_id == 'b')
				rb(e);
			else
				rr(e);
		}
		--until;
	}
}

void	final_rotate(t_env *e)
{
	int		index;
	int		rotate;
	t_bool	reverse;

	reverse = FALSE;
	index = 0;
	while (e->a[index] != 1)
		++index;
	if (index < e->elem_nb / 2)
		rotate = index;
	else
	{
		reverse = TRUE;
		rotate = e->elem_nb - index;
	}
	while (rotate--)
		reverse == TRUE ? rra(e) : ra(e);
}
