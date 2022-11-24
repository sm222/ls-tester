/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 09:00:26 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/24 09:28:59 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	if (ft_printf(YEL"[%s]\n", "%s"))
	{
		ft_printf(GRN"1. ");
		if (ft_printf("[%s]", "a") != 3)
			printf(RED" = [KO]\n");
		else
			printf(GRN" = [OK]\n");
	}
}