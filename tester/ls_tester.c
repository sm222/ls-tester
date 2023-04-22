/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:56:56 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/25 11:48:14 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		log_fd;
char	*path;
char	*name;

char	*menu_loop(int *loop, char *call_back)
{
	int		size_i = 80;
	char	u_input[size_i];
	char	copy[size_i];
	//char	temp[size_i];
	int		file;
	int		str_p = 0;
	char	up[4] = {27, 91, 65, 0};

	if (call_back != NULL)
		ls_printf(1, "last command : "YEL "%s\n" WHT, call_back);
	if (ft_memcmp(name, "anboisve", 9) == 0 || ft_memcmp(name, "sm222", 6) == 0)
		ls_printf(1, BLU"%s"WHT"/ls-tester: ", name);
	else
		ls_printf(1, "%s/ls-tester: ", name);
	//						look for recall input					//
	if (call_back && *loop == 1)
	{
		*loop = 0;
		strcpy(u_input, call_back);
		free(call_back);
	}
	else
	{
		*loop = 0;
		sm_get_keybord_input(u_input, size_i);
		sm_clear_str(u_input);
	}
	//							help func							//
	if (sm_func_looking(u_input, "help", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			ls_printf(1, ORG"\n- - - - Help List - - - -\n"WHT);
			ls_printf(1, "val -tuto	shows how to install valgrind\n");
			ls_printf(1, "gnl		GNL tester\n");
			ls_printf(1, "gnlb		GNL tester with BONUS\n");
			ls_printf(1, "pf		PRINTF tester\n");
			ls_printf(1, "norm		norminette all the files\n");
			ls_printf(1, "rm		RM all trace files\n");
			ls_printf(1, "help of (tester name or command) -help - shows help list\n");
			ls_printf(1, "exit or q	exits the program\n");
			ls_printf(1, "\n");
			sm_log(log_fd,"ls-tester", "call help");
		}
		else
		{
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "help "RED"%s " WHT "is not a valid argumant\n", copy);
			sm_log(log_fd,"ls-tester", "call help with invalid argument");
		}
		return (sm_str_dup(u_input));
	}
	//						PRINTF									//
	else if (sm_func_looking(u_input, "pf", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "-help", &str_p) == 0)
		{
			ls_printf(1, ORG"\n- - - - Printf Help List - - - -\n"WHT);
			ls_printf(1, "exit or q - exit the program\n");
			ls_printf(1, "\n");
		}
		else if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call pf");
			put_time_file('s',"tester/PRINTF/PRINTF_dif.txt");
			printf_tester();
			put_time_file('e',"tester/PRINTF/PRINTF_dif.txt");
		}
		else
		{
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "pf "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							GNL									//
	else if (sm_func_looking(u_input, "gnl", &str_p) == 0)
	{
		t_define_in *in = NULL;
		t_define_in *tmp = NULL;
		if (access("tester/GNL/GNL_dif.txt", F_OK | R_OK) != 0)
		{
			ls_printf(1, "making tester/GNL/GNL_dif.txt\n");
			file = open("tester/GNL/GNL_dif.txt", O_CREAT, 0644);
			if (file < 0)
				ls_printf(2, RED"can't make tester/GNL/GNL_dif.txt"WHT);
			else
				close(file);
		}
		if (sm_func_looking(u_input, "-help", &str_p) == 0)
		{
			ls_printf(1, ORG"\n- - - - GNL Help List - - - -\n"WHT);
			ls_printf(1, "-buff	set buffer size (ex: gnl -buff 42)\n");
			ls_printf(1, "-test	run one test (ex: gnl -test 5)\n");
			ls_printf(1, "-mem	run %s test to chek memory\n", VAL);
			ls_printf(1, "-mem+	test multiple BUFFER_SIZE\n");
			ls_printf(1, "-pp	run peepy test\n");
			ls_printf(1, "-dif	show GNL trace file\n");
			ls_printf(1, "-rm	RM GNL trace file\n");
			ls_printf(1, "exit or q - exit the program\n");
			ls_printf(1, "\n");
			sm_log(log_fd,"ls-tester", "call gnl -help");
		}
		else if (sm_func_looking(u_input, "-rm", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call gnl -rm");
			if (!system("rm tester/GNL/GNL_dif.txt"))
				ls_printf(1, RED"GNL_dif.txt, was remove\n"WHT);
			return (sm_str_dup(u_input));
		}
		else if (sm_func_looking(u_input, "-t", &str_p) == 0)
		{
			ls_printf(1, WHT);
			put_time_file('s',"tester/GNL/GNL_dif.txt");
			tmp = make_node_define(LS_FULL_TEST_T, 1);
			if (!look_for_double_node(&in, tmp))
				ls_printf(2, RED"all ready use\n"WHT);
			make_node_def_last(&in, tmp);
			tmp = make_node_define(LS_FULL_TEST_T, 1);
			if (!look_for_double_node(&in, tmp))
				ls_printf(2, RED"all ready use\n"WHT);
			else
				make_node_def_last(&in, tmp);
			new_gnl_test(in);
			put_time_file('e',"tester/GNL/GNL_dif.txt");
		}
		else if (sm_func_looking(u_input, "-dif", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call gnl -dif");
			if (access("tester/GNL/GNL_dif.txt", F_OK | R_OK) == 0)
				ls_printf(1, MAG"tester/GNL/GNL_dif.txt\n"WHT);
			else
				ls_printf(1, RED"GNL_dif.txt, don't exist\n"WHT);
			return (sm_str_dup(u_input));
		}
		else if (sm_func_looking(u_input, "-mem", &str_p) == 0)
		{
			if(!gnl_mem_info())
			{
				put_time_file('s',"tester/GNL/GNL_dif.txt");
				sm_log(log_fd,"ls-tester", "gnl_mem");
				gnl_mem(0, 100);
				put_time_file('e',"tester/GNL/GNL_dif.txt");
			}
		}
		else if (sm_func_looking(u_input, "-mem+", &str_p) == 0)
		{
			gnl_buffer_tester();
			if (!test_take_time())
			{
				put_time_file('s',"tester/GNL/GNL_dif.txt");
				sm_log(log_fd,"ls-tester", "gnl_mem+");
				gnl_mem(2, 100);
				put_time_file('e',"tester/GNL/GNL_dif.txt");
			}
		}
		else if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			put_time_file('s',"tester/GNL/GNL_dif.txt");
			sm_log(log_fd,"ls-tester", "call gnl");
			make_node_def_last(&in, make_node_define(LS_STYLE_T, 3));
			new_gnl_test(in);
			put_time_file('e',"tester/GNL/GNL_dif.txt");
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call gnl 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "gnl "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							GNL_B								//
	else if (sm_func_looking(u_input, "gnlb", &str_p) == 0)
	{
		system("touch tester/GNL/GNLB_dif.txt");
		if (sm_func_looking(u_input, "-help", &str_p) == 0)
		{
			ls_printf(1, ORG"\n- - - - GNLB Help List - - - -\n"WHT);
			ls_printf(1, "-buff	set buffer size (ex: gnl -buff 42)\n");
			ls_printf(1, "-test	run one test (ex: gnl -test 5)\n");
			ls_printf(1, "-dif	show GNLB trace file\n");
			ls_printf(1, "-rm	RM GNLB trace file\n");
			ls_printf(1, "exit or q - exit the program\n");
			ls_printf(1, "\n");
			sm_log(log_fd,"ls-tester", "call gnlb -help");
		}
		else if (sm_func_looking(u_input, "-buff", &str_p) == 0)
		{
			put_time_file('s',"tester/GNL/GNLB_dif.txt");
			sm_log(log_fd,"ls-tester", "call gnlb -buff");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			gnlb_tester(peepy_atoi(copy));
			put_time_file('e',"tester/GNL/GNLB_dif.txt");
		}
		else if (sm_func_looking(u_input, "-rm", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call gnl -rm");
			if (!system("rm tester/GNL/GNLB_dif.txt"))
				ls_printf(1, RED"GNLB_dif.txt, was remove\n"WHT);
			return (sm_str_dup(u_input));
		}
		else if (sm_func_looking(u_input, "-dif", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call gnl -dif");
			if (system("cat tester/GNL/GNLB_dif.txt"))
				ls_printf(1, RED"GNLB_dif.txt, don't exist\n"WHT);
			return (sm_str_dup(u_input));
		}
		else if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			put_time_file('s',"tester/GNL/GNLB_dif.txt");
			sm_log(log_fd,"ls-tester", "call gnlb");
			gnlb_tester(1);
			put_time_file('e',"tester/GNL/GNLB_dif.txt");
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call gnlb 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "gnlb "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							NORMINETTE							//
	else if (sm_func_looking(u_input, "norm", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call norminette");
			ls_printf(1, BLU"\n-	"GRN"-	"RED"-	\n");
			system("echo " WHT);
			system("norminette get_next_line ft_printf");
			ls_printf(1, RED"\n-	"GRN"-	"BLU"-	\n"WHT);
		}
		else if (sm_func_looking(u_input, "-gnl", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call norminette -gnl");
			ls_printf(1, BLU"\n-	"GRN"-	"RED"-	\n");
			system("echo " WHT);
			system("norminette get_next_line");
			ls_printf(1, RED"\n-	"GRN"-	"BLU"-	\n"WHT);
		}
		else if (sm_func_looking(u_input, "-pf", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call norminette -pf");
			ls_printf(1, BLU"\n-	"GRN"-	"RED"-	\n");
			system("echo " WHT);
			system("norminette ft_printf");
			ls_printf(1, RED"\n-	"GRN"-	"BLU"-	\n"WHT);
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call norm 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "norm "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							RM									//
	else if (sm_func_looking(u_input, "rm", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "rm all test file");
			if (!system("rm tester/GNL/GNL_dif.txt tester/GNL/GNLB_dif.txt tester/trace/tester* tester/trace/user*"))
				ls_printf(1, RED"GNL_dif.txt, GNLB_dif.txt, trace files,was remove\n"WHT);
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call rm 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "rm "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//								log								//
	else if (sm_func_looking(u_input, "log", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			system("echo "MAG"\x1b[4m.log.txt\x1b[0m"WHT);
			sm_log(log_fd,"ls-tester", "call log link");
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call log 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "log "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							VAL TUTO							//
	else if (sm_func_looking(u_input, "val", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "-tuto", &str_p) == 0)
			val_install();
		else if (sm_func_looking(u_input, "", &str_p) == 0)
			ls_printf(1, "did you mean \"val -tuto\" ?\n");
		else
		{
			sm_log(log_fd,"ls-tester", "call val 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "val "RED"%s " WHT "is not a valid argumant, use val -tuto for more info\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							example								//
	else if (sm_func_looking(u_input, ("yes"), &str_p) == 0)
	{
		if (sm_find_mix_str(u_input, ("itwork"), &str_p) == 0)
			ls_printf(1, "yes\n");
	}
	//							git									//
	else if (sm_func_looking(u_input, ("update"), &str_p) == 0)
	{
		if (sm_func_looking(u_input, ("-i"), &str_p) == 0)
			system("git pull");
		else if (sm_func_looking(u_input, ("-l"), &str_p) == 0)
			system("git log -5");
		else if (sm_func_looking(u_input, (""), &str_p) == 0)
		{
			ls_printf(1, "looking for update ...\n");
			system("git fetch --dry-run");
			system("git fetch --dry-run");
		}
		else if (sm_func_looking(u_input, ("-h"), &str_p) == 0)
		{
			ls_printf(1, "\n		"ORG"update"WHT"		\n\n");
			ls_printf(1, "update		git fetch --dry-run\n");
			ls_printf(1, "update -i	git pull\n");
			ls_printf(1, "update -h	show help\n");
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call update 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			ls_printf(1, YEL "update "RED"%s " WHT "is not a valid argumant, type update -h for help\n", copy);
		}
	}
	//							void								//
	else if (sm_func_looking(u_input, (""), &str_p) == 0)
	{
		sm_log(log_fd,"ls-tester", "was call with void");
		return (call_back);
	}
	//							UP									//
	else if (sm_func_looking(u_input, (up), &str_p) == 0)
	{
		*loop = 1;
		ls_printf(1, "\n");
		sm_log(log_fd,"ls-tester", "up arrow");
		return (call_back);
	}
	//							exit								//
	else if (sm_func_looking(u_input, ("exit"), &str_p) == 0 
			|| sm_func_looking(u_input, "q", &str_p) == 0)
	{
		if (call_back)
			free(call_back);
		sm_log(log_fd,"ls-tester", "exit");
		close(log_fd);
		exit(0);
	}
	else if (sm_func_looking(u_input, "pwd", &str_p) == 0)
		ls_printf(1, "%s\n", path);
	//							default								//
	else if (sm_func_looking(u_input, "ls-tester", &str_p) == 0)
		system("curl parrot.live");
	else
	{
		sm_log(log_fd, "ls-tester", "bad input");
		ls_printf(1, RED"%s " WHT"is not a valid input\n", u_input);
	}
	return (sm_str_dup(u_input));
}

int	main(int ac, char **av, char **en)
{
	int		loop;
	char	*last_call;
	int	i = 0;
	(void)ac;
	(void)av;
	loop = 0;
	last_call = NULL;
	system("rm .log.txt");
	sm_make_file_name(".log.txt");
	log_fd = open(".log.txt", O_RDWR);
	// make dif file
	//system("touch tester/PRINTF/PRINTF_dif.txt");
	//
	ls_printf(1, GRN"compile"WHT"				welcome in ...\n");
	logo();
	ls_printf(1, RED "DON'T use this for correction ❗\n"WHT);
	ls_printf(1, "this is not a finish product ⚠️\n");
	ls_printf(1, "type \"" YEL "help" WHT "\" to start\n\n");
	sm_log(log_fd, "ls-tester", "hi here");
	while (en[i])
	{
		sm_log(log_fd, "system", en[i]);
		if(strncmp("PWD=", en[i], 4) == 0)
			path = en[i] + 4;
		if(strncmp("LOGNAME=", en[i], 8) == 0)
			name = en[i] + 8;
		i++;
	}
	while (1)
		last_call = menu_loop(&loop, last_call);
	return (0);
}

// >> .log.txt
/*

*/