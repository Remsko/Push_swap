/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:25:32 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/08 18:49:53 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	check_duplicate(t_env *e)
{
	int	i;
	int j;

	i = 0;
	while (i < e->elem_nb)
	{
		j = 0;
		while (j < e->elem_nb)
		{
			if (j != i && e->b[i] == e->b[j]) 
			{
				free(e->a);
				free(e->b);
				ft_error(6);
			}
			j++;
		}
		i++;
	}
}
