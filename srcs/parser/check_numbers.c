/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_numbers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 15:48:11 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/08 19:18:30 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static t_bool	ft_isstrdigit(char *p, size_t len)
{
	while (ft_isdigit((int)*p++))
		--len;
	return (len ? FALSE : TRUE);
}

static t_bool	number_checker(char *nb)
{
	size_t	len;
	int		diff;
	t_bool	neg;

	neg = (nb[0] == '-');
	if (neg && ft_isdigit((int)nb[1]) == 0)
		ft_error(9);
	len = ft_strlen((nb)) - neg;
	if (ft_isstrdigit(nb + neg, len) == FALSE)
		return (FALSE);
	if (len < 10)
		return (TRUE);
	else if (len > 10)
		return (FALSE);
	else
	{
		diff = neg ? ft_strcmp(nb, "-2147483648") : ft_strcmp(nb, "2147483647");
		return (diff <= 0 ? TRUE : FALSE);
	}
}

void			check_numbers(t_env *e)
{
	char	**split;
	t_list	*tmp;

	tmp = e->lst;
	while (tmp)
	{
		split = (char**)tmp->content;
		while (*split)
		{
			if (number_checker(*split++) == FALSE)
			{
				ft_lstdel(&e->lst, &ft_deltab);
				ft_error(3);
			}
		}
		tmp = tmp->next;
	}
}
