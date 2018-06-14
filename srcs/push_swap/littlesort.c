/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:15:13 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/14 14:58:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void			littlesort(t_env *e)
{
	while (a_sorted(e) == FALSE)
	{
		if (e->a_len == 2)
			sa(e);
		else
		{
			if (e->a[1] < e->a[0] && e->a[1] < e->a[2])
				e->a[0] < e->a[2] ? sa(e) : ra(e);
			else if ((e->a[1] < e->a[0] || e->a[1] < e->a[2])
					&& e->a[0] > e->a[2])
				sa(e);
			else
				rra(e);
		}
	}
}
