/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 09:44:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/08 19:41:25 by rpinoit          ###   ########.fr       */
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
		quicksort(&e);
		littlesort(&e);
		insertionsort(&e);
		stack_cleaner(e.a, e.b);
	}
	else
		ft_putendl("usage: ./push_swap + integer argument(s)");
	return (0);
}
