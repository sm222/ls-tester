/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_gnl_mem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 21:12:30 by anboisve          #+#    #+#             */
/*   Updated: 2022/12/30 21:12:30 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../get_next_line/get_next_line.h"
#include	"val_gnl_mem.h"
#include	<fcntl.h>
#include	<stdio.h>

# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"
# define ORG	"\x1b[38;5;202m"
# define PIK	"\x1b[38;5;176m"
# define CLE 	"\e[1;1H\e[2J"


int	main(void)
{
	char	*s;
	int		fd;

	system("echo " WHT);
	system("rm tester/text/void.txt 2> /dev/null");
	sleep(1);
	system("touch tester/text/void.txt");
	if (TEST_NB == 0)
	{
		printf(YEL"\n\ntest empty file\n"WHT);
		fd = open("tester/text/void.txt", O_RDONLY);
		if (fd >= 0)
		{
			s = get_next_line(fd);
			if (s)
			{
				printf(RED"did't work !\n\n"WHT);
				free(s);
			}
			else
				printf(GRN"work !\n\n"WHT);
			close(fd);
		}
		else
			printf(RED"can't open file : tester/text/void.txt\n"WHT);
	}
	else if (TEST_NB == 1)
	{
		printf(YEL"\n\ninvalid fd\n"WHT);
		s = get_next_line(-1);
		if (s)
		{
			system("echo '>❌[KO] did't work with -1\n' >> tester/GNL/GNL_dif.txt");
			printf(RED"❌ your gnl didn't send 'NULL' with -1 fd\n"WHT);
			free(s);
		}
		else
		{
			system("echo '	✅[OK]\n' >> tester/GNL/GNL_dif.txt");
			printf(GRN"✅ send 'NULL' with -1 fd\n"WHT);
		}
		s = get_next_line(-100);
		if (s)
		{
			system("echo '>❌[KO]\ndid't work with -100' >> tester/GNL/GNL_dif.txt");
			printf(RED"❌ your gnl didn't send 'NULL' with -100 fd\n"WHT);
			free(s);
		}
		else
		{
			system("echo '	✅[OK]\n' >> tester/GNL/GNL_dif.txt");
			printf(GRN"✅ send 'NULL' with -100 fd\n"WHT);
		}
		s = get_next_line(-42);
		if (s)
		{
			system("echo '>❌[KO]\n did't work with -42' >> tester/GNL/GNL_dif.txt");
			printf(RED"❌ your gnl didn't send 'NULL' with -42 fd\n"WHT);
			free(s);
		}
		else
		{
			system("echo '	✅[OK]\n' >> tester/GNL/GNL_dif.txt");
			printf(GRN"✅ send 'NULL' with -42 fd\n"WHT);
		}
	}
	else if (TEST_NB == 2)
	{
		//still reachable:
		printf(YEL"\n\ntest still reachable\n"WHT);
		system("echo 'line' >> tester/text/void.txt");
		fd = open("tester/text/void.txt", O_RDONLY);
		s = get_next_line(fd);
		free(s);
		close(fd);
	}
	else if (TEST_NB == 3)
	{
		s = get_next_line(0);
		write(0, "ls-tester",9);
		if (!s)
		{
			free(s);
			s = NULL;
		}
	}

	system("rm tester/text/void.txt");
	return (0);
}