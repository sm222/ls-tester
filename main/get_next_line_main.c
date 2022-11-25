/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:48:21 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/25 09:46:13 by anboisve         ###   ########.fr       */
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

//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main_utils.c get_next_line_main.c

int	main(int ac, char **av)
{
	int		fd[3];
	char	*tmp;
	int		i;
	int		norm;

	logo();
	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	if (ac != 1)
		printf(RED"YES\n"WHT);
	norm = check(ac, av, norm);
	fd[0] = open(TF"peepy.ans", O_RDONLY);
	fd[1] = open(TF"text1.txt", O_RDONLY);
	fd[2] = open(TF"text2.txt", O_RDONLY);
	i = 0;
	tmp = "\n";
	while (tmp)
	{
		tmp = get_next_line(fd[INDEX]);
		printf(GRN"%4d "YEL"%4zu"WHT" = %s", i + 1, ft_strlen(tmp), tmp);
		xfree(tmp);
		i++;
	}
	printf(WHT"\ntotal line read -- %d\n", --i);
	system(GCCF" -o val_test.out "VAL_GNL);
	if (LEAK == 0)
	{	
		if (system(VAL" ./val_test.out") != 0)
			printf(RED"valgrind could not run\n"WHT);
	}
	else
		if (system(VALL" ./val_test.out") != 0)
			printf(RED"valgrind could not run\n"WHT);
	system("rm val_test.out");
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	if (norm != 0)
		printf(YEL "NORM ERROR !\n"WHT);
	else
		printf(GRN "NORM OK !\n"WHT);
}
