/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 07:25:09 by wdelaros          #+#    #+#             */
/*   Updated: 2022/12/01 13:53:26 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	check_ft_printf(int norm)
{
	int	verif[2];
	int	i;

	i = 0;
	verif[0] = open(FT_PRINTF"/Makefile", O_RDONLY);
	verif[1] = open(FT_PRINTF"/ft_printf.c", O_RDONLY);
	printf("looking for files  ");
	while (i++ < 3)
	{
		usleep(200000);
		printf(YEL"."WHT);
	}
	if (verif[0] < 0 || verif[1] < 0)
	{
		printf(RED"\nMissing file: ");
		if (verif[0] < 0)
			printf(RED "Makefile "WHT);
		if (verif[1] < 0)
			printf(RED "ft_printf.c"WHT);
		printf("\n");
		return (-1);
	}
	printf(GRN"\nNo files missing, ready to go!\n"WHT);
	system("echo "WHT);
	if (system("norminette " FT_PRINTF) > 0)
	{
		norm = 1;
		printf(YEL "NORM ERROR !\n"WHT);
	}
	close(verif[0]);
	close(verif[1]);
	return (norm);
}

void	printf_tester(void)
{
	int	fd;
	check_ft_printf(0);
	system("(make re -C ft_printf >> .log.txt)");
	fd = open("ft_printf/libftprintf.a", O_RDONLY);
	if (fd < 0)
	{
		printf(RED"can't find libftprintf.a\n"WHT);
		return ;
	}
	system(GCCF" ft_printf/libftprintf.a tester/PRINTF/PF_main.c");
	system("./a.out");
	//system("rm a.out");
	return ;
}