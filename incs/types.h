/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 12:06:51 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "push_swap.h"

typedef struct		s_visual
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
    SDL_Texture		*texture;
	SDL_Event		event;
}					t_visual;

typedef struct	s_env
{
	char	**argv;
	t_list	*lst;
	int		*a;
	int		*b;
	int		elem_nb;
	int		op_nb;
	int		a_len;
	int		b_len;
	t_bool	print;
	t_bool	number;
	t_bool	visual;
}				t_env;

typedef struct	s_rotation
{
	int		a;
	int		b;
	int		both;
	t_bool	rev_a;
	t_bool	rev_b;
	t_bool	rev_both;
}				t_rotation;

typedef struct	s_stack_nb
{
	int		nb;
	int		index;
}				t_stack_nb;

#endif
