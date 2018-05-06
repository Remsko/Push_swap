/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: remsko <remsko@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:08:41 by remsko            #+#    #+#             */
/*   Updated: 2018/05/06 23:07:13 by remsko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void    check_params(t_env *e)
{
    char    **split;
    t_list  *new;

    while (e->argv != NULL)
    {
        split = ft_strsplit(*e->argv++, ' ');
        if (e->elem_nb == 0)
        {
            if (!(e->lst = (t_list*)malloc(sizeof(t_list))))
                ft_exit(1);
            e->lst->content = (void *)split;
            e->lst->content_size = ft_tablen(split);
            e->lst->next = NULL;
        }
        else
        {
            if (!(new = (t_list*)malloc(sizeof(t_list))))
            {
                ft_lstdel(&e->lst, ft_deltab);
                ft_exit(2);
            }
            ft_lstadd(&e->lst, new);
            e->lst->content = (void *)split;
            e->lst->content_size = ft_tablen(split);
        }
    }
}