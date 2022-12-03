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

#include "../../../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

#define RED    "\x1B[31m"
#define GRN    "\x1B[32m"
#define YEL    "\x1B[33m"
#define BLU    "\x1B[34m"
#define MAG    "\x1B[35m"
#define CYN    "\x1B[36m"
#define WHT    "\x1B[37m"
#define RESET  "\x1B[0m"
#define CLE    "\e[1;1H\e[2J"

int	main(void)
{
	int		fd;
	char	*s;
	char	o;

	system("echo " WHT);
	s = &o;
	fd = open("tester/text/peepy.ans", O_RDONLY);
	if (fd < 0)
		return (printf(RED "[KO] : can't open file\n"WHT), 0);
	while (s != NULL)
	{
		s = get_next_line(fd);
		if (s)
			free(s);
	}
	close(fd);
}
