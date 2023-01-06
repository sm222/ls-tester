/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNLB_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:45:32 by anboisve          #+#    #+#             */
/*   Updated: 2022/12/03 14:45:32 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

/*
normale str len
*/
static size_t	peepy_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i++])
		continue ;
	return (i - 1);
}

/*
free p if not NULL, and return NULL
*/
void	*peepyfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

//
static int	ft_num_s(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{	
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_set_str(char *s, int i, int long n)
{
	if (i > 0)
	{
		s[i] = n % 10 + '0';
		ft_set_str(s, i - 1, n / 10);
	}
	else
		s[i] = n % 10 + '0';
}

/*
int to *str
*/
char	*ft_itoa(int n)
{
	char		*r;
	long int	temp;

	temp = n;
	r = calloc(ft_num_s(n) + 1, sizeof(char));
	if (!r)
		return (NULL);
	else if (temp < 0)
		temp = temp * -1;
	ft_set_str(r, ft_num_s(n) - 1, temp);
	if (n < 0)
		r[0] = '-';
	return (r);
}

/*
dup the 's' str
*/
char	*sm_str_dup(char	*s)
{
	size_t	i;
	char	*new;

	i = 0;
	while(s && s[i])
		i++;
	new = calloc(i, sizeof(char));
	while (i--)
		new[i] = s[i];
	return (new);
}

/*
str join but free *sfree
*/
char	*ft_str_fback_join(char *sfree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = strlen(sfree);
	s2_i = strlen(s2);
	new = calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = peepyfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = sfree[s1_i];
	return (peepyfree(sfree), new);
}

/*
str join but free *sfree
*/
char	*ft_str_ffront_join(char *s1, char *sfree)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = strlen(s1);
	s2_i = strlen(sfree);
	new = calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = peepyfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = sfree[s2_i];
	while (s1_i--)
		new[s1_i] = s1[s1_i];
	return (peepyfree(sfree), new);
}

/*
normale str join
*/
char	*f_strjoin(char *s1, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = strlen(s1);
	s2_i = strlen(s2);
	new = calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = peepyfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = s1[s1_i];
	return (new);
}

/*
str join, but free the 2 old str
*/
char	*ft_str_ff_join(char *s1f, char *s2f)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = strlen(s1f);
	s2_i = strlen(s2f);
	new = calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = peepyfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2f[s2_i];
	while (s1_i--)
		new[s1_i] = s1f[s1_i];
	return (peepyfree(s1f), peepyfree(s2f), new);
}

char	*ft_join_select(va_list list, char c)
{
	if (c == 'i' || c == 'd')
		return (ft_itoa(va_arg(list, int)));
	else if (c == 's')
		return (sm_str_dup(va_arg(list, char *)));
	return (NULL);
}

/*
add one char at the end of *str
(like a realloc)
*/
char	*str_join_char(char *s, char c)
{
	size_t	size;
	char	*new;

	size = peepy_strlen(s) + 1;
	new = calloc(size + 1, sizeof(char));
	new = strcpy(new, s);
	new[size - 1] = c;
	free(s);
	return (new);
}

/*
make a new str from str and va_arg;
use like a printf
*/
char	*combine(char *s, ...)
{
	va_list	list;
	size_t	i;
	char	*new;
	
	va_start(list, s);
	new = calloc(1, sizeof(char));
	i = 0;
	while (s[i])
	{
		if(s[i] != '%')
			new = str_join_char(new, s[i++]);
		else
		{
			new = ft_str_ff_join(new, ft_join_select(list, s[++i]));
			i++;
		}
	}
	va_end(list);
	return (new);
}

/*
	f1 is the first file 
	argv is the array the file.
	argc is the file you want in the argv
*/
int	compare(char *f1, int argc, char **argv)
{
	FILE	*fp1;
	FILE	*fp2;
	int		cnt1 = 0;
	int		cnt2 = 0;
	int		flg = 0;

	fp1 = fopen(f1, "r");
	if (fp1 == NULL)
	{
		printf("\n%s File can not be opened : \n", argv[1]);
		return (-1);
	}
	// move file pointer to end and get total number of bytes
	fseek(fp1, 0, SEEK_END);
	cnt1 = ftell(fp1);
	fp2 = fopen(argv[argc], "r");
	if (fp2 == NULL)
	{
		printf("\n%s File can not be opened : \n", argv[2]);
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
		system("echo '>❌[KO]' >> tester/GNL/GNLB_dif.txt");
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
			system("echo '>❌[KO]' >> tester/GNL/GNLB_dif.txt");
		}
		else
		{
			printf(GRN"\n✅[OK]\n"WHT);
			system("echo '	✅[OK]' >> tester/GNL/GNLB_dif.txt");
			fclose(fp1);
			fclose(fp2);
			return(1);
		}
	}
	fclose(fp1);
	fclose(fp2);
	return (0);
}

/*
take 3 files as the test
*/
int	multy_test(char *f1, char *f2, char *f3)
{
	int		index;
	int		fd[3], fd_r[3], i[3];
	char	*tmp[3], *cmd, *av[3];

	av[0] = f1;
	av[1] = f2;
	av[2] = f3;

	index = 0;
	while (index < 3)
		i[index++] = 1;
	fd[0] = open(f1,O_RDONLY);
	fd[1] = open(f2,O_RDONLY);
	fd[2] = open(f3,O_RDONLY);
	if (fd[0] < 0 || fd[1] < 0 || fd[2] < 0)
		return (-1);
	index = 0;
	while (index < 3)
		tmp[index++] = "ls-tester";
	//rm files
	index = 0;
	while (index < 3)
	{
		cmd = combine("rm tester/text/mul%d.txt 2> /dev/null",index++);
		system(cmd);
		free(cmd);
	}
	//make files
	index = 0;
	while (index < 3)
	{
		cmd = combine("touch tester/text/mul%d.txt",index++);
		system(cmd);
		free(cmd);
	}
	index = 0;
	while (index < 3)
	{
		cmd = combine("tester/text/mul%d.txt",index);
		fd_r[index++] = open(cmd,O_RDWR);
		free(cmd);
	}
	//
	while (1)
	{
		usleep(2000);
		//
		tmp[0] = get_next_line(fd[0]);
		tmp[1] = get_next_line(fd[1]);
		tmp[2] = get_next_line(fd[2]);
		//
		printf(LINE"%4d "NB_CHAR"%4zu"GRN" [fd 1]"WHT" : %s"RESET, i[0], peepy_strlen(tmp[0]),tmp[0]);
		printf(LINE"%4d "NB_CHAR"%4zu"BLU" [fd 2]"WHT" : %s"RESET, i[1], peepy_strlen(tmp[1]),tmp[1]);
		printf(LINE"%4d "NB_CHAR"%4zu"MAG" [fd 3]"WHT" : %s"RESET, i[2], peepy_strlen(tmp[2]),tmp[2]);
		//
		if (tmp[0])
		{
			write(fd_r[0], tmp[0], peepy_strlen(tmp[0]));
			i[0]++;
			peepyfree(tmp[0]);
		}
		if (tmp[1])
		{
			write(fd_r[1], tmp[1], peepy_strlen(tmp[1]));
			i[1]++;
			peepyfree(tmp[1]);
		}
		if (tmp[2])
		{
			write(fd_r[2], tmp[2], peepy_strlen(tmp[2]));
			i[2]++;
			peepyfree(tmp[2]);
		}
		//
		if (i[0] > 13000 || i[1] > 13000 || i[2] > 13000)
		{
			printf(WHT"\n Never return "RED"NULL"WHT"!");
			break ;
		}
		if (tmp[0] == NULL && tmp[1] == NULL && tmp[2] == NULL)
			break ;
	}
	// 0
	cmd = combine("diff -a tester/text/mul0.txt %s >> tester/GNL/GNLB_dif.txt", f1);
	system(cmd);
	free(cmd);
	// 1
	cmd = combine("diff -a tester/text/mul1.txt %s >> tester/GNL/GNLB_dif.txt", f2);
	system(cmd);
	free(cmd);
	// 2
	cmd = combine("diff -a tester/text/mul2.txt %s >> tester/GNL/GNLB_dif.txt", f3);
	system(cmd);
	free(cmd);
	// --- // --- //
	index = 0;
	while (index < 3)
	{
		cmd = combine("tester/text/mul%d.txt", index);
		compare(cmd, index++, av);
		free(cmd);
	}
	index = 0;
	while (index < 3)
	{
		close(fd[index]);
		close(fd_r[index]);
		cmd = combine("rm tester/text/mul%d.txt", index);
		system(cmd);
		free(cmd);
		index++;
	}
	printf("\n"YEL"%d "WHT"total read \n\n", i[0] + i[1] + i[2]);
	system("echo 'finish test\n' >> tester/GNL/GNLB_dif.txt");
	return (0);
}

//
int	main(int ac, char **av)
{
	int		fd, i, test;
	char	*tmp;
	char	*tmp2;
	float	num, to = 0;
	clock_t	start, end, duration, start1, end1, duration1;

	num = ac - 1;
	if (system("touch tester/GNL/GNLB_dif.txt"))
		printf(RED"can't make file"WHT);
	start1 = clock();
	printf("BUFFER_SIZE = %d\n", BUFFER_SIZE);
	while (--ac)
	{
		sleep(3);
		printf(GRN"\n\n\n[file use : %s]\n"WHT, av[ac]);
		i = 0;
		fd = open(av[ac], O_RDONLY);
		if (fd < 0)
			printf(RED"can't open file\n"WHT);
		tmp = "\n";
		system("touch tester/text/result.txt");
		test = open("tester/text/result.txt", O_RDWR);
		if (BUFFER_SIZE <= 0 && get_next_line(fd) == NULL)
		{
			printf("work with invalid buffer size\n");
			system("rm tester/text/result.txt");
			exit(0);
		}
		start = clock();
		while (tmp)
		{
			tmp = get_next_line(fd);
			write(test, tmp, peepy_strlen(tmp));
			printf(LINE"%4d "NB_CHAR"%4zu"WHT" = %s", i + 1, peepy_strlen(tmp), tmp);
			peepyfree(tmp);
			i++;
			usleep(2000);
			if (i > 13000)
			{
				printf(RED"Never return NULL❗️\n"WHT);
				system("echo break\n >> tester/GNL/GNLB_dif.txt");
				to--;
				break ;
			}
		}
		end = clock();
		duration = (end - start);
		//
		tmp2 = combine("diff -a tester/text/result.txt %s >> tester/GNL/GNLB_dif.txt", av[ac]);
		printf("\n %s", ac[av]);
		system(tmp2);
		free(tmp2);
		//
		tmp2 = combine("echo %s >> tester/GNL/GNLB_dif.txt", av[ac]);
		system(tmp2);
		free(tmp2);
		//
		close(test);
		if (compare("tester/text/result.txt", ac, av))
			to++;
		system("rm tester/text/result.txt");
		printf(RESET WHT"\ntime call -- %d\n", i);
		printf(WHT"total line read -- %d\n", --i);
		printf(YEL"test time taken : %.2f seconds\n"WHT, (double)duration/CLOCKS_PER_SEC * 100);
	}
	end1 = clock();
	duration1 = (end1 - start1);
	to = (to / num) * 100;
	if (to == 100)
		printf(GRN "🎉");
	else
		printf(RED"❌");
	printf("you got %.0f%% - - - - - - - - - - - - - - - - -\n"WHT, to);
	sleep(5);
	system("echo '\n🔀start of multy test\n' >> tester/GNL/GNLB_dif.txt");
	multy_test("tester/text/m_fd1.txt","tester/text/m_fd2.txt","tester/text/m_fd3.txt");
	multy_test("tester/text/m_fd4.txt","tester/text/m_fd5.txt","tester/text/m_fd6.txt");
	multy_test("tester/text/peepy1.ans","tester/text/peepy2.ans","tester/text/peepy2.ans");
	system("echo '🔚end of multy test\n' >> tester/GNL/GNLB_dif.txt");
	printf(RED"\ntotal time taken : %.2f seconds\n"WHT, (double)duration1/CLOCKS_PER_SEC * 100);
	printf(MAG"[error log: tester/GNL/GNLB_dif.txt]\n"WHT);
	return (0);
}
//system("gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main_utils.c get_next_line_main.c -D ");