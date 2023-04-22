/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:46:54 by wdelaros          #+#    #+#             */
/*   Updated: 2023/01/02 00:12:32 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "sm_ft.h"

/*
print the lego 'ls-tester'
*/
void	logo(void)
{
	ls_printf(1, "\x1b[40m");
	ls_printf(1, RED"          ██╗      "BLU" ██████╗     "GRN"████████╗ "YEL"███████╗ "MAG" ██████╗ "CYN"████████╗"PIK" ███████╗"ORG " ██████╗      \n");
	ls_printf(1, RED"          ██║      "BLU"██╔════╝     "GRN"╚══██╔══╝ "YEL"██╔════╝ "MAG"██╔════╝ "CYN"╚══██╔══╝"PIK" ██╔════╝"ORG " ██╔══██╗     \n");
	ls_printf(1, RED"          ██║      "BLU"╚█████╗      "GRN"   ██║    "YEL"█████╗   "MAG"╚█████╗  "CYN"   ██║   "PIK" █████╗  "ORG " ██████╔╝     \n");
	ls_printf(1, RED"          ██║      "BLU" ╚═══██╗     "GRN"   ██║    "YEL"██╔══╝   "MAG" ╚═══██╗ "CYN"   ██║   "PIK" ██╔══╝  "ORG " ██╔══██╗     \n");
	ls_printf(1, RED"          ███████╗ "BLU"██████╔╝     "GRN"   ██║    "YEL"███████╗ "MAG"██████╔╝ "CYN"   ██║   "PIK" ███████╗"ORG " ██║  ██║     \n");
	ls_printf(1, RED"          ╚══════╝ "BLU"╚═════╝      "GRN"   ╚═╝    "YEL"╚══════╝ "MAG"╚═════╝  "CYN"   ╚═╝   "PIK" ╚══════╝"ORG " ╚═╝  ╚═╝     \n");
	ls_printf(1, "\x1b[0m");
	ls_printf(1, "				Made by "BLU"anboisve,"GRN" brheaume, wdelaros"WHT"\n");
}

void	*ft_sfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

//https://brew.sh/

/*
give info about mem test
*/
int		gnl_mem_info(void)
{
	char	txt[1];
	ls_printf(1, "\n	Info\n\n");
	ls_printf(1, "this test use %s.\n", VAL);
	ls_printf(1, "if you don't have it please install it : " MAG "https://valgrind.org/" WHT " \n");
	ls_printf(1, "you can install it using : " MAG "https://brew.sh/" WHT " \n");
	ls_printf(1, "if you want the instructions, type the command, val -tuto .\n\n");
	ls_printf(1, "the next test look if you have memory problem with a empty file and\n");
	ls_printf(1, "if you call your get_next_line the right amount of time if memory is still allocate.\n\n");
	ls_printf(1, "1. test show if it work with a empty file\n");
	ls_printf(1, "2. look for the phrase : "YEL"still reachable"WHT".\n");
	ls_printf(1, "	if you see it and it say somting like '"YEL"still reachable: 1 bytes in 1 blocks"WHT"'\n");
	ls_printf(1, "	it mean you have memory still allocate event if the rest of the file is empty.\n");
	ls_printf(1, "\n\nq or x to cancel, enter to continue\n");
	sm_get_keybord_input(txt, 1);
	if (txt[0] == 'x' || txt[0] == 'q')
		return (1);
	return (0);
}

/*
info how to install valgrind
*/
void	val_install(void)
{
	ls_printf(1, "\n	Info\n\n");
	ls_printf(1, "to install %s, you can use those commande\n", VAL);
	ls_printf(1, "if something happens to your computer we are not responsible for those software\n\n");
	ls_printf(1, "	1. \"rm -rf $HOME/.brew && git clone --depth=1 https://github.com/Homebrew/brew $HOME/.brew && echo 'export PATH=$HOME/.brew/bin:$PATH' >> $HOME/.zshrc && source $HOME/.zshrc && brew update\"\n");
	ls_printf(1, "	2. \"brew tap LouisBrunner/valgrind\"\n");
	ls_printf(1, "	3. \"brew install --HEAD LouisBrunner/valgrind/valgrind\"\n");
	ls_printf(1, "\nhave fun testing\n\n");
}
//	system("echo '\nStart of Test - - -⏱'$(date '+ %A %d %B %Y%n %T')'\n' >> tester/GNL/GNL_dif.txt");

/*
use before test and and of test
type
	s = start
	e = end
file
	path and name of file
*/
void	put_time_file(char type, char *file)
{
	char	*cmd = NULL;
	char	*txt = NULL;
	
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

/*
info about buffer test
*/
void	gnl_buffer_tester(void)
{
	ls_printf(1, "\n	Info\n\n");
	ls_printf(1, "This test will run your gnl with BUFFER_SIZE from 1 to 10000000.\n");
	ls_printf(1, "(BUFFER_SIZE * 2 every time)\n");
}

/*
give info about a test that take time
*/
int		test_take_time(void)
{
	char	txt[2];
	ls_printf(1, "\n	Info\n\n");
	ls_printf(1, "This test take a lot of time, are you sure you want to continue?\n");
	ls_printf(1, "\n\nq or x to cancel, enter to continue\n");
	sm_get_keybord_input(txt, 1);
	if (txt[0] == 'x' || txt[0] == 'q')
		return (1);
	return (0);
}

/*
struct
*/

void	make_node_def_last(t_define_in **node, t_define_in *new)
{
	t_define_in	*tmp;

	if (!new)
		return ;
	else if (!*node)
	{
		*node = new;
		if (!*node)
		{
			write(2, "fail to make note\n", 18);
			return ;
		}
	}
	else
	{
		tmp = (*node);
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_define_in	*make_node_define(char *define, int size)
{
	t_define_in	*tmp;

	tmp = sm_calloc(sizeof(t_define_in), 1);
	tmp->cmd = sm_str_dup(define);
	tmp->size = size;
	tmp->next = NULL;
	return (tmp);
}

int	look_for_double_node(t_define_in **head, t_define_in *new)
{
	t_define_in	*tmp;

	if (!head || !(*head))
		return (1);
	tmp = (*head);
	while (tmp)
	{
		if (sm_strncmp(tmp->cmd, new->cmd, sm_strlen(new->cmd) + 1) == 0)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
