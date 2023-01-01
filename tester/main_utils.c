/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:46:54 by wdelaros          #+#    #+#             */
/*   Updated: 2023/01/01 03:50:11 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	logo(void)
{
	printf("\x1b[40m");
	printf(RED"          ██╗      "BLU" ██████╗     "GRN"████████╗ "YEL"███████╗ "MAG" ██████╗ "CYN"████████╗"PIK" ███████╗"ORG " ██████╗      \n");
	printf(RED"          ██║      "BLU"██╔════╝     "GRN"╚══██╔══╝ "YEL"██╔════╝ "MAG"██╔════╝ "CYN"╚══██╔══╝"PIK" ██╔════╝"ORG " ██╔══██╗     \n");
	printf(RED"          ██║      "BLU"╚█████╗      "GRN"   ██║    "YEL"█████╗   "MAG"╚█████╗  "CYN"   ██║   "PIK" █████╗  "ORG " ██████╔╝     \n");
	printf(RED"          ██║      "BLU" ╚═══██╗     "GRN"   ██║    "YEL"██╔══╝   "MAG" ╚═══██╗ "CYN"   ██║   "PIK" ██╔══╝  "ORG " ██╔══██╗     \n");
	printf(RED"          ███████╗ "BLU"██████╔╝     "GRN"   ██║    "YEL"███████╗ "MAG"██████╔╝ "CYN"   ██║   "PIK" ███████╗"ORG " ██║  ██║     \n");
	printf(RED"          ╚══════╝ "BLU"╚═════╝      "GRN"   ╚═╝    "YEL"╚══════╝ "MAG"╚═════╝  "CYN"   ╚═╝   "PIK" ╚══════╝"ORG " ╚═╝  ╚═╝     \n");
	printf("\x1b[0m");
	printf("				Made by "GRN" wdelaros, "BLU"anboisve,"GRN" brheaume"WHT"\n");
}

void	*ft_sfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

//https://brew.sh/

int		gnl_mem_info(void)
{
	char	txt[1];
	printf("\n	Info\n\n");
	printf("this test use %s.\n", VAL);
	printf("if you don't have it please install it : " MAG "https://valgrind.org/" WHT " \n");
	printf("you can install it using : " MAG "https://brew.sh/" WHT " \n");
	printf("if you want the instructions, type the command, val -tuto .\n\n");
	printf("the next test look if you have memory problem with a empty file and\n");
	printf("if you call your get_next_line the right amount of time if memory is still allocate.\n\n");
	printf("1. test show if it work with a empty file\n");
	printf("2. look for the phrase : "YEL"still reachable"WHT".\n");
	printf("	if you see it and it say somting like '"YEL"still reachable: 1 bytes in 1 blocks"WHT"'\n");
	printf("	it mean you have memory still allocate event if the rest of the file is empty.\n");
	printf("\n\nq or x to cancel, enter to continue\n");
	sm_get_keybord_input(txt, 1);
	if (txt[0] == 'x' || txt[0] == 'q')
		return (1);
	return (0);
}

void	val_install(void)
{
	printf("\n	Info\n\n");
	printf("to install %s, you can use those commande\n", VAL);
	printf("if something happens to your computer we are not responsible for those software\n\n");
	printf("	1. \"rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update\"\n");
	printf("	2. \"brew tap LouisBrunner/valgrind\"\n");
	printf("	3. \"brew install --HEAD LouisBrunner/valgrind/valgrind\"\n");
	printf("\nhave fun testing\n\n");
}
//	system("echo '\nStart of Test - - -⏱'$(date '+ %A %d %B %Y%n %T')'\n' >> tester/GNL/GNL_dif.txt");

void	put_time_file(char type, char *file)
{
	char	*cmd;
	char	*txt;
	
	if (type == 's')
	{
		txt = "echo '\nStart of Test - - -⏱'$(date '+ %A %d %B %Y%n %T')'\n' ";
		cmd = combine("%s >> %s", txt , file);
	}
	else if (type == 'e')
	{
		txt = "echo 'finish of Test - - ⏰'$(date '+ %A %d %B %Y%n %T')'\n' ";
		cmd = combine("%s >> %s", txt , file);
	}
	else
	{
		txt = "echo '\n'$(date '+ %A %d %B %Y%n %T')'\n'";
		cmd = combine("%s >> %s", txt , file);
	}
	system(cmd);
	free(cmd);
}

//tester/GNL/GNL_dif.txt

void	gnl_buffer_tester(void)
{
	printf("\n	Info\n\n");
	printf("This test will run your gnl with BUFFER_SIZE from 1 to 10000000.\n");
	printf("(BUFFER_SIZE * 2 every time)\n");
}

int		test_take_time(void)
{
	char	txt[2];
	printf("\n	Info\n\n");
	printf("This test take a lot of time, are you sure you want to continue?\n");
	printf("\n\nq or x to cancel, enter to continue\n");
	sm_get_keybord_input(txt, 1);
	if (txt[0] == 'x' || txt[0] == 'q')
		return (1);
	return (0);
}