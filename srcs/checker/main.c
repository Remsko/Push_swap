/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/13 19:15:22 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int     main(int argc, char **argv)
{
    t_env   e;

    if (argc > 1)
    {
        e = (t_env){.argc = argc, .argv = argv, .elem_nb = 0, .op_nb = 0,
        .a_len = 0, .b_len = 0, .print = FALSE, .lst = NULL, .a = NULL, .b = NULL};
        if (ft_strcmp(argv[1], "-v") && (++e->argv))
            e.visual = TRUE;
        parse_params(&e);
        operation_getter(&e);
        sort_verifier(&e);
        ft_putnbr(e.op_nb);
    }
    else
        ft_putendl("usage: ./checker + integer argument(s)");
    return (0);
}