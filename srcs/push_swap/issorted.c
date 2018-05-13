/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:20:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/13 12:21:00 by rpinoit          ###   ########.fr       */
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