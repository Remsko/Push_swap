/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:11:09 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/13 16:01:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		get_number_index(t_env *e, int nb)
{
	int ret;

	ret = 0;
	while (ret < e->elem_nb)
	{
		if (e->a[ret] == nb)
			break;
		ret++;
	}
	return (ret);
}

void	operations_algo(t_env *e)
{
	int	mediane;
	int index;
	int nb;
	int op_nb;

	op_nb = 0;
	nb = 0;
	index = 0;
	mediane = e->elem_nb / 2;
	if (issorted(e) == TRUE)
		return ;
	while (nb++ != e->elem_nb)
	{
		index = get_number_index(e, nb);
		if (index >= mediane)
		{
			op_nb = e->a_len - index;
			while (op_nb--)
				rra(e);
		}
		else
		{
			op_nb = index;
			while (op_nb--)
				ra(e);
		}
		pb(e);
	}
	nb = 0;
	while (nb++ != e->elem_nb)
		pa(e);
}