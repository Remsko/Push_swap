/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:55:04 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/13 15:55:07 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	sa(t_env *e)
{
	if (e->print == TRUE)
		ft_putendl("sa");
	if (e->a_len > 1)
		ft_swap(&e->a[0], &e->a[1]);
}

void	sb(t_env *e)
{
	if (e->print == TRUE)
		ft_putendl("sb");
	if (e->b_len > 1)
		ft_swap(&e->b[0], &e->b[1]);
}

void	ss(t_env *e)
{
	if (e->print == TRUE)
		ft_putendl("ss");
	if (e->a_len > 1)
		ft_swap(&e->a[0], &e->a[1]);
	if (e->b_len > 1)
		ft_swap(&e->b[0], &e->b[1]);
}