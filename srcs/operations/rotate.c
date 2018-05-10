/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:55:37 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 18:01:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ra(t_env *e)
{
	int i;

	i = 0;
	while (i + 1 < e->a_len)
	{
		ft_swap(&e->a[i], &e->a[i + 1]);
		++i;
	}
}

void	rb(t_env *e)
{
	int i;

	i = 0;
	while (i + 1 < e->b_len)
	{
		ft_swap(&e->b[i], &e->b[i + 1]);
		++i;
	}
}

void	rr(t_env *e)
{
	ra(e);
	rb(e);
}