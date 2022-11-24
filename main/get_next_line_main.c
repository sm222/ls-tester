/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:48:21 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/24 08:47:33 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(void)
{
	int		fd[3];
	char	*tmp;
	int		i;

	fd[0] = open("../main/text/text.txt", O_RDONLY);
	fd[1] = open("../main/text/text1.txt", O_RDONLY);
	fd[2] = open("../main/text/text2.txt", O_RDONLY);
	i = 0;
	tmp = "\n";
	while (tmp)
	{
		tmp = get_next_line(fd[INDEX]);
		printf(RED"[fd-%d]"WHT" = %s", INDEX + 1, tmp);
		xfree(tmp);
		printf(WHT"\ntime call -- %d\n", ++i);
	}
	close(fd[0]);
	close(fd[1]);
	close(fd[2]);
}

// int	main(void)
// {
// 	int		fd;
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	if (INDEX == 0)
// 	{
// 		fd = open("../main/text/text.txt", O_RDONLY);
// 		do
// 		{
// 			tmp = get_next_line(fd);
// 			printf(BLU"[fd-1]"WHT" = %s", tmp);
// 			xfree(tmp);
// 			printf(WHT"\ntime call -- %d\n", ++i);
// 		} while (!tmp);
// 	}
// 	else if (INDEX == 1)
// 	{
// 		fd = open("../main/text/text1.txt", O_RDONLY);
// 		do
// 		{
// 			tmp = get_next_line(fd);
// 			printf(RED"[fd-2]"WHT" = %s", tmp);
// 			xfree(tmp);
// 			printf(WHT"\ntime call -- %d\n", ++i);
// 		} while (!tmp);
// 	}
// 	else if (INDEX == 2)
// 	{
// 		fd = open("../main/text/text2.txt", O_RDONLY);
// 		do
// 		{
// 			tmp = get_next_line(fd);
// 			printf(GRN"[fd-3]"WHT" = %s", tmp);
// 			xfree(tmp);
// 			printf(WHT"\ntime call -- %d\n", ++i);
// 		} while (!tmp);
// 	}
// 	close(fd);
// }