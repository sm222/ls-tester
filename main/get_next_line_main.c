/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:48:21 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/24 15:09:13 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	check(int ac, char **av)
{
	int	verif[3];
	int	i;

	(void)ac;
	(void)av;
	printf(CLE);
	i = 0;
	verif[0] = open("get_next_line.c", O_RDONLY);
	verif[1] = open("get_next_line_utils.c", O_RDONLY);
	verif[2] = open("get_next_line.h", O_RDONLY);
	if (verif[0] < 0 || verif[1] < 0 || verif[2] < 0)
	{
		printf(RED"Missing file: ");
		if (verif[0] < 0)
			printf(RED"get_next_line.c "WHT);
		if (verif[1] < 0)
			printf(RED"get_next_line_utils.c "WHT);
		if (verif[2] < 0)
			printf(RED"get_next_line.h"WHT);
		exit(0);
	}
	printf(GRN"No files missing, ready to go!\n");
	sleep(1);
	close(verif[0]);
	close(verif[1]);
	close(verif[2]);
	//system("./test_gnl.out");
}

int	main(int ac, char **av)
{
	int		fd[3];
	char	*tmp;
	int		i;

	check(ac, av);
	fd[0] = open("text/peepy.ans", O_RDONLY);
	fd[1] = open("text/text1.txt", O_RDONLY);
	fd[2] = open("text/text2.txt", O_RDONLY);
	i = 0;
	tmp = "\n";
	while (tmp)
	{
		tmp = get_next_line(fd[INDEX]);
		printf(RED"[fd-%d]"WHT" = %s", INDEX + 1, tmp);
		xfree(tmp);
		i++;
	}
	printf(WHT"\ntime call -- %d\n", i);
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}
