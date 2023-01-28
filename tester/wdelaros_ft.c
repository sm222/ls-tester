/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdelaros_ft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:40:53 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/29 13:44:56 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	peepy_atoi(const char *str)
{
	int	num;
	int	i;
	int	neg;

	num = 0;
	i = 0;
	neg = 1;
	if (!str)
		return (0);
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43)
		i++;
	else if (str[i] == 45)
	{
		neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num *= 10;
		num += str[i] - 48;
		i++;
	}
	return (num * neg);
}

int	intlen(long int n, int base)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > (base - 1))
	{
		n /= base;
		i++;
	}
	return (i);
}