/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:25:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/21 17:47:04 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

#define PILE_LEN (pile == 'a' ? e->a_len : e->b_len)
#define PILE_CHOSE (pile == 'a' ? e->a : e->b)
#define PILE_REVERSE (pile == 'a' ? 'b' : 'a')
#define PILE_FIRST (pile == 'a' ? e->a[0] : e->b[0])

int		quicksort_to(t_env *e, char pile, int op_nb, int pivot)
{
	int pushed;

	pushed = 0;
	while (op_nb--)
	{
		if (PILE_FIRST <= pivot)
		{
			pile == 'a' ? pb(e) : pa(e);
			++pushed;
		}
		else
			pile == 'a' ? ra(e) : rb(e);
	}
	return (pushed); 
}

int		get_median(int *actual, int len)
{
	int i;
	int min;
	int max;

	max = 0;
	min = 2147483647;
	i = 0;
	while (i < len)
	{
		min = actual[i] < min ? actual[i] : min;
		max = actual[i] > max ? actual[i] : max;
		i++;
	}
	return ((min + max) / 2);
}

void	recursive_quicksort(t_env *e, int len, char pile)
{
	int pivot;
	int pushed;

	if (issorted(e) == TRUE || len <= 0 || e == NULL)
		return ;
	pivot = get_median(PILE_CHOSE, len);
	pushed = quicksort_to(e, pile, len, pivot);

	if (pushed > 0 && pile == 'b')
		recursive_quicksort(e, pushed, 'a');
	if (pushed <= 5)
		return ;
	else
		recursive_quicksort(e, len - pushed, pile);
	if (pushed > 0 && pile == 'a')
		recursive_quicksort(e, pushed, 'b');
}