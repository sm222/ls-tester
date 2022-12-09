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

void	gnlb_partial_tester(int buff, char *test)
{
	char	*txt;
	char	*cmd;
	int		norm;

	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	cmd = combine(GCCF GNL_PATH_O "test1.out "GNL_C" "GNLU_C" -D BUFFER_SIZE=%d ", buff);
	system(cmd);
	free(cmd);
	if (!strcmp(test, "pp"))
		txt = f_strjoin("./test1.out", " tester/text/peepy.ans");
	else
		txt = ft_str_ffront_join("./test1.out", combine(" tester/text/%s.txt", test));
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

void	gnlb_tester(int buff)
{
	char	*txt;
	char	*cmd;
	int		norm;
	int		i;

	i = 1;
	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	//norm = check(norm);
	cmd = combine(GCCF GNLB_PATH_O "test1.out "GNLB_C" "GNLUB_C" -D BUFFER_SIZE=%d ", buff);
	system(cmd);
	free(cmd);
	txt = f_strjoin(NULL, "./test1.out");
	while (i < 4)
		txt = ft_str_ff_join(txt, combine(" tester/text/peepy%d.ans", i++));
	//txt = ft_str_fback_join(txt, " > out_test.txt");
	system(txt);//call ./test1.out
	if (system(GCCF" -o val_test.out -g "VAL_GNL) == 0)
	{
		if (system(VALL" ./val_test.out ") != 0)
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