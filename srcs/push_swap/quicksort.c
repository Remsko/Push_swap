/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 15:25:39 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/23 17:24:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

#define PILE_LEN (pile == 'a' ? e->a_len : e->b_len)
#define PILE_CHOSE (pile == 'a' ? e->a : e->b)
#define PILE_REVERSE (pile == 'a' ? 'b' : 'a')
#define PILE_FIRST (pile == 'a' ? e->a[0] : e->b[0])

int		quicksort_to(t_env *e, char pile, int pivot)
{
	if (PILE_FIRST <= pivot)
	{
		pile == 'a' ? pb(e) : pa(e);
		return (1);
	}
	else
		pile == 'a' ? ra(e) : rb(e);
	return (0); 
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
	int reset;

	if (issorted(e) == TRUE)
		return ;
	pushed = 0;
	reset = 0;
	pivot = get_median(PILE_CHOSE, len);
	while (len > 3 && pushed < (len / 2) + (len % 2 && pile == 'a') && ++reset)
		pushed += quicksort_to(e, pile, pivot);
	while (turn == 0 && (reset--) - pushed)
		pile == 'a' ? rra(e) : rrb(e);
	if (pushed > 0 && pile == 'b')
		recursive_quicksort(e, pushed, 'a', 0);
	if (len - pushed <= 3)
		instant_sort(e, len - pushed, pile);
	else
		recursive_quicksort(e, len - pushed, pile, turn == 2 ? turn - 1 : turn);
	if (pushed > 0 && pile == 'a')
		recursive_quicksort(e, pushed, 'b', turn == 2 ? 1 : 0);
	while (pushed--)
		pile == 'a' ? pa(e) : pb(e);
}