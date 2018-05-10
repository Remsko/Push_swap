/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 17:28:29 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int     main(int argc, char **argv)
{
    t_env   e;

    if (argc > 1)
    {
        e = (t_env){.argc = argc, .argv = argv, .elem_nb = 0};
        parse_params(&e);
        operation_getter(&e);
        sort_verifier(&e);
    }
    else
        ft_putendl("usage: /checker + numbers");
    return (0);
}