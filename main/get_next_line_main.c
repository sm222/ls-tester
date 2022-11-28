/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:48:21 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/28 13:13:41 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

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

void	gnl_tester(void)
{
	char	*tmp;
	char	*txt;
	int		norm;
	int		i;


	i = 0;
	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = check(norm);
	system(GCCF GNL_PATH_O "test1.out "GNL_C" "GNLU_C" -D C=0");
	/*--
	txt = ft_str_ffront_join("./test1.out text",ft_itoa(4));
	txt = ft_str_fback_join(txt, ".txt");
	*/
	txt = f_strjoin("./test1.out", " main/text/peepy.ans");
	while (i < 5)	
		txt = ft_str_ff_join(txt, combine(" main/text/text%d.txt", i++));
	//txt = ft_str_fback_join(txt, " > out_test.txt");
	system(txt);//call ./test1.out
	tmp = "\n";
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