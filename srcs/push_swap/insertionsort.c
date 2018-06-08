/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:37:19 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/08 15:48:59 by rpinoit          ###   ########.fr       */
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

t_stack_nb  get_closest_upper(t_env *e, t_stack_nb *actual)
{
    t_stack_nb  next;
    int         index;

    index = 0;
    next.index = 0;
    next.nb = 0x7FFFFFFF;
    while (index < e->a_len)
    {
        if (e->a[index] > actual->nb && e->a[index] < next.nb)
        {
            next.index = index;
            next.nb = e->a[index];
        }
        else
            ++index;
    }
    return (next);
}

void    rotate_until(t_env *e, int until, t_bool reverse, char stack_id)
{
    while (until)
    {
        if (reverse == TRUE)
        {
            if (stack_id == 'a')
                rra(e);
            else if (stack_id == 'b')
                rrb(e);
            else
                rrr(e);
        }
        else
        {
            if (stack_id == 'a')
                ra(e);
            else if (stack_id == 'b')
                rb(e);
            else
                rr(e);
        }
        --until;
    }
}

int     move_for(t_env *e, t_stack_nb *actual, t_stack_nb *next, t_bool do_op)
{
    int     op;

    op = 0;
    int middle_a = e->a_len / 2;
    int middle_b = e->b_len / 2;

    int rotate_a;
    int rotate_b;

    t_bool reverse_a = FALSE;
    t_bool reverse_b = FALSE;

    if (actual->index < middle_b)
        rotate_b = actual->index; 
    else
    {
        rotate_b = e->b_len + (e->b_len % 2 != 0) - actual->index;
        reverse_b = FALSE;
    }
    if (next->index < middle_a)
        rotate_a = next->index;
    else
    {
        rotate_a = e->a_len + (e->a_len % 2 != 0) - next->index;
        reverse_a = FALSE;
    }
    if (do_op == TRUE)
    {
        rotate_until(e, rotate_a, reverse_a, 'a');
        rotate_until(e, rotate_b, reverse_b, 'b');
        pa(e);
    }
    else
    {
        op += rotate_a;
        op += rotate_b;
        ++op;
    }
    return (op);
}

int     move_cost(t_env *e, t_stack_nb *actual, t_stack_nb *next)
{
    int op_nb;

    op_nb = move_for(e, actual, next, FALSE);
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
        rotate = e->elem_nb + (e->elem_nb % 2 != 0) - index;
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
    t_stack_nb final;
    t_stack_nb actual;
    t_stack_nb next;
    int index;
    int op_nb;
    int tmp;

    tmp = 0;
    index = 0;
    op_nb = 0x7FFFFFFF;
    /* debug stop */
    //if (turn == 5)
    //    return ;
    if (e->b_len == 0)
        return /*pile_rotate(e)*/;
    /* calculate move cost per elements */
    while (index < e->b_len)
    {
        /* get the chipest nb at the pointed index */
        actual = (t_stack_nb){e->b[index], index};
        next = get_closest_upper(e, &actual);
        if ((tmp = move_cost(e, &actual, &next)) < op_nb)
        {
            op_nb = tmp;
            final = actual;
        }
        ++index;
    }
    //printf("nb %d \t index %d\n", nb, index);
    t_stack_nb final_next = get_closest_upper(e, &final);
    /* do the moves for the index */
    //printf("nb = %d \t index = %d\n", final.nb, final.index);
    //printf("nb = %d \t index = %d\n", final_next.nb, final_next.index);
    //for(int i = 0; i < e->elem_nb; i++)
    //    printf("%d \t %d\n", e->a[i], e->b[i]);
    move_for(e, &final, &final_next, TRUE);
    /* repeat until b is not empty */
    insertionsort(e, turn + 1);
}