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
	char	a;
	void	*p;
	int		char_nb;
	char	*s;

	(void)ac;
	char_nb = 0;
	s = NULL;
	p = NULL;
	a = 'a';
	if (av[1][0] == 'r')
		char_nb = printf(IN_TEST);
	else if (av[1][0] == 'f')
		char_nb = ft_printf(IN_TEST);
	else
		printf("%p %p %s", &a, &p, s);
	printf("\n	[printf output=%d]", char_nb);
	return (0);
}
