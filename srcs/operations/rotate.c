/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:55:37 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/13 15:52:50 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ra(t_env *e)
{
	int i;

	i = 0;
	if (e->print == TRUE)
		ft_putendl("ra");
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
	if (e->print == TRUE)
		ft_putendl("rb");
	while (i + 1 < e->b_len)
	{
		ft_swap(&e->b[i], &e->b[i + 1]);
		++i;
	}
}

void	rr(t_env *e)
{
	int mark;

	mark = 0;
	if (e->print == TRUE)
	{
		ft_putendl("rr");
		e->print = FALSE;
		mark = 1;
	}
	ra(e);
	rb(e);
	if (mark == 1)
		e->print = TRUE;
}