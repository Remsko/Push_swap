/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:47:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/05 15:15:05 by rpinoit          ###   ########.fr       */
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

t_bool param_check(char *p)
{
    size_t  len;
    int     diff;
    t_bool  neg;

    neg = (p[0] == '-');
    len = ft_strlen(p) - neg;
    if (number_check(p + neg, len) == FALSE)
        return (FALSE);
    if (len < 10)
        return (TRUE);
    else if (len > 10)
        return (FALSE);
    else
    {
        diff = neg ? ft_strcmp(p, "-2147483648") : ft_strcmp(p, "2147483647");
        return (diff <= 0 ? TRUE : FALSE);
    }
}

t_bool  duplicate_check(char **av)
{
    int i;
    int j;

    i = 0;
    while (av[i])
    {
        j = 0;
        while (av[j])
        {
            if (i != j && ft_strcmp(av[i], av[j]) == 0)
                return (FALSE);
            ++j;
        }
        ++i;
    }
    return (TRUE);
}

int main(int ac, char **av)
{
    char **save;

    save = av;
    if (ac > 1)
    {
        while (--ac > 0)
        {
            if (param_check(*(++av)) == FALSE)
                return (puterror());
        }
        if (duplicate_check(save) == FALSE)
            return (puterror());
    }
    else
        ft_putendl("Usage: ./checker + numbers");
}