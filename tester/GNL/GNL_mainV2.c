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
		printf("file use for test : "MAG"%s\n"WHT, av[ac]);
		data.fd[0] = open(av[ac], O_RDONLY);
		data.fd[1] = open(av[ac], O_RDONLY);
		printf("open fd		/%d|%d\\\n", data.fd[0], data.fd[1]);
		data.s_ls  = NULL;
		data.s_gnl = NULL;
		data.out_fd[0] = open("ls_out",  O_RDWR | O_CREAT | O_TRUNC, 0644);
		data.out_fd[1] = open("gnl_out", O_RDWR | O_CREAT | O_TRUNC, 0644);
		printf("open fd_out	/%d|%d\\\n", data.out_fd[0], data.out_fd[1]);
		cmd = combine("echo 'file test %s 🔽\n' >> " OUTFILE, av[ac]);
		system(cmd);
		sm_free(cmd);
		sleep(1);
		system("echo 'top\\\\\\\\🔜' >> " OUTFILE);
		while (data.loop)
		{
			usleep(LS_SPEED * 1000);
			data.s_ls = sm_get_next_line(data.fd[0]);
			data.s_gnl  =  get_next_line(data.fd[1]);
			write(data.out_fd[0], data.s_ls, sm_strlen(data.s_ls));
			write(data.out_fd[1], data.s_gnl, sm_strlen(data.s_gnl));
			if (LS_FULL_TEST)
			{
				if (ft_memcmp(data.s_gnl, data.s_ls, sm_strlen(data.s_ls) + 1) == 0)
				{
					if (LS_STYLE == 2)
						printf(GRN"|"WHT);
					else if (LS_STYLE == 1)
						printf(LINE"%.d "NB_CHAR"%.zu"RESET" %s", data.loop, sm_strlen(data.s_gnl), data.s_gnl);
					else
						printf(GRN"[OK]"WHT);
					cmd = combine("echo '✅%d' >> " OUTFILE, data.loop);
					system(cmd);
					sm_free(cmd);
					if (data.s_gnl == NULL && data.s_ls == NULL)
					{
						printf(GRN"\n✅ [OK]\n"WHT);
						break ;
					}
				}
				else
				{
					if (LS_STYLE)
					{
						printf(RED"|"WHT);
					}
					else
						printf(RED"[KO]"WHT);
					cmd = combine("echo '✅%d' >> " OUTFILE, data.loop);
					system(cmd);
					sm_free(cmd);
					system("echo '	❌ [KO]' >> " OUTFILE);
					system("echo 'was expecting :' >> " OUTFILE);
					cmd = combine("echo '%s' >> " OUTFILE, data.s_ls);
					system(cmd);
					sm_free(cmd);
					system("echo '⬆⬇' >> " OUTFILE);
					system("echo 'got:' >> " OUTFILE);
					cmd = combine("echo '%s\n' >> " OUTFILE, data.s_gnl);
					system(cmd);
					sm_free(cmd);
				}
				sm_free(data.s_ls);
				sm_free(data.s_gnl);
				if (data.s_ls == NULL)
					break ;
			}
			else
			{
				if (ft_memcmp(data.s_gnl, data.s_ls, sm_strlen(data.s_ls) + 1) == 0)
				{
					if (LS_STYLE == 3)
						fprintf(stderr ,LINE"%3d "NB_CHAR"%4zu"RESET" %s", data.loop, sm_strlen(data.s_gnl), data.s_gnl);
					if (LS_STYLE == 2)
						Ct_mprintf(data.s_gnl, sm_strlen(data.s_gnl) + 1, 1, 'A');
					else if (LS_STYLE == 1)
						printf(GRN"|"WHT);
					else
						printf(GRN"[OK]"WHT);
					sm_free(data.s_ls);
					sm_free(data.s_gnl);
					if (data.s_gnl == NULL && data.s_ls == NULL)
					{
						printf(GRN"\n✅ [OK]\n"WHT);
						system("echo '	✅[OK]\n' >> " OUTFILE);
						break ;
					}
				}
				else
				{
					printf(RED"\n❌ [KO]\n"WHT);
					system("echo '	❌ [KO]\n' >> " OUTFILE);
					printf("\nwas expecting :\n");
					system("echo 'was expecting :\n' >> " OUTFILE);
					cmd = combine("echo '%s' >> " OUTFILE, data.s_ls);
					system(cmd);
					sm_free(cmd);
					system("echo '⬆🆚⬇' >> " OUTFILE);
					cmd = combine("echo '%s' >> "OUTFILE, data.s_gnl);
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
					system("echo 'got :\n' >> " OUTFILE);
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
		system("echo 'bot///🔚\n' >> " OUTFILE);
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
