/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:54:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 17:19:33 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	sa(t_env *e)
{
	if (e->a_len > 1)
		ft_swap(&e->a[0], &e->a[1]);
}

void	sb(t_env *e)
{
	if (e->b_len> 1)
		ft_swap(&e->b[0], &e->b[1]);
}

void	ss(t_env *e)
{
	sa(e);
	sb(e);
}

void	pa(t_env *e)
{
	int i;

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

t_bool	do_operation(t_env *e, char *line)
{
	(void)e;
	if (ft_strcmp(line, "sa") == 0)
		sa(e);
	else if (ft_strcmp(line, "sb") == 0)
		sb(e);
	else if (ft_strcmp(line, "ss") == 0)
		ss(e);
	else if (ft_strcmp(line, "pa") == 0)
		pa(e);
	else if (ft_strcmp(line, "pb") == 0)
		pb(e);
	else if (ft_strcmp(line, "ra") == 0)
		ra(e);
	else if (ft_strcmp(line, "rb") == 0)
		rb(e);
	else if (ft_strcmp(line, "rr") == 0)
		rr(e);
	else if (ft_strcmp(line, "rra") == 0)
		rra(e);
	else if (ft_strcmp(line, "rrb") == 0)
		rrb(e);
	else if (ft_strcmp(line, "rrr") == 0)
		rrr(e);
	else
		return (FALSE);
	for (int i = 0; i < e->elem_nb; i++)
		printf("%d \t %d\n", e->a[i], e->b[i]);
	return (TRUE);
}