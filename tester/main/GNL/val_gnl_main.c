/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_gnl_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:51:26 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/30 08:41:27 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../../get_next_line.h"
#include	<fcntl.h>
#include	<stdio.h>

#define RED		"\x1B[31m"
#define GRN		"\x1B[32m"
#define YEL		"\x1B[33m"
#define BLU		"\x1B[34m"
#define MAG		"\x1B[35m"
#define CYN		"\x1B[36m"
#define WHT		"\x1B[37m"
#define RESET	"\x1B[0m"
#define CLE		"\e[1;1H\e[2J"

int	main(int ac, char **av)
{
	int		fd;
	char	*s;
	int		i;

	i = 0;
	(void)ac;
	printf("file test : "MAG"%s\n"WHT, av[1]);
	system("echo " WHT);
	s = "ls-tester";
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (printf(RED "❌Can't open file %s\n"WHT, av[1]));
	while (s)
	{
		s = get_next_line(fd);
		if (s)
			free(s);
		i++;
		if (i > 13000)
		{
			printf(WHT"\nNever return "RED"NULL"WHT"❗️\n");
			break ;
		}
		if (i % 100 == 0)
			printf(YEL"."WHT);
	}
	printf("\n gnl run "YEL"%d"WHT" time\n\n", i + 1);
	close(fd);
	return (0);
}


// work on reachable byte 