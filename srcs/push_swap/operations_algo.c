/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 11:11:09 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/11 16:48:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_bool	issorted(t_env *e)
{
	int		i;
	t_bool	answer;

	i = 0;
	answer = 1 - (e->b_len > 0);
	while (i + 1 < e->elem_nb)
	{
		if (e->a[i] > e->a[i + 1])
		{
			answer = FALSE;
			break ;
		}
		else
			++i;
	}
	if (answer == TRUE)
	{
		free(e->a);
		free(e->b);
		return (TRUE);
	}
	else
		return (FALSE);
}

void	operations_algo(t_env *e)
{
	int	center;
	int	i;

	i = 0;
	center = e->elem_nb / 2;
	if (issorted(e) == TRUE)
		return ;
	while (i++ < center)
		pb(e);
	for (int j = 0; j < e->elem_nb; j++)
		printf("%d \t %d\n", e->a[j], e->b[j]);
}