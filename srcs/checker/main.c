/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpinoit <rpinoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 12:47:55 by rpinoit           #+#    #+#             */
/*   Updated: 2018/05/05 16:09:59 by rpinoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include "../../libft/libft.h"

#define MIN -2147483648
#define MAX 2147483647

int puterror(int ret)
{
    ft_putendl("Error");
    printf("ret = %d", ret);
    return (ret);
}

t_bool number_check(char *p, size_t len)
{
    char *tmp;

    tmp = p;
    while (ft_isdigit((int)*p++) && len--)
        ;
    if (len)
    {
        printf("number = %s", tmp);
        printf("len = %zu", len);
    }
    return (len ? FALSE : TRUE);
}

t_bool param_check(char *p)
{
    char    **split;
    size_t  len;
    int     diff;
    t_bool  neg;

    split = ft_strsplit(p); // malloc => need to free
    while (split++)
    {
        neg = (*split[0] == '-');
        len = ft_strlen((*split)) - neg;
        if (number_check(*split + neg, len) == FALSE)
        {
            printf("number error");
            return (FALSE);
        }
        if (len < 10)
            return (TRUE);
        else if (len > 10)
        {
            printf("len error");
            return (FALSE);
        }
        else
        {
            diff = neg ? ft_strcmp(*split, "-2147483648") : ft_strcmp(*split, "2147483647");
            return (diff <= 0 ? TRUE : FALSE);
        }
    }
}

t_bool duplicate_check(char **av)
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
    char **argv;
    int argc;

    argv = av;
    argc = ac;
    if (ac > 1)
    {
        while (--ac > 0)
        {
            if (param_check(*(++av)) == FALSE)
                return (puterror(1));
        }
        if (duplicate_check(argv) == FALSE)
        {
            printf("dublicate\n");
            return (puterror(-1));
        }
    }
    else
        ft_putendl("Usage: ./checker + numbers");
}