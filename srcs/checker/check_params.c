/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 22:08:41 by remsko            #+#    #+#             */
/*   Updated: 2018/05/07 17:53:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void    check_params(t_env *e)
{
    stock_numbers(e);
    check_numbers(e);
    create_piles(e);
    check_duplicate(e);
}