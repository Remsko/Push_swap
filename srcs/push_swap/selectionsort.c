/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:37:19 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/04 18:44:00 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void    move_for(t_env *e, int nb)
{
    (void)e;
    (void)nb;
}

int     move_cost(t_env *e, int nb)
{
    int op_nb;

    op_nb = 0;
    (void)e;
    (void)nb;
    return (op_nb);
}

void    pile_rotate(t_env *e)
{
    int     index;
    int     rotate;
    t_bool  reverse;

    reverse = FALSE;
    index = 0;
    while (e->a[index] != 1)
        ++index;
    if (index > e->elem_nb / 2)
        rotate = e->elem_nb - index;
    else
    {
        reverse = TRUE;
        rotate = index;
    }
    while (index--)
        reverse == TRUE ? rra(e) : ra(e);
}

void    selectionsort(t_env *e)
{
    int tmp;
    int op_nb;
    int nb;

    nb = 0;
    op_nb = 0;
    if (e->b_len == 0)
        return (pile_rotate(e));
    /* calculate move cost per elements */
    while (nb < e->b_len)
    {
        /* get the chipest index */
        if ((tmp = move_cost(e, nb)) > op_nb)
            nb = tmp;
        ++nb;
    }
    /* do the moves for the index */
    move_for(e, nb);
    /* repeat until b is not empty */
    selectionsort(e);
}