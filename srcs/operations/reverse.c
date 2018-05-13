/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:56:54 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/13 15:51:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	rra(t_env *e)
{
	int i;

	if (e->print == TRUE)
		ft_putendl("rra");
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

	if (e->print == TRUE)
		ft_putendl("rrb");
	i = e->b_len - 1;
	while (i - 1 >= 0)
	{
		ft_swap(&e->b[i], &e->b[i - 1]);
		--i;
	}
}

void	rrr(t_env *e)
{
	int i;

	if (e->print == TRUE)
		ft_putendl("rrr");
	i = e->a_len - 1;
	while (i - 1 >= 0)
	{
		ft_swap(&e->a[i], &e->a[i - 1]);
		--i;
	}
	i = e->b_len - 1;
	while (i - 1 >= 0)
	{
		ft_swap(&e->b[i], &e->b[i - 1]);
		--i;
	}
}