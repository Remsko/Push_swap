/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:37:19 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/06 14:48:49 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int     get_nb_index(int *stack, int len, int nb)
{
    int index;

    index = 0;
    while (index < len)
    {
        if (stack[index] == nb)
            break ;
        else
            ++index;
    }
    return (index);
}

int     closest_upper(t_env *e, int nb)
{
    int index;
    int tmp;

    index = 0;
    tmp = 0x7FFFFFFF;
    while (index < e->a_len)
    {
        if (e->a[index] > nb && e->a[index] < tmp)
            tmp = e->a[index];
        else
            ++index;
    }
    return (e->a[tmp]);
}

void    move_for(t_env *e, int nb)
{
    int     rotate;
    int     index;
    int     next;
    t_bool  reverse;

    reverse = FALSE;
    index = get_nb_index(e->b, e->b_len, nb);
    next = closest_upper(e, nb);
    if (index > e->b_len / 2)
        rotate = e->b_len - index;
    else
    {
        reverse = TRUE;
        rotate = index - 1;
    }
    while (rotate--)
        reverse == TRUE ? rrb(e) : rb(e);
    pa(e);
}

int     move_cost(t_env *e, int nb)
{
    int op_nb;

    op_nb = 0x7FFFFFFF;
    if (nb != 96)
        op_nb = 1;
    (void)e;
    (void)nb;
    return (op_nb);
}

void    pile_finalrotate(t_env *e)
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
    while (rotate--)
        reverse == TRUE ? rra(e) : ra(e);
}

void    insertionsort(t_env *e, int turn)
{
    int index;
    int tmp;
    int op_nb;
    int nb;

    nb = 0;
    index = 0;
    op_nb = 0x7FFFFFFF;
    /* debug stop */
    if (turn == 1)
    {
        return ;
    }
    if (e->b_len == 0)
        return /*pile_rotate(e)*/;
    /* calculate move cost per elements */
    while (index < e->b_len)
    {
        /* get the chipest nb at the pointed index */
        if ((tmp = move_cost(e, nb)) < op_nb)
            nb = e->b[index];
        ++index;
    }
    //printf("nb %d \t index %d\n", nb, index);
    /* do the moves for the index */
    move_for(e, nb);
    /* repeat until b is not empty */
    insertionsort(e, turn + 1);
}