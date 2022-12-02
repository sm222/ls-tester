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

int	check(int norm)
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
			printf(RED"get_next_line.c "WHT);
		if (verif[1] < 0)
			printf(RED"get_next_line_utils.c "WHT);
		if (verif[2] < 0)
			printf(RED"get_next_line.h"WHT);
		printf("\n");
		exit(0);
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
	norm = check(norm);
	cmd = combine(GCCF GNL_PATH_O "test1.out "GNL_C" "GNLU_C" -D BUFFER_SIZE=%d ", buff);
	system(cmd);
	free(cmd);
	if (!strcmp(test, "pp"))
		txt = f_strjoin("./test1.out", " tester/text/peepy.ans");
	else
		txt = ft_str_ffront_join("./test1.out", combine(" tester/text/%s.txt", test));
	//txt = ft_str_fback_join(txt, " > out_test.txt");
	system(txt);//call ./test1.out
	if (system(GCCF" -o val_test.out -g "VAL_GNL) == 0)
	{
		if (system(VALL" ./val_test.out") != 0)
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

void	gnl_tester(int buff)
{
	char	*txt;
	char	*cmd;
	int		norm;
	int		i;

	i = 0;
	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = check(norm);
	cmd = combine(GCCF GNL_PATH_O "test1.out "GNL_C" "GNLU_C" -D BUFFER_SIZE=%d ", buff);
	system(cmd);
	free(cmd);
	txt = f_strjoin("./test1.out", " tester/text/peepy.ans");
	while (i < 9)
		txt = ft_str_ff_join(txt, combine(" tester/text/text%d.txt", i++));
	//txt = ft_str_fback_join(txt, " > out_test.txt");
	system(txt);//call ./test1.out
	if (system(GCCF" -o val_test.out -g "VAL_GNL) == 0)
	{
		if (system(VALL" ./val_test.out") != 0)
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
