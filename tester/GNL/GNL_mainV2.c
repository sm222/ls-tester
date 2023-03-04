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
/*___________________________________*/
#include "../ls_gnl.h"
#include "../sm_ft.h"
#include "../../C_tools/C_tool.h"

/*___________________________________*/

int	main(int ac, char **av)
{
	t_gnl	data;
	char	*cmd;

	cmd = NULL;
	data.loop = 1;
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("BUFFER_SIZE = %d\n\n", BUFFER_SIZE);
	while (--ac)
	{
		data.loop = 1;
		printf("file use for test : "YEL"%s\n"WHT, av[ac]);
		data.fd[0] = open(av[ac], O_RDONLY);
		data.fd[1] = open(av[ac], O_RDONLY);
		printf("open fd /%d|%d\\\n", data.fd[0], data.fd[1]);
		data.s_ls =  NULL;
		data.s_gnl = NULL;
		sm_make_file_name("ls_out");
		sm_make_file_name("gnl_out");
		data.out_fd[0] = open("ls_out", O_RDWR);
		data.out_fd[1] = open("gnl_out", O_RDWR);
		printf("open fd_out /%d|%d\\\n", data.out_fd[0], data.out_fd[1]);
		cmd = combine("echo 'file test %s\n' >> tester/GNL/GNL_dif.txt", av[ac]);
		system(cmd);
		sm_free(cmd);
		while (data.loop)
		{
			usleep(70000);
			data.s_ls = sm_get_next_line(data.fd[0]);
			data.s_gnl  =  get_next_line(data.fd[1]);
			write(data.out_fd[0], data.s_ls, sm_strlen(data.s_ls));
			write(data.out_fd[1], data.s_gnl, sm_strlen(data.s_gnl));
			if (LS_FULL_TEST)
			{
				if (ft_memcmp(data.s_gnl, data.s_ls, sm_strlen(data.s_ls) + 1) == 0)
				{
					printf(GRN"[OK]"WHT);
					if (data.s_gnl == NULL && data.s_ls == NULL)
					{
						printf(GRN"\n✅ [OK]\n"WHT);
						break ;
					}
				}
				else
					printf(RED"[KO]"WHT);
				sm_free(data.s_ls);
				sm_free(data.s_gnl);
				if (data.s_ls == NULL)
					break ;
			}
			else
			{
				printf("%d", data.loop);
				if (ft_memcmp(data.s_gnl, data.s_ls, sm_strlen(data.s_ls) + 1) == 0)
				{
					sm_free(data.s_ls);
					sm_free(data.s_gnl);
					printf(GRN"[OK]"WHT);
					if (data.s_gnl == NULL && data.s_ls == NULL)
					{
						printf(GRN"\n✅ [OK]\n"WHT);
						system("echo '	✅[OK]\n' >> tester/GNL/GNL_dif.txt");
						break ;
					}
				}
				else
				{
					printf(RED"\n❌ [KO]\n"WHT);
					system("echo '	❌ [KO]\n' >> tester/GNL/GNL_dif.txt");
					printf("\nwas expecting :\n");
					system("echo 'was expecting :\n' >> tester/GNL/GNL_dif.txt");
					cmd = combine("echo '%s|||' >> tester/GNL/GNL_dif.txt", data.s_ls);
					system(cmd);
					sm_free(cmd);
					cmd = combine("echo '%s\n|||' >> tester/GNL/GNL_dif.txt", data.s_gnl);
					system(cmd);
					sm_free(cmd);
					if (LS_INSP_TEST)
					{
						Ct_memcmp(data.s_ls, data.s_gnl, sm_strlen(data.s_ls) + 1, 1);
					}
					else
					{
						printf(GRN"%s\n\n"WHT, data.s_ls);
						printf(RED"%s\n\n"WHT, data.s_gnl);
					}
					printf("got :\n");
					system("echo 'got :\n' >> tester/GNL/GNL_dif.txt");
					//sm_inspect_arr(data.s_gnl, 'c', sm_strlen(data.s_ls) + 1, -1);
					printf("\n- - -\n");
					
					sm_free(data.s_ls);
					sm_free(data.s_gnl);
					if (!LS_FULL_TEST)
						break ;
				}
			}
			data.loop++;
		}
		close(data.fd[0]);
		close(data.fd[1]);
		close(data.out_fd[0]);
		close(data.out_fd[1]);
		if (LS_RMFILE)
		{
			system("rm -f gnl_out");
			system("rm -f ls_out");
		}
		printf("\n");
	}
	printf(RED"\n-"GRN"\n-"BLU"\n-"WHT"\n");
}
