/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 14:59:43 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/14 14:59:56 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_bool	a_sorted(t_env *e)
{
	int i;

	i = 0;
	while (i < e->a_len - 1)
	{
		if (e->a[i] < e->a[i + 1])
			++i;
		else
			return (FALSE);
	}
	return (TRUE);
}