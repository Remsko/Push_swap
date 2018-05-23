/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:25:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/23 19:03:59 by rpinoit          ###   ########.fr       */
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

t_bool	isnsorted(int *stack, int n)
{
	int i;

	i = 0;
	while (i + 1 < n)
	{
		if (stack[i] > stack[i + 1])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	instant_sort(t_env *e, int len, char pile)
{
	int *actual;

	actual = pile == 'a' ? e->a : e->b;
	if (len > 3)
		ft_error(666);
	while (isnsorted(actual, len) == FALSE)
	{
		if (isnsorted(actual, 2) == FALSE)
				pile == 'a' ? sa(e) : sb(e);
		else
		{
			pile == 'a' ? ra(e) : rb(e);
        	pile == 'a' ? sa(e) : sb(e);
            pile == 'a' ? rra(e) : rrb(e);
		}
	}
}

void	recursive_quicksort(t_env *e, int len, char pile, int turn)
{
	int pivot;
	int pushed;
	int tmp;

	if (issorted(e) == TRUE || len <= 0 || e == NULL)
		return ;
	pivot = get_median(PILE_CHOSE, len);
	pushed = quicksort_to(e, pile, len, pivot);
	if (len - pushed <= 3)
		instant_sort(e, len - pushed, pile);
	else
		recursive_quicksort(e, len - pushed, pile, turn + 1);
	tmp = pushed;
	if (turn < 5)
		return ;
	while (tmp--)
		pile == 'a' ? pa(e) : pb(e);
}