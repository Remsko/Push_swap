/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 13:59:35 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/11 15:17:01 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void boolean_init(t_env *e, char *argv)
{
    int i;

    i = 1;
    if (argv[i])
    {
        while (argv[i])
        {
            if (argv[i] == 'v')
                e->visual = TRUE;
            else if (argv[i] == 'n')
                e->number = TRUE;
            else
                ft_error(999);
            ++i;
        }
    }
    else
        ft_error(998);
}
void parse_bonus(t_env *e)
{
    while (e->argv && *(++e->argv) != NULL)
    {
        if (**(e->argv) == '-')
            boolean_init(e, *(e->argv));
        else
            return ;
    }
}