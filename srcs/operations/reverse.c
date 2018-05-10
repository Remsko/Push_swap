/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:56:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 17:56:57 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	rra(t_env *e)
{
	int i;

	i = e->a_len - 1;
	while (i - 1 >= 0)
	{
		ft_swap(&e->a[i], &e->a[i - 1]);
		--i;
	}
}

void	rrb(t_env *e)
{
	int i;

	i = e->b_len - 1;
	while (i - 1 >= 0)
	{
		ft_swap(&e->b[i], &e->b[i - 1]);
		--i;
	}
}

void	rrr(t_env *e)
{
	rra(e);
	rrb(e);
}