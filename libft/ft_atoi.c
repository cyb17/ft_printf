/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachen <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:48:15 by yachen            #+#    #+#             */
/*   Updated: 2023/05/06 11:19:31 by yachen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_sign(const char *str)
{
	int	i;
	int	c;
	int	sign;

	i = 0;
	c = 0;
	sign = 43;
	while (str[i] == 32 || (str[i] < 14 && str[i] > 8))
		i++;
	while (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			sign = 45;
		i++;
		c++;
	}
	if (c > 1)
		return (0);
	else
		return (sign);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	if (ft_check_sign(str) == 45 || ft_check_sign(str) == 43)
	{
		while (str[i] == 32 || (str[i] < 14 && str[i] > 8))
			i++;
		while (str[i] == 45 || str[i] == 43)
			i++;
		while (str[i] <= '9' && str[i] >= '0')
		{
			nbr = nbr * 10 + (str[i] - 48);
			i++;
		}
	}
	if (ft_check_sign(str) == 45)
		return (nbr * (-1));
	return (nbr);
}
/*
#include <stdio.h>

int	main()
{
	printf("%d", ft_atoi("  		+42"));
}*/
