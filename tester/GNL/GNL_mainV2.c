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
#include "../sm_ft.h"


int	main(int ac, char **av)
{
	char	*s_ls;
	char	*s_gnl;
	int		fd[2];
	int		loop;

	s_ls = NULL;
	s_gnl = NULL;
	loop = 1;
	printf("welcome to gnl tester\n");
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while (--ac)
	{
		printf("file use for test :"YEL"%s\n"WHT, av[ac]);
		fd[0] = open(av[ac], O_RDONLY);
		fd[1] = open(av[ac], O_RDONLY);
		printf("open fd /%d/%d\n", fd[0], fd[1]);
		s_ls = NULL;
		s_gnl = NULL;
		while (loop)
		{
			printf("here\n");
			s_ls = sm_get_next_line(fd[0]);
			s_gnl  = get_next_line(fd[1]);
			printf("test = %s", s_gnl);
			printf("ls   = %s", s_ls);
			if (s_ls == NULL && s_gnl == NULL)
				break ;
			else if (ft_memcmp(s_gnl, s_ls, sm_strlen(s_ls) + 1) == 0)
				continue;
			//if (s_ls == NULL || s_gnl == NULL)
			//	break ;
		}
		close(fd[0]);
		close(fd[1]);
	}
}