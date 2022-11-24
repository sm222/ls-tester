/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:48:21 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/24 17:51:50 by anboisve         ###   ########.fr       */
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
	int		fd[3];
	char	*tmp;
	int		i;
	int		norm;

	logo();
	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = check(ac, av, norm);
	system(GCCF" -o val_test.out get_next_line_utils.c get_next_line.c val_gnl_main.c");
	system("valgrind --leak-check=full ./val_test.out");
	system("rm val_test.out");
	fd[0] = open("text/peepy.ans", O_RDONLY);
	fd[1] = open("text/text1.txt", O_RDONLY);
	fd[2] = open("text/text2.txt", O_RDONLY);
	i = 0;
	tmp = "\n";
	while (tmp)
	{
		tmp = get_next_line(fd[INDEX]);
		printf(GRN"%d."WHT" = %s", i + 1, tmp);
		xfree(tmp);
		i++;
	}
	printf(WHT"\ntime call -- %d\n", i);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
	if (norm != 0)
		printf(YEL "NORM ERROR !\n"WHT);
	else
		printf(GRN "NORM OK !\n"WHT);
}
