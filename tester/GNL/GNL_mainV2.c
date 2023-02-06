/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_mainV2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:04:55 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/03 16:04:55 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"
#include "../ls_gnl.h"

int	main(int ac, char **av)
{
	char	*s_ls;
	char	*s_gnl;
	int		fd[2];

	s_ls = NULL;
	s_gnl = NULL;
	printf("welcome to gnl tester\n");
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while (--ac)
	{
		printf("file use for test :"YEL"%s", av[ac]);
		fd[0] = open(av[ac], O_RDONLY);
		fd[1] = open(av[ac], O_RDONLY);
		printf("open fd , 1 = %d, 2 = %d\n", fd[0], fd[1]);
		while (s_ls == s_gnl)
		{
			s_gnl = sm_get_next_line(fd[0]);
			s_ls  = get_next_line(fd[1]);
			if (s_ls == NULL || s_gnl == NULL)
				break ;
		}
		close(fd[0]);
		close(fd[1]);
	}
}