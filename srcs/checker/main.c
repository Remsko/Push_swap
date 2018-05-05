/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:47:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/05 14:27:04 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdio.h>
#include    <unistd.h>
#include    <stdlib.h>
#include    <limits.h>
#include    "../../libft/libft.h"

#define MIN -2147483648
#define MAX 2147483647

int puterror()
{
    ft_putendl("Error");
    return (-1);
}

t_bool number_check(char *p, size_t len)
{
    while (ft_isdigit((int)*p++) && len--)
        ;
    return (len ? FALSE : TRUE);
}

t_bool param_checker(char *p)
{
    size_t  len;
    int     diff;
    t_bool  neg;

    len = ft_strlen(p);
    neg = (p[0] == '-');
    if (number_check(p + neg, len) == FALSE)
        return (FALSE);
    if ((len < 10 && !neg) || (len < 11 && neg))
        return (TRUE);
    else if ((len > 10 && !neg) || (len > 11 && neg))
        return (FALSE);
    else
    {
        diff = neg ? ft_strcmp(p, "-2147483648") : ft_strcmp(p, "2147483647");
        return (diff <= 0 ? TRUE : FALSE);
    }
}

int main(int ac, char **av)
{
    if (ac > 1)
    {
        while (--ac > 0)
        {
            if (param_checker(*(++av)) == FALSE)
                return (puterror());
        }
    }
    else
        ft_putendl("Usage: ./checker + numbers");
}