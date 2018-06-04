/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 09:44:17 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/04 17:01:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int     main(int argc, char **argv)
{
    t_env   e;

    if (argc > 1)
    {
        e = (t_env){.argc = argc, .argv = argv, .elem_nb = 0, .a_len = 0,
                    .b_len = 0, .print = TRUE, .lst = NULL, .a = NULL, .b = NULL};
        parse_params(&e);
        quicksort(&e);
        littlesort(&e);
        selectionsort(&e);
        free(e.a);
        free(e.b);
    }
    else
        ft_putendl("usage: ./push_swap + integer argument(s)");
    return (0);
}