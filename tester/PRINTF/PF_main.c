/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PF_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:08:23 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/01 21:08:23 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PRINTF.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;
	char	a;
	int		p;
	int		char_nb;

	p = 42;
	a = 'a';
	if (av[1][0] == 'r')
		char_nb = printf IN_TEST;
	else if (av[1][0] == 'f')
		char_nb = ft_printf IN_TEST;
	else
		printf("%p %p ", &a, &p);
	printf("\n	[printf output=%d]", char_nb);
	return (0);
}