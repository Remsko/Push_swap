/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_verifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 17:28:46 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/10 17:38:35 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	sort_verifier(t_env *e)
{
	int		i;
	t_bool	answer;

	i = 0;
	answer = e->b_len > 0 ? FALSE : TRUE;
	while (i + 1 < e->elem_nb)
	{
		if (e->a[i] > e->a[i + 1])
		{
			answer = FALSE;
			break ;
		}
		else
			++i;
	}
	free(e->a);
	free(e->b);
	return (answer ? ft_putendl("OK") : ft_putendl("KO"));
}