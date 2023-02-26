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

	setvbuf(stdout, NULL, _IONBF, 0);
	printf("welcome to gnl tester\n");
	printf("BUFFER_SIZE = %d\n\n", BUFFER_SIZE);
	while (--ac)
	{
		loop = 1;
		printf("file use for test : "YEL"%s\n"WHT, av[ac]);
		fd[0] = open(av[ac], O_RDONLY);
		fd[1] = open(av[ac], O_RDONLY);
		printf("open fd /%d|%d\\\n", fd[0], fd[1]);
		s_ls = NULL;
		s_gnl = NULL;
		sm_make_file_name("ls_out");
		sm_make_file_name("gnl_out");
		while (loop)
		{
			usleep(70000);
			s_ls = sm_get_next_line(fd[0]);
			s_gnl  = get_next_line(fd[1]);
			if (ft_memcmp(s_gnl, s_ls, sm_strlen(s_ls) + 1) == 0)
			{
				s_ls = sm_free(s_ls);
				s_gnl = sm_free(s_gnl);
				printf(GRN"[OK]"WHT);
				if (s_gnl == NULL && s_ls == NULL)
				{
					printf("\n✅ OK\n");
					break ;
				}
			}
			else
			{
				printf("\n❌ KO\n");
				printf("\nwas expecting :\n %s", s_ls);
				printf("\ngot :\n %s", s_gnl);
				printf("\n- - -\n");
				s_ls = sm_free(s_ls);
				s_gnl = sm_free(s_gnl);
				break ;
			}
		}
		close(fd[0]);
		close(fd[1]);
		system("rm -f gnl_out");
		system("rm -f ls_out");
		printf("\n");
	}
}