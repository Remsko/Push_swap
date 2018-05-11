/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_operation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 13:54:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/11 14:45:16 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_bool	do_operation(t_env *e, char *line)
{
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
	printf("a = %d\t b = %d\n", e->a_len, e->b_len);
	for (int i = 0; i < e->elem_nb; i++)
		printf("%d \t %d\n", e->a[i], e->b[i]);
	return (TRUE);
}