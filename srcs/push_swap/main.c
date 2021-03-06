/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 09:44:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/14 14:58:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void	stack_cleaner(int *a, int *b)
{
	free(a);
	free(b);
}

int			main(int argc, char **argv)
{
	t_env	e;

	if (argc > 1)
	{
		env_init(&e, 1);
		parse_params(&e, argv);
		if (e.a_len > 1 && a_sorted(&e) == FALSE)
		{
			quicksort(&e);
			littlesort(&e);
			insertionsort(&e, 0);
		}
		stack_cleaner(e.a, e.b);
	}
	else
		ft_putendl("usage: ./push_swap + integer argument(s)");
	return (0);
}
