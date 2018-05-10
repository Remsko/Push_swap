/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_piles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 17:16:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 15:24:48 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	fill_piles(int *pile_a, int *pile_b, t_env *e)
{
	t_list	*lst;
	char	**split;
	int		i;

	i = 0;
	lst = e->lst;
	e->a = pile_a;
	e->b = pile_b;
	while (lst)
	{
		split = (char **)lst->content;
		while (*split)
		{
			e->b[i++] = ft_atoi(*split++);
			if (i == e->elem_nb)
				return ;
		}
		lst = lst->next;
	}
}

void	create_piles(t_env *e)
{
	int	*pile_a;
	int	*pile_b;

	if (!(pile_a = (int*)malloc(sizeof(int) * e->elem_nb)))
	{
		ft_lstdel(&e->lst, ft_deltab);
		ft_error(4);
	}
	if (!(pile_b = (int*)malloc(sizeof(int) * e->elem_nb)))
	{
		ft_lstdel(&e->lst, ft_deltab);
		free(pile_a);
		ft_error(5);
	}
	e->a_len = e->elem_nb;
	e->b_len = 0;
	fill_piles(pile_a, pile_b, e);
	ft_lstdel(&e->lst, ft_deltab);
}