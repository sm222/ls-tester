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
	char	*tmp;
	char	*name;
	float	bad, to = 0;

	cmd = NULL;
	data.loop = 1;
	bad = 0;
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("BUFFER_SIZE = %d\n\n", BUFFER_SIZE);
	while (--ac)
	{
		data.loop = 1;
		printf(MAG"%s\n"WHT, av[ac]);
		data.fd[0] = open(av[ac], O_RDONLY);
		data.fd[1] = open(av[ac], O_RDONLY);
		if ((data.fd[0] < 0 && data.fd[1] >= 0) || (data.fd[1] < 0 && data.fd[0] >= 0))
		{
			ls_printf(2, RED"one open fail to get the in file\n"WHT);
			return (1);
		}
		printf("open fd		/%d|%d\\\n", data.fd[0], data.fd[1]);
		data.s_ls  = NULL;
		data.s_gnl = NULL;
		data.out_fd[0] = open("ls_out",  O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data.out_fd[0] < 0)
			ls_printf(2, RED"can't make: ls_out"WHT);
		data.out_fd[1] = open("gnl_out", O_RDWR | O_CREAT | O_TRUNC, 0644);
		if (data.out_fd[1] < 0)
			ls_printf(2, RED"can't make: gnl_out"WHT);
		if (LS_TRACE)
		{
			name = sm_strrchr(av[ac], '/');
			name++;
			tmp = combine("tester/trace/tester_%s.trace", name);
			data.trace[0] = open(tmp,  O_RDWR | O_CREAT , 0644);
			if (data.trace[0] < 0)
				ls_printf(2, "can't make trace :"RED" %s\n"WHT, tmp);
			sm_free(tmp);
			tmp = combine("tester/trace/user_%s.trace", name);
			data.trace[1] = open(tmp, O_RDWR | O_CREAT , 0644);
			if (data.trace[1] < 0)
				ls_printf(2, "can't make trace :"RED" %s\n"WHT, tmp);
			sm_free(tmp);
		}
		ls_printf(1, "open fd_out	/%d|%d\\\n", data.out_fd[0], data.out_fd[1]);
		cmd = combine("echo -n '🔽 file test %s \n' >> " OUTFILE, av[ac]);
		system(cmd);
		sm_free(cmd);
		sleep(1);
		system("echo 'top\\\\\\\\' >> " OUTFILE);
		while (data.loop)
		{
			usleep(LS_SPEED * 1000);
			to++;
			data.s_ls = sm_get_next_line(data.fd[0]);
			data.s_gnl  =  get_next_line(data.fd[1]);
			ls_printf(data.out_fd[0], "%s", data.s_ls);
			ls_printf(data.out_fd[1], "%s", data.s_gnl);
			if (LS_TRACE)
			{
				ls_printf(data.trace[0], "%s", data.s_ls);
				ls_printf(data.trace[1], "%s", data.s_gnl);
			}
			if (ft_memcmp(data.s_gnl, data.s_ls, sm_strlen(data.s_ls) + 1) == 0)
			{
				if (LS_STYLE == 5)
					ls_printf(1, GRN "" GOOD"" WHT);
				else if (LS_STYLE == 4)
					ls_printf(1, "✅");
				else if (LS_STYLE == 3)
					fprintf(stderr ,LINE"%3d "NB_CHAR"%4zu"RESET" %s", data.loop, sm_strlen(data.s_gnl), data.s_gnl);
				else if (LS_STYLE == 2)
					Ct_mprintf(data.s_gnl, sm_strlen(data.s_gnl) + 1, 1, 'A');
				else if (LS_STYLE == 1)
					ls_printf(1, GRN"|"WHT);
				else
					ls_printf(1, GRN"[OK]"WHT);
				if (LS_FULL_TEST)
				{
					cmd = combine("echo '✅%d' >> " OUTFILE, data.loop);
					system(cmd);
					sm_free(cmd);
				}
				if (data.s_gnl == NULL && data.s_ls == NULL)
				{
					if (bad == 0)
						ls_printf(1, GRN"\n✅ [OK]\n"WHT);
					else
						ls_printf(1, RED"\n❌[KO]\n"WHT);
					break ;
				}
			}
			else
			{
				bad++;
				if (LS_STYLE == 5)
					ls_printf(1, RED"" BAD ""WHT);
				else if (LS_STYLE == 4)
					ls_printf(1, "❌");
				else if (LS_STYLE == 3)
					fprintf(stderr ,RED"%3d "NB_CHAR"%4zu"RESET" %s", data.loop, sm_strlen(data.s_gnl), data.s_gnl);
				else if (LS_STYLE == 2)
					Ct_mprintf(data.s_gnl, sm_strlen(data.s_gnl) + 1, 1, 'F');
				else if (LS_STYLE == 1)
					printf(RED"|"WHT);
				else
					printf(RED"[KO]"WHT);
				cmd = combine("echo '❌%d' >> " OUTFILE, data.loop);
				system(cmd);
				sm_free(cmd);
				system("echo '❌ [KO]' >> " OUTFILE);
				system("echo -n 'was expecting :' >> " OUTFILE);
				cmd = combine("echo '%s' >> " OUTFILE, data.s_ls);
				system(cmd);
				sm_free(cmd);
				system("echo '⬆⬇\n' >> " OUTFILE);
				system("echo -n 'got:' >> " OUTFILE);
				cmd = combine("echo '%s\n' >> " OUTFILE, data.s_gnl);
				system(cmd);
				sm_free(cmd);
				if (!LS_FULL_TEST)
					break ;
			}
			sm_free(data.s_ls);
			sm_free(data.s_gnl);
			data.loop++;
			if (data.s_ls == NULL)
			{
				cmd = combine("echo '❌%d' >> " OUTFILE, data.loop);
				system(cmd);
				sm_free(cmd);
				system("echo '❌ [KO]' >> " OUTFILE);
				break ;
			}
		}
		if (LS_TRACE)
		{
			close(data.trace[0]);
			close(data.trace[1]);
		}
		system("echo 'bot///\n' >> " OUTFILE);
		close(data.fd[0]);
		close(data.fd[1]);
		close(data.out_fd[0]);
		close(data.out_fd[1]);
		if (LS_RMFILE)
		{
			system("rm -f gnl_out");
			system("rm -f ls_out");
		}
		ls_printf(2,"\n");
	}
	to = (bad / to) * 100;
	if (bad)
	{
		ls_printf(1, RED"\n❌[KO]\n"WHT);
		if (LS_FULL_TEST)
			printf("you got %.0f%% bad line\n", to);
		ls_printf(1, RED"\n-"GRN"\n-"BLU"\n-"WHT"\n");
		return (2);
	}
	ls_printf(1, RED"\n-"GRN"\n-"BLU"\n-"WHT"\n");
	return (0);
}
