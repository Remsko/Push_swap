/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 21:50:22 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/14 11:05:15 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

# include <SDL.h>
# include "types.h"
# include "proto.h"
# include "operations.h"
# include "parser.h"

# define WIN_W 1500
# define WIN_H 1000

void	sdl_init(t_visual *v);
void	draw_visu(t_env *e, t_visual *v);
void	sdl_event(t_visual *v, t_bool loop);
void	sdl_destroy(t_visual *v);

#endif
