/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:53:50 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/08 19:15:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	pa(t_env *e)
{
	int i;

	if (e->print == TRUE)
		ft_putendl("pa");
	i = e->a_len;
	if (e->b_len > 0)
	{
		while (i - 1 >= 0)
		{
			ft_swap(&e->a[i], &e->a[i - 1]);
			--i;
		}
		ft_swap(&e->a[0], &e->b[0]);
		e->b_len -= 1;
		e->a_len += 1;
		i = 0;
		while (i < e->b_len)
		{
			ft_swap(&e->b[i], &e->b[i + 1]);
			++i;
		}
	}
}

void	pb(t_env *e)
{
	int i;

	if (e->print == TRUE)
		ft_putendl("pb");
	i = e->b_len;
	if (e->a_len > 0)
	{
		while (i - 1 >= 0)
		{
			ft_swap(&e->b[i], &e->b[i - 1]);
			--i;
		}
		ft_swap(&e->a[0], &e->b[0]);
		e->a_len -= 1;
		e->b_len += 1;
		i = 0;
		while (i < e->a_len)
		{
			ft_swap(&e->a[i], &e->a[i + 1]);
			++i;
		}
	}
}
