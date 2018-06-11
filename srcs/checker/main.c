/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/11 16:16:09 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int		main(int argc, char **argv)
{
	t_env		e;
	t_visual	v;

	if (argc > 1)
	{
		e.argv = argv;
		env_init(&e, 0);
		parse_bonus(&e);
		parse_params(&e, --e.argv);
		if (e.visual == TRUE)
			init_sdl(&v);
		operation_getter(&e);
		sort_verifier(&e);
		if (e.number == TRUE)
			ft_putnbr(e.op_nb);
		if (e.visual == TRUE)
			SDL_Quit();
	}
	else
		ft_putendl("usage: ./checker + integer argument(s)");
	return (0);
}
