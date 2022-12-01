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

void	gnl_bonus__tester(int buff)
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

// int	main(void)
// {
// 	int		fd[3];
// 	char	*tmp[3];
// 	int		i;

// 	i = 0;
// 	fd[0] = open("../main/text/text.txt", O_RDONLY);
// 	fd[1] = open("../main/text/text1.txt", O_RDONLY);
// 	fd[2] = open("../main/text/text2.txt", O_RDONLY);
// 	do
// 	{
// 	tmp[0] = get_next_line(fd[0]);
// 	tmp[1] = get_next_line(fd[1]);
// 	tmp[2] = get_next_line(fd[2]);
// 	if (tmp[0])
// 		printf(BLU"[fd-1]"WHT" = %s", tmp[0]);
// 	else if (!tmp[0])
// 		printf(BLU"[fd-1]"YEL" = %s\n", tmp[0]);
// 	xfree(tmp[0]);
// 	if (tmp[1])
// 		printf(RED"[fd-2]"WHT" = %s", tmp[1]);
// 	else if (!tmp[1])
// 		printf(RED"[fd-2]"YEL" = %s\n", tmp[1]);
// 	xfree(tmp[1]);
// 	if (tmp[2])
// 		printf(GRN"[fd-3]"WHT" = %s", tmp[2]);
// 	else if (!tmp[2])
// 		printf(GRN"[fd-3]"YEL" = %s\n", tmp[2]);
// 	xfree(tmp[2]);
// 	printf(WHT"\ntime call -- %d\n", ++i);
// 	} while ((tmp[0] != NULL || tmp[1] != NULL || tmp[2] != NULL));
// 	close(fd[0]);
// 	close(fd[1]);
// 	close(fd[2]);
// }