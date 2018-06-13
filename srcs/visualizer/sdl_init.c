/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 16:07:19 by rpinoit           #+#    #+#             */
/*   Updated: 2018/06/13 16:17:32 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

static void init(void)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        exit(-1);
    }
}

static void window(t_visual *v)
{
    if ((v->window = SDL_CreateWindow(
            "TEST SDL RPINOIT FENETRE",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            WIN_W,
            WIN_H,
            0)) == NULL)
    {
        ft_putstr("Could not create window: ");
        ft_putendl(SDL_GetError());
        exit(-2);
    }
}

static void image(t_visual *v)
{
    if ((v->renderer = SDL_CreateRenderer(v->window,
            -1,
            SDL_RENDERER_SOFTWARE)) == NULL)
    {
        ft_putstr("Could not create renderer: ");
        ft_putendl(SDL_GetError());
        exit(-3);
    }
}

static void texture(t_visual *v)
{
    if ((v->texture = SDL_CreateTexture(v->renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_TARGET,
            WIN_W,
            WIN_H)) == NULL)
    {
        ft_putstr("Could not create texture: ");
        ft_putendl(SDL_GetError());
        exit(-4);
    }
}

void sdl_init(t_visual *v)
{
    init();
    window(v);
    image(v);
    texture(v);
}