/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:48:21 by wdelaros          #+#    #+#             */
/*   Updated: 2023/04/09 20:46:42 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int	check_gnl(void)
{
	int	verif[3];
	int	i;
	int	norm;

	i = 0;
	norm = 0;
	sm_putstr("looking for files", 2);
	while (i++ < 3)
	{
		usleep(200000);
		sm_putstr(YEL"."WHT, 2);
	}
	verif[0] = access(GNL_C, F_OK | R_OK);
	verif[1] = access(GNLU_C, F_OK | R_OK);
	verif[2] = access(GNL_H, F_OK | R_OK);
	if (verif[0] < 0 || verif[1] < 0 || verif[2] < 0)
	{
		sm_putstr(RED"\nMissing file:	\n", 2);
		if (verif[0] < 0)
			sm_putstr("	"RED GNL_C"\n"WHT, 2);
		if (verif[1] < 0)
			sm_putstr("	"RED GNLU_C"\n"WHT, 2);
		if (verif[2] < 0)
			sm_putstr("	"RED GNL_H"\n"WHT, 2);
		sm_putstr(WHT"\n", 2);
		return (-1);
	}
	sm_putstr(GRN"\nNo files missing, ready to go!\n"WHT, 2);
	if (system("norminette " GNL_C " " GNL_H " " GNLU_C) > 0)
	{
		norm = 1;
		sm_putstr(YEL "NORM ERROR !\n"WHT, 2);
	}
	sm_putstr(WHT, 2);
	return (norm);
}

void	gnl_partial_tester(int buff, char *test)
{
	char	*txt;
	char	*cmd;
	int		norm;

	norm = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	norm = check_gnl();
	if (norm < 0)
		return ;
	//
	cmd = combine(GCCF GNL_PATH_O "test1.out "GNL_C" "GNLU_C " -D BUFFER_SIZE=%d ", buff);
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
	norm = check_gnl();
	if (norm < 0)
		return ;
	gnl_mem(1, 100);
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

int		gnl_mem(int test,int BS)
{
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
	system("rm -fr mem_test.out.dSYM");
	//ici
	return (0);
}

//gccf get_next_line_main.c main_utils.c -D LEAK=1
//work on timer ft

void	new_gnl_test(t_define_in *data)
{
	int			i;
	char		*tmp;
	char		*tmp2;
	char		*path;
	char		**setting_file;
	int			fd_set_file;
	t_define_in	*data_tmp;

	tmp = NULL;
	tmp2 = NULL;
	path = NULL;
	setting_file = NULL;
	printf("\n\n\n");
	printf("welcome in Gnl tester !\n");
	//look for gnl file
	if (check_gnl() == -1)
		return ;
	tmp = combine(GCCF" tester/ls_gnl.c "GNL_C" "GNLU_C" tester/GNL/GNL_mainV2.c "SM_FT" " LS_PF " .."C_TOOLS" ");
	ls_printf(1, "%s\n", tmp);
	//		*		*		*//
	// add the setting
	while(data)
	{
		data_tmp = data;
		if (data->cmd)
		{
			tmp2 = combine("%s -D %s=%d", tmp, data->cmd, data->size);
			sm_free(tmp);
			tmp = tmp2;
		}
		data = data->next;
		sm_free(data_tmp->cmd);
		sm_free(data_tmp);
	}
	//ls_printf(1, "%s\n", tmp);
	/*
	0 = off
	1 = on
	//	//	//
	LS_FULL_TEST
	LS_INSP_TEST
	LS_RMFILE
	LS_SPEED= "1/10"
	LS_STYLE
	*/
	//-o gnl.out
	tmp2 = combine("%s -o gnl.out", tmp);
	system(tmp2);
	tmp2 = sm_free(tmp2);
	tmp =  sm_free(tmp);
	fd_set_file = open("tester/.settings.data", O_RDONLY);
	if (fd_set_file == -1)
	{
		printf(RED"can't open \".settings.data\"\n"WHT);
		return ;
	}
	tmp2 = "ls-tester";
	while (tmp2)
	{
		tmp2 = sm_get_next_line(fd_set_file);
		if (tmp2)
			tmp = ft_str_ff_join(tmp, tmp2);
	}
	setting_file = ft_split(tmp, '\n');
	tmp = sm_free(tmp);
	i = 0;
	while (sm_strncmp("GNL={", setting_file[i], 5) != 0)
	{
		i++;
		if (setting_file[i] == NULL)
		{
			ls_printf(2 , RED"can't find 'GNL={' in .settings.data"WHT"\n");
			return ;
		}
	}
	while (setting_file[i])
	{
		if (sm_strncmp(setting_file[i], "PATH=", 5) == 0)
		{
			if (path)
				free(path);
			path = sm_str_dup(setting_file[i] + 5);
			sm_putstr("new path ", 2);
			sm_putstr(path, 2);
			sm_putstr("\n", 2);
		}
		if (setting_file[i][0] == '\t')
		{
			tmp = combine("./gnl.out %s%s", path ,setting_file[i] + 1);
			system(tmp);
			sm_free(tmp);
			sleep(1);
			printf("\n\n\n");
		}
		if (setting_file[i][0] == '}')
			break ;
		i++;
	}
	printf("\n");
	tmp = combine(GCCF " " GNL_C " " GNLU_C " tester/main/GNL/val_gnl_main.c -D BUFFER_SIZE=1 -o gnl.out");
	system(tmp);
	sm_free(tmp);
	tmp = combine("valgrind -s ./gnl.out tester/text/text5.txt");
	system(tmp);
	sm_free(tmp);
	system("rm -f gnl.out");
}

//ls-tester\tester\GNL\GNL_mainV2.c