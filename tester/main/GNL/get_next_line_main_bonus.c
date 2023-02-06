/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:43:31 by wdelaros          #+#    #+#             */
/*   Updated: 2022/12/01 08:44:47 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	gnlb_check(int norm)
{
	int	verif[3];
	int	i;

	i = 0;
	verif[0] = open(GNLB_C, O_RDONLY);
	verif[1] = open(GNLUB_C, O_RDONLY);
	verif[2] = open(GNLB_H, O_RDONLY);
	printf("looking for files  ");
	while (i++ < 3)
	{
		usleep(200000);
		printf(YEL"."WHT);
	}
	if (verif[0] < 0 || verif[1] < 0 || verif[2] < 0)
	{
		printf(RED"\nMissing file:	\n");
		if (verif[0] < 0)
			printf("	"RED GNLB_C"\n"WHT);
		if (verif[1] < 0)
			printf("	"RED GNLUB_C"\n"WHT);
		if (verif[2] < 0)
			printf("	"RED GNLB_H"\n"WHT);
		printf("\n");
		return (-1);
	}
	printf(GRN"\nNo files missing, ready to go!\n"WHT);
	if (system("norminette " GNLB_C " " GNLB_H " " GNLUB_C) > 0)
	{
		norm = 1;
		printf(YEL "NORM ERROR !\n"WHT);
	}
	close(verif[0]);
	close(verif[1]);
	close(verif[2]);
	return (norm);
}

void	gnlb_partial_tester(int buff, char *test)
{
	char	*txt;
	char	*cmd;
	int		norm;

	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = gnlb_check(0);
	if (norm < 0)
		return ;
	//
	cmd = combine(GCCF GNL_PATH_O "test1.out "GNLB_C" "GNLUB_C" -D BUFFER_SIZE=%d ", buff);
	system(cmd);
	free(cmd);
	//
	if (!strcmp(test, "pp"))
		txt = f_strjoin("./test1.out", " tester/text/peepy.ans");
	else
		txt = ft_str_ffront_join("./test1.out", combine(" tester/text/%s.txt", test));
	system(txt);
	free(txt);
	//
	if (system(GCCF" -o val_test.out -g "VAL_GNL) == 0)
	{
		txt = combine(VALL " ./val_test.out tester/text/%s.txt", test);
		if (system(txt) != 0)
		{
			free(txt);
			printf(RED"valgrind could not run\n"WHT);
			txt = combine("leaks -atExit -- ./val_test.out tester/text/%s.txt", test);
			system("leaks -atExit -- ./val_test.out");
		}
	}
	free(txt);
	system("rm -rf val_test.out val_test.out.dSYM test1.out");
	if (norm != 0)
		printf(YEL "NORM ERROR !\n"WHT);
	else
		printf(GRN "NORM OK !\n"WHT);
	return ;
}

void	gnlb_tester(int buff)
{
	char	*txt;
	char	*cmd;
	int		norm;
	int		i;

	i = 2;
	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = gnlb_check(0);
	if (norm < 0)
		return ;
	cmd = combine(GCCF GNLB_PATH_O "test1.out "GNLB_C" "GNLUB_C" -D BUFFER_SIZE=%d ", buff);
	printf("\n\n-	-	-\n"YEL"Normal test"WHT"\n-	-	-\n\n");
	system(cmd);
	free(cmd);
	//
	//txt = f_strjoin("./test1.out", " tester/text/peepy.ans");
	txt = f_strjoin("./test1.out", " ");
	while (i < 9) // 9
		txt = ft_str_ff_join(txt, combine(" tester/text/text%d.txt", i++));
	//combine 
	system(txt);
	if (system(GCCF" -o val_test.out -g "VAL_GNLB) == 0)
	{
		if (system(VALL" ./val_test.out tester/text/peepy.ans") != 0)
		{
			printf(RED"valgrind could not run\n"WHT);
			system("leaks -atExit -- ./val_test.out");
		}
	}
	system("rm -rf val_test.out val_test.out.dSYM test1.out");
	if (norm != 0)
		printf(YEL "NORM ERROR !\n"WHT);
	else
		printf(GRN "NORM OK !\n"WHT);
	free(txt);
	return ;
}

//gccf get_next_line_main.c main_utils.c -D LEAK=1