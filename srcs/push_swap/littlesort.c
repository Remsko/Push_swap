/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littlesort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 16:15:13 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/04 16:29:34 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_bool  a_sorted(t_env *e)
{
    int i;

    i = 0;
    while (i < e->a_len - 1)
    {
        if (e->a[i] < e->a[i + 1])
            ++i;
        else
            return (FALSE);
    }
    return (TRUE);
}

void    littlesort(t_env *e)
{
    while (a_sorted(e) == FALSE)
    {
        if (e->a_len == 2)
            sa(e);
        else
        {
            if (e->a[1] < e->a[0] && e->a[1] < e->a[2])
                e->a[0] < e->a[2] ? sa(e) : ra(e);
            else if ((e->a[1] < e->a[0] || e->a[1] < e->a[2]) && e->a[0] > e->a[2])
                sa(e);
            else
                rra(e);
        }
    }
}