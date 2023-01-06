/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:48:21 by wdelaros          #+#    #+#             */
/*   Updated: 2022/12/02 13:19:06 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	check_gnl(int norm)
{
	int	verif[3];
	int	i;

	i = 0;
	verif[0] = open(GNL_C, O_RDONLY);
	verif[1] = open(GNLU_C, O_RDONLY);
	verif[2] = open(GNL_H, O_RDONLY);
	printf("looking for files  ");
	while (i++ < 3)
	{
		usleep(200000);
		printf(YEL"."WHT);
	}
	if (verif[0] < 0 || verif[1] < 0 || verif[2] < 0)
	{
		printf(RED"\nMissing file: ");
		if (verif[0] < 0)
			printf(RED GNL_C" "WHT);
		if (verif[1] < 0)
			printf(RED GNLU_C" "WHT);
		if (verif[2] < 0)
			printf(RED GNL_H WHT);
		printf("\n");
		return (-1);
	}
	printf(GRN"\nNo files missing, ready to go!\n"WHT);
	if (system("norminette " GNL_C " " GNL_H " " GNLU_C) > 0)
	{
		norm = 1;
		printf(YEL "NORM ERROR !\n"WHT);
	}
	close(verif[0]);
	close(verif[1]);
	close(verif[2]);
	return (norm);
}

void	gnl_partial_tester(int buff, char *test)
{
	char	*txt;
	char	*cmd;
	int		norm;

	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = check_gnl(0);
	if (norm < 0)
		return ;
	//
	cmd = combine(GCCF GNL_PATH_O "test1.out "GNL_C" "GNLU_C" -D BUFFER_SIZE=%d ", buff);
	printf("\n\n-	-	-\n"YEL"Start test"WHT"\n-	-	-\n\n");
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
		if (!strcmp(test, "pp"))
			txt = combine(VALL " ./val_test.out tester/text/%s.ans", "peepy");
		else
			txt = combine(VALL " ./val_test.out tester/text/%s.txt", test);
		if (system(txt) != 0)
		{
			printf(RED"valgrind could not run\n"WHT);
			free(txt);
			if (!strcmp(test, "pp"))
				txt = combine("leaks -atExit -- ./val_test.out tester/text/%s.ans", "peepy");
			else
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

void	gnl_tester(int buff)
{
	char	*txt;
	char	*cmd;
	int		norm;
	int		i;

	i = 0;
	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = check_gnl(0);
	if (norm < 0)
		return ;
	cmd = combine(GCCF GNL_PATH_O "test1.out "GNL_C" "GNLU_C" -D BUFFER_SIZE=%d ", buff);
	system(cmd);
	free(cmd);
	txt = f_strjoin("./test1.out", " tester/text/peepy.ans");
	while (i < 9)
		txt = ft_str_ff_join(txt, combine(" tester/text/text%d.txt", i++));
	system(txt);
	if (system(GCCF" -o val_test.out -g "VAL_GNL) == 0)
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

int		gnl_mem(int test)
{
	int		BS = 1;
	char	*cmd, *info;
	int 	loop = 1;

	system("echo " WHT);
	if (test == 0)
	{
		
		//test 0
		system("echo 'start mem verif\n' >> tester/GNL/GNL_dif.txt");
		cmd = combine(GCCF " tester/main/GNL/val_gnl_mem.c -o mem_test.out "GNL_C" "GNLU_C" -D BUFFER_SIZE=%d  -D TEST_NB=%d ", BS, 0);
		system(cmd);
		system(VALL" ./mem_test.out");
		free(cmd);
		//test 1
		cmd = combine(GCCF " tester/main/GNL/val_gnl_mem.c -o mem_test.out "GNL_C" "GNLU_C" -D BUFFER_SIZE=%d  -D TEST_NB=%d ", BS, 2);
		system(cmd);
		system(VALL" ./mem_test.out");
		free(cmd);
		system("rm ./mem_test.out");
	}
	else if (test == 1)
	{
		system("echo 'invalid fd test' >> tester/GNL/GNL_dif.txt");
		cmd = combine(GCCF " tester/main/GNL/val_gnl_mem.c -o mem_test.out "GNL_C" "GNLU_C" -D BUFFER_SIZE=%d  -D TEST_NB=%d ", 1, 1);
		system(cmd);
		system("./mem_test.out");
		free(cmd);
		system("rm ./mem_test.out");
	}
	else
	{
		system("echo 'start loop test' >> tester/GNL/GNL_dif.txt");
		while (loop < 10000000)
		{
			printf("test with buffer: %d\n", loop);
			info = combine("echo 'BUFFER_SIZE %d' >> tester/GNL/GNL_dif.txt", loop);
			system(info);
			free(info);
			gnl_partial_tester(loop,"text4");
			loop *= 2;
		}
		info = combine("echo 'BUFFER_SIZE %d' >> tester/GNL/GNL_dif.txt", 10000000);
		system(info);
		free(info);
		gnl_partial_tester(10000000,"text4");
	}
	return (0);
}



//gccf get_next_line_main.c main_utils.c -D LEAK=1

//work on timer ft
