/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 07:25:09 by wdelaros          #+#    #+#             */
/*   Updated: 2022/12/01 13:53:26 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../main.h"

int		compare(char *f1, char *f2)
{
	FILE	*fp1, *fp2;
	int		cnt1 = 0;
	int		cnt2 = 0;
	int		flg = 0;

	fp1 = fopen(f1, "r");
	if (fp1 == NULL)
	{
		printf("\n%s File can not be opened : \n", f2);
		return (-1);
	}
	// move file pointer to end and get total number of bytes
	fseek(fp1, 0, SEEK_END);
	cnt1 = ftell(fp1);
	fp2 = fopen(f2, "r");
	if (fp2 == NULL)
	{
		printf("\n%s File can not be opened : \n", f2);
		return (-1);
	}
	// move file pointer to end and get total number of bytes
	fseek(fp2, 0, SEEK_END);
	cnt2 = ftell(fp2);
	fseek(fp1, 0, SEEK_SET);
	fseek(fp2, 0, SEEK_SET);
	// check for the total number of bytes
	if (cnt1 != cnt2)
	{
		printf(RED"\n❌[KO]\n"WHT);
		system("echo '>❌[KO]\n' >> tester/PRINTF/PRINTF_dif.txt");
	}
	else
	{
		while (!feof(fp1))
		{
			if (fgetc(fp1) != fgetc(fp2))
			{
				flg = 1;
				break ;
			}
		}
		if (flg)
		{
			printf(RED"\n❌[KO]\n"WHT);
			system("echo '>❌[KO]\n' >> tester/PRINTF/PRINTF_dif.txt");
		}
		else
		{
			printf(GRN"\n✅[OK]\n"WHT);
			system("echo '	✅[OK]\n' >> tester/PRINTF/PRINTF_dif.txt");
			fclose(fp1);
			fclose(fp2);
			return (1);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return (0);
}

int	check_ft_printf(int norm)
{
	int	verif[3];
	int	i;

	i = 0;
	verif[0] = open(FT_PRINTF"/Makefile", O_RDONLY);
	verif[1] = open(FT_PRINTF"/ft_printf.c", O_RDONLY);
	verif[2] = open(FT_PRINTF"/ft_printf.h", O_RDONLY);
	printf("looking for files  ");
	while (i++ < 3)
	{
		usleep(200000);
		printf(YEL"."WHT);
	}
	if (verif[0] < 0 || verif[1] < 0 || verif[2] < 0)
	{
		printf(RED"\nMissing file: ");
		if (verif[0] < 0)
			printf(RED "Makefile "WHT);
		if (verif[1] < 0)
			printf(RED "ft_printf.c "WHT);
		if (verif[2] < 0)
			printf(RED "ft_printf.h"WHT);
		printf("\n");
		return (-1);
	}
	printf(GRN"\nNo files missing, ready to go!\n"WHT);
	system("echo "WHT);
	if (system("norminette " FT_PRINTF) > 0)
	{
		norm = 1;
		printf(YEL "NORM ERROR !\n"WHT);
	}
	close(verif[0]);
	close(verif[1]);
	close(verif[2]);
	return (norm);
}

char	**get_test_pf(int fd)
{
	char	**new;
	char 	*s, *j = NULL;

	s = "ls";
	while (s)
	{
		s = sm_get_next_line(fd);
		j = ft_str_ff_join(j, s);
	}
	new = ft_split(j, '\n');
	if (j)
		free(j);
	return (new);
}

void	run_one_test_pf(char *test)
{
	char	*cmd;

	printf("input %s\n", test);
	cmd = combine(GCCF" tester/PRINTF/PF_main.c ft_printf/libftprintf.a -o pf.out -D IN_TEST='%s'", test);
	system(cmd);
	free(cmd);
	write(1, "real printf: ", 14);
	system("./pf.out r");
	system("./pf.out r > rp.txt");
	write(1, "\n42 printf  : ", 15);
	system("./pf.out f");
	system("./pf.out f > fp.txt");
	system("rm pf.out");
	system("diff -a rp.txt fp.txt >> tester/PRINTF/PRINTF_dif.txt");
	cmd = combine("echo 'input  %s' >> tester/PRINTF/PRINTF_dif.txt", test);
	system(cmd);
	free(cmd);
	compare("rp.txt", "fp.txt");
	system("rm fp.txt");
	system("rm rp.txt");
}

void	run_test_pf(char **test_in)
{
	char	*cmd;
	int		i = 0;

	while (test_in[i])
	{
		printf(YEL"test %d"WHT", input %s\n", i, test_in[i]);
		cmd = combine("     "GCCF" tester/PRINTF/PF_main.c ft_printf/libftprintf.a -o pf.out -D IN_TEST='%s'", test_in[i]);
		puts(cmd);
		system(cmd);
		free(cmd);
		write(1, "real printf: ", 14);
		system("./pf.out r");
		system("./pf.out r > rp.txt");
		write(1, "\n42 printf  : ", 15);
		system("./pf.out f");
		system("./pf.out f > fp.txt");
		system("rm pf.out");
		printf("\n\n");
		system("diff -a rp.txt fp.txt >> tester/PRINTF/PRINTF_dif.txt");
		cmd = combine("echo 'input  %s' >> tester/PRINTF/PRINTF_dif.txt", test_in[i]);
		system(cmd);
		free(cmd);
		compare("rp.txt", "fp.txt");
		i++;
		sleep(1);
	}
	system("rm fp.txt");
	system("rm rp.txt");
	printf("\n\n");
	return ;
}

void	printf_tester(void)
{
	int		fd, fd_file, i = 0;
	char	**test;
	char	*cmd;

	if (check_ft_printf(0) == -1)
		return ;
	system("(make re -C ft_printf >> .log.txt)");
	fd = open("ft_printf/libftprintf.a", O_RDONLY);
	if (fd < 0)
	{
		printf(RED"can't find libftprintf.a\n"WHT);
		return ;
	}
	close(fd);
	// normal str
	fd_file = open ("tester/text/pf_0.txt",O_RDONLY);
	test = get_test_pf(fd_file);
	close(fd_file);
	sm_inspect_arr(test[0], 'c', ft_strlen(test[0]), 0);
	run_test_pf(test);
	i = 0;
	while (test[i])
		free(test[i++]);
	free(test);
	//
	i = 0;
	while (i < 128)
	{
		cmd = combine("(\"%%c %%c %%c %%c %%c %%c\", %d, %d, %d , %d, %d, %d)", i, i + 1, i + 2, i + 3, i + 4, i + 5);
		run_one_test_pf(cmd);
		free(cmd);
		i += 6;
	}
	return ;
}