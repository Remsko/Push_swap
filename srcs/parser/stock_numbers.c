/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 12:52:13 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/08 18:55:38 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void fill_lst(t_env *e, char **split)
{
    e->lst->content = (void *)split;
    e->lst->content_size = ft_tablen(split);
    e->elem_nb += e->lst->content_size - 1;
}

void        stock_numbers(t_env *e, char **argv)
{
    char    **split;
    t_list  *new;

    while (*(++argv) != NULL)
    {
        split = ft_strsplit(*(argv), ' ');
        if (e->elem_nb == 0)
        {
            if (!(e->lst = (t_list*)malloc(sizeof(t_list))))
                ft_error(1);
            fill_lst(e, split);
            e->lst->next = NULL;
        }
        else
        {
            if (!(new = (t_list*)malloc(sizeof(t_list))))
            {
                ft_lstdel(&e->lst, ft_deltab);
                ft_error(2);
            }
            ft_lstadd(&e->lst, new);
            fill_lst(e, split);
        }
    }
    ft_lstrev(&e->lst);
}
