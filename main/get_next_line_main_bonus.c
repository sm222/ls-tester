/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:43:31 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/25 11:01:35 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	int	verif[3];
	int	i;

	(void)ac;
	(void)av;
	i = 0;
	verif[0] = open("get_next_line_bonus.c", O_RDONLY);
	verif[1] = open("get_next_line_utils_bonus.c", O_RDONLY);
	verif[2] = open("get_next_line_bonus.h", O_RDONLY);
	if (verif[0] < 0 || verif[1] < 0 || verif[2] < 0)
		return (printf("Missing file\n"), exit(0), 0);
	printf("work :D\n");
	close(verif[0]);
	close(verif[1]);
	close(verif[2]);
}

// int	main(void)
// {
// 	int		fd[3];
// 	char	*tmp[3];
// 	int		i;

// 	i = 0;
// 	fd[0] = open("../main/text/text.txt", O_RDONLY);
// 	fd[1] = open("../main/text/text1.txt", O_RDONLY);
// 	fd[2] = open("../main/text/text2.txt", O_RDONLY);
// 	do
// 	{
// 	tmp[0] = get_next_line(fd[0]);
// 	tmp[1] = get_next_line(fd[1]);
// 	tmp[2] = get_next_line(fd[2]);
// 	if (tmp[0])
// 		printf(BLU"[fd-1]"WHT" = %s", tmp[0]);
// 	else if (!tmp[0])
// 		printf(BLU"[fd-1]"YEL" = %s\n", tmp[0]);
// 	xfree(tmp[0]);
// 	if (tmp[1])
// 		printf(RED"[fd-2]"WHT" = %s", tmp[1]);
// 	else if (!tmp[1])
// 		printf(RED"[fd-2]"YEL" = %s\n", tmp[1]);
// 	xfree(tmp[1]);
// 	if (tmp[2])
// 		printf(GRN"[fd-3]"WHT" = %s", tmp[2]);
// 	else if (!tmp[2])
// 		printf(GRN"[fd-3]"YEL" = %s\n", tmp[2]);
// 	xfree(tmp[2]);
// 	printf(WHT"\ntime call -- %d\n", ++i);
// 	} while ((tmp[0] != NULL || tmp[1] != NULL || tmp[2] != NULL));
// 	close(fd[0]);
// 	close(fd[1]);
// 	close(fd[2]);
// }