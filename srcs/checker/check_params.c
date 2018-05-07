/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:08:41 by remsko            #+#    #+#             */
/*   Updated: 2018/05/07 14:56:54 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

#include <stdio.h>
void    check_params(t_env *e)
{
    stock_numbers(e);
    ft_lstdel(&e->lst, ft_deltab);
}