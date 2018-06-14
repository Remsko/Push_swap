/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:16:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/14 12:01:26 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void	fill_piles(t_env *e)
{
	t_list	*tmp;
	char	**split;
	int		i;

	i = 0;
	tmp = e->lst;
	while (tmp)
	{
		split = (char **)tmp->content;
		while (*split)
		{
			e->b[i++] = ft_atoi(*split++);
			if (i == e->elem_nb)
				return ;
		}
		tmp = tmp->next;
	}
}

void		create_piles(t_env *e)
{
	if (!(e->a = (int*)malloc(sizeof(int) * e->elem_nb)))
	{
		ft_lstdel(&e->lst, ft_deltab);
		ft_error(4);
	}
	if (!(e->b = (int*)malloc(sizeof(int) * e->elem_nb)))
	{
		ft_lstdel(&e->lst, ft_deltab);
		free(e->a);
		ft_error(5);
	}
	e->a_len = e->elem_nb;
	e->b_len = 0;
	fill_piles(e);
	ft_lstdel(&e->lst, ft_deltab);
}
