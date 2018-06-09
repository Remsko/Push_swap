/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/09 18:11:04 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		main(int argc, char **argv)
{
	t_env	e;

	if (argc > 1)
	{
		env_init(&e, 0);
		parse_params(&e, argv);
		operation_getter(&e);
		sort_verifier(&e);
		ft_putnbr(e.op_nb);
	}
	else
		ft_putendl("usage: ./checker + integer argument(s)");
	return (0);
}
