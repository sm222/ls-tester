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
	char	temp[size_i];
	int		str_p = 0;
	char	up[4] = {27, 91, 65, 0};

	if (call_back != NULL)
		printf("last command : "YEL "%s\n" WHT, call_back);
	printf("%s/ls-tester: ", name);
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
			printf(ORG"\n- - - - Help List - - - -\n"WHT);
			printf("val -tuto	shows how to install valgrind\n");
			printf("gnl		GNL tester\n");
			printf("gnlb		GNL tester with BONUS\n");
			printf("pf		PRINTF tester\n");
			printf("norm		norminette all the files\n");
			printf("rm		RM all trace files\n");
			printf("help of (tester name or command) -help - shows help list\n");
			printf("exit or q	exits the program\n");
			printf("\n");
			sm_log(log_fd,"ls-tester", "call help");
		}
		else
		{
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			printf(YEL "help "RED"%s " WHT "is not a valid argumant\n", copy);
			sm_log(log_fd,"ls-tester", "call help with invalid argument");
		}
		return (sm_str_dup(u_input));
	}
	//						PRINTF									//
	else if (sm_func_looking(u_input, "pf", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "-help", &str_p) == 0)
		{
			printf(ORG"\n- - - - Printf Help List - - - -\n"WHT);
			printf("exit or q - exit the program\n");
			printf("\n");
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
			printf(YEL "pf "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							GNL									//
	else if (sm_func_looking(u_input, "gnl", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "-help", &str_p) == 0)
		{
			printf(ORG"\n- - - - GNL Help List - - - -\n"WHT);
			printf("-buff	set buffer size (ex: gnl -buff 42)\n");
			printf("-test	run one test (ex: gnl -test 5)\n");
			printf("-mem	run %s test to chek memory\n", VAL);
			printf("-mem+	test multiple BUFFER_SIZE\n");
			printf("-pp	run peepy test\n");
			printf("-dif	show GNL trace file\n");
			printf("-rm	RM GNL trace file\n");
			printf("exit or q - exit the program\n");
			printf("\n");
			sm_log(log_fd,"ls-tester", "call gnl -help");
		}
		else if (sm_func_looking(u_input, "-buff", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call gnl -buff");
			put_time_file('s',"tester/GNL/GNL_dif.txt");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			gnl_mem(1, 100);
			gnl_tester(peepy_atoi(copy));
			put_time_file('e',"tester/GNL/GNL_dif.txt");
		}
		else if (sm_func_looking(u_input, "-rm", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call gnl -rm");
			if (!system("rm tester/GNL/GNL_dif.txt"))
				printf(RED"GNL_dif.txt, was remove\n"WHT);
			return (sm_str_dup(u_input));
		}
		else if (sm_func_looking(u_input, "-tt", &str_p) == 0)
		{
			printf(WHT);
			t_gnl_in *in;
			in = sm_calloc(1, sizeof(t_gnl_in));
			in->cmd = "LS_FULL_TEST";
			in->size = 0;
			in->next = NULL;
			new_gnl_test(in);
		}
		else if (sm_func_looking(u_input, "-dif", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call gnl -dif");
			if (system("cat tester/GNL/GNL_dif.txt"))
				printf(RED"GNL_dif.txt, don't exist\n"WHT);
			return (sm_str_dup(u_input));
		}
		else if (sm_func_looking(u_input, "-pp", &str_p) == 0)
		{
			put_time_file('s',"tester/GNL/GNL_dif.txt");
			if (sm_func_looking(u_input, "-buff", &str_p) == 0)
			{
				sm_log(log_fd,"ls-tester", "call gnl -pp -buff");
				sm_copy_str_to(u_input, copy, str_p + 1, -1);
				gnl_partial_tester(peepy_atoi(copy), "pp");
			}
			else
			{
				sm_log(log_fd,"ls-tester", "call gnl -pp");
				gnl_partial_tester(1, "pp");
			}
			put_time_file('e',"tester/GNL/GNL_dif.txt");
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
		else if (sm_func_looking(u_input, "-test", &str_p) == 0)
		{
			put_time_file('s',"tester/GNL/GNL_dif.txt");
			str_p += sm_copy_str_to(u_input, temp, str_p + 1, -1) + 1;
			if (sm_func_looking(u_input, "-buff", &str_p) == 0)
			{
				sm_log(log_fd,"ls-tester", "call gnl -test -buff");
				sm_copy_str_to(u_input, copy, str_p + 1, -1);
				gnl_partial_tester(peepy_atoi(copy), combine("text%s", temp));
				gnl_mem(1, 100);
			}
			else
			{
				sm_log(log_fd,"ls-tester", "call gnl -test");
				gnl_partial_tester(1, combine("text%s", temp));
			}
			put_time_file('e',"tester/GNL/GNL_dif.txt");
		}
		else if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			put_time_file('s',"tester/GNL/GNL_dif.txt");
			sm_log(log_fd,"ls-tester", "call gnl");
			gnl_tester(1);
			put_time_file('e',"tester/GNL/GNL_dif.txt");
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call gnl 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			printf(YEL "gnl "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							GNL_B								//
	else if (sm_func_looking(u_input, "gnlb", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "-help", &str_p) == 0)
		{
			printf(ORG"\n- - - - GNLB Help List - - - -\n"WHT);
			printf("-buff	set buffer size (ex: gnl -buff 42)\n");
			printf("-test	run one test (ex: gnl -test 5)\n");
			printf("-dif	show GNLB trace file\n");
			printf("-rm	RM GNLB trace file\n");
			printf("exit or q - exit the program\n");
			printf("\n");
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
				printf(RED"GNLB_dif.txt, was remove\n"WHT);
			return (sm_str_dup(u_input));
		}
		else if (sm_func_looking(u_input, "-dif", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call gnl -dif");
			if (system("cat tester/GNL/GNLB_dif.txt"))
				printf(RED"GNLB_dif.txt, don't exist\n"WHT);
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
			printf(YEL "gnlb "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							NORMINETTE							//
	else if (sm_func_looking(u_input, "norm", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call norminette");
			printf(BLU"\n-	"GRN"-	"RED"-	\n");
			system("echo " WHT);
			system("norminette get_next_line ft_printf");
			printf(RED"\n-	"GRN"-	"BLU"-	\n"WHT);
		}
		else if (sm_func_looking(u_input, "-gnl", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call norminette -gnl");
			printf(BLU"\n-	"GRN"-	"RED"-	\n");
			system("echo " WHT);
			system("norminette get_next_line");
			printf(RED"\n-	"GRN"-	"BLU"-	\n"WHT);
		}
		else if (sm_func_looking(u_input, "-pf", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "call norminette -pf");
			printf(BLU"\n-	"GRN"-	"RED"-	\n");
			system("echo " WHT);
			system("norminette ft_printf");
			printf(RED"\n-	"GRN"-	"BLU"-	\n"WHT);
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call norm 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			printf(YEL "norm "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							RM									//
	else if (sm_func_looking(u_input, "rm", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "rm", &str_p) == 0)
		{
			sm_log(log_fd,"ls-tester", "rm all test file");
			if (!system("rm tester/GNL/GNL_dif.txt tester/GNL/GNLB_dif.txt"))
				printf(RED"GNL_dif.txt, GNLB_dif.txt, was remove\n"WHT);
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call rm 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			printf(YEL "rm "RED"%s " WHT "is not a valid argumant\n", copy);
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
			printf(YEL "log "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							VAL TUTO							//
	else if (sm_func_looking(u_input, "val", &str_p) == 0)
	{
		if (sm_func_looking(u_input, "-tuto", &str_p) == 0)
			val_install();
		else if (sm_func_looking(u_input, "", &str_p) == 0)
			printf("did you mean \"val -tuto\" ?\n");
		else
		{
			sm_log(log_fd,"ls-tester", "call val 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			printf(YEL "val "RED"%s " WHT "is not a valid argumant, use val -tuto for more info\n", copy);
		}
		return (sm_str_dup(u_input));
	}
	//							example								//
	else if (sm_func_looking(u_input, ("yes"), &str_p) == 0)
	{
		if (sm_find_mix_str(u_input, ("itwork"), &str_p) == 0)
			printf("yes\n");
	}
	//							git									//
	else if (sm_func_looking(u_input, ("update"), &str_p) == 0)
	{
		if (sm_func_looking(u_input, ("-i"), &str_p) == 0)
			system("git pull");
		else if (sm_func_looking(u_input, (""), &str_p) == 0)
		{
			printf("looking for update ...\n");
			system("git fetch --dry-run");
			system("git fetch --dry-run");
		}
		else if (sm_func_looking(u_input, ("-h"), &str_p) == 0)
		{
			printf("\n		"ORG"update"WHT"		\n\n");
			printf("update		git fetch --dry-run\n");
			printf("update -i	git pull\n");
			printf("update -h	show help\n");
		}
		else
		{
			sm_log(log_fd,"ls-tester", "call update 'whit mix argument'");
			sm_copy_str_to(u_input, copy, str_p + 1, -1);
			printf(YEL "update "RED"%s " WHT "is not a valid argumant, type update -h for help\n", copy);
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
		printf("\n");
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
	{
		printf("%s\n", path);
	}
	//							default								//
	else if (sm_func_looking(u_input, "ls-tester", &str_p) == 0)
	{
		system("curl parrot.live");
	}
	else
	{
		sm_log(log_fd, "ls-tester", "bad input");
		printf(RED"%s " WHT"is not a valid input\n", u_input);
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
	system("touch tester/GNL/GNL_dif.txt");
	system("touch tester/PRINTF/PRINTF_dif.txt");
	//
	printf(GRN"compile"WHT"				welcome in ...\n");
	logo();
	printf(RED "DON'T use this for correction ❗\n"WHT);
	printf("this is not a finish product ⚠️\n");
	printf("type \"" YEL "help" WHT "\" to start\n\n");
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
	close(log_fd);
	return (0);
}

// >> .log.txt
