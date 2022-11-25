/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:48:21 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/25 16:02:08 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	check(int ac, char **av, int norm)
{
	int	verif[3];
	int	i;

	(void)ac;
	(void)av;
	i = 0;
	verif[0] = open(GNL_C, O_RDONLY);
	verif[1] = open(GNLU_C, O_RDONLY);
	verif[2] = open(GNL_H, O_RDONLY);
	printf("looking for files  ");
	while (i++ < 3)
	{
		sleep(1);
		printf(YEL"."WHT);
	}
	if (verif[0] < 0 || verif[1] < 0 || verif[2] < 0)
	{
		printf(RED"Missing file: ");
		if (verif[0] < 0)
			printf(RED"get_next_line.c "WHT);
		if (verif[1] < 0)
			printf(RED"get_next_line_utils.c "WHT);
		if (verif[2] < 0)
			printf(RED"get_next_line.h"WHT);
		exit(0);
	}
	printf(GRN"\nNo files missing, ready to go!\n"WHT);
	if (system("norminette " GNL_C " " GNL_H " " GNLU_C) > 0)
	{
		norm = 1;
		printf(YEL "NORM ERROR !\n"WHT);
	}
	sleep(1);
	close(verif[0]);
	close(verif[1]);
	close(verif[2]);
	return (norm);
}

int	main(int ac, char **av)
{
	char	*tmp;
	int		norm;

	logo();
	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = check(ac, av, norm);
	system(GCCF" main/GNL/GNL_main.c -o test1.out "GNL_C" "GNLU_C" -D C=0");
	system("./test1.out");
	tmp = "\n";
	if (system(GCCF" -o val_test.out -g "VAL_GNL) == 0)
	{
		if (LEAK == 0)
		{	
			if (system(VAL" ./val_test.out") != 0)
				printf(RED"valgrind could not run\n"WHT);
			else
				goto END;
		}
		else
		{
			if (system(VALL" ./val_test.out") != 0)
				printf(RED"valgrind could not run\n"WHT);
			else
				system("leaks -atExit -- ./val_test.out");
		}
		system("rm val_test.out");
	}
	END:
	if (norm != 0)
		printf(YEL "NORM ERROR !\n"WHT);
	else
		printf(GRN "NORM OK !\n"WHT);
}


//gccf get_next_line_main.c main_utils.c -D LEAK=1