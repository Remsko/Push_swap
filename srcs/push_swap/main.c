/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 09:44:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/11 14:17:40 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int     main(int argc, char **argv)
{
    t_env   e;

    if (argc > 1)
    {
        e = (t_env){.argc = argc, .argv = argv, .elem_nb = 0, .a_len = 0,
                    .b_len = 0, .lst = NULL, .a = NULL, .b = NULL};
        parse_params(&e);
		operations_algo(&e);
    }
    else
        ft_putendl("usage: ./push_swap + integer argument(s)");
    return (0);
}