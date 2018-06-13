/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 17:17:31 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 17:18:28 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void    sdl_destroy(t_visual *v)
{
    SDL_DestroyTexture(v->texture);
    SDL_DestroyRenderer(v->renderer);
    SDL_DestroyWindow(v->window);

    SDL_Quit();
}