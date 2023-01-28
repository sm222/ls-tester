/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PF_main_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:02:29 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/08 10:18:54 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
# include "../../ft_printf/ft_printf.h"

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"
# define ORG	"\x1b[38;5;202m"
# define PIK	"\x1b[38;5;176m"
# define CLE 	"\e[1;1H\e[2J"

# ifndef IN_TEST
#  define IN_TEST "%p\n", &ac
# endif

int	main(int ac, char **av)
{
	int	nb[2];

	(void)ac;
	(void)av;
	nb[0] = printf(IN_TEST);
	nb[1] = ft_printf(IN_TEST);
	if (nb[0] != nb[1])
		printf(RED"❌[KO]"WHT"ft_printf return %d and printf return %d\n",nb[1] , nb[0]);
	else
		printf("✅[OK]\n");
	printf("\n");
	return (0);
}
