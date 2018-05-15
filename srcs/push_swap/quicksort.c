/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:25:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/15 21:59:41 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	recursive_quicksort(t_env *e)
{
	int pivot;
	int op_nb;

	pivot = e->elem_nb - e->a_len / 2;
	op_nb = 0;
	while (op_nb < e->a_len)
	{
		if (e->a[0] <= pivot)
			pb(e);
		else
			ra(e);
		++op_nb;
	}
	if (pivot >= e->elem_nb)
		return ;
	return (recursive_quicksort(e));
}

void	quicksort(t_env *e)
{
	if (issorted(e) == TRUE)
		return ;
	recursive_quicksort(e);
}