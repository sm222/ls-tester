/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:04:36 by anboisve          #+#    #+#             */
/*   Updated: 2022/12/01 07:41:43 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

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

int	compare(char *f1, int argc, char *argv[])
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
		printf(RED"\n[KO]\n"WHT);
		system("echo '[KO]\n' >> tester/GNL/GNL_dif.txt");
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
			printf(RED"\n[KO]\n"WHT);
			system("echo '[KO]\n' >> tester/GNL/GNL_dif.txt");
		}
		else
		{
			printf(GRN"\n[OK]\n"WHT);
			system("echo '[OK]\n' >> tester/GNL/GNL_dif.txt");
		}
	}
	fclose(fp1);
	fclose(fp2);
	return (0);
}

//
int	main(int ac, char **av)
{
	int		fd;
	char	*tmp;
	char	*tmp2;
	int		i;
	int		test;
	clock_t	start, end, duration, start1, end1, duration1;

	if (system("touch tester/GNL/GNL_dif.txt"))
		printf(RED"can't make file"WHT);
	system("echo '\nStart of Test - - -'$(date '+ %A %d %B %Y%n %T')'\n' >> tester/GNL/GNL_dif.txt");
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
			printf(GRN"%4d "YEL"%4zu"WHT" = %s", i + 1, peepy_strlen(tmp), tmp);
			peepyfree(tmp);
			i++;
			usleep(2000);
			if (i > 13000)
			{
				printf(RED"Never return NULL!\n"WHT);
				system("echo break\n >> tester/GNL/GNL_dif.txt");
				break ;
			}
		}
		end = clock();
		duration = (end - start);
		//sleep(2);
		tmp2 = combine("diff -a tester/text/result.txt %s >> tester/GNL/GNL_dif.txt", av[ac]);
		printf("\n %s", ac[av]);
		system(tmp2);
		free(tmp2);
		tmp2 = combine("echo %s >> tester/GNL/GNL_dif.txt", av[ac]);
		system(tmp2);
		free(tmp2);
		close(test);
		compare("tester/text/result.txt", ac, av);
		system("rm tester/text/result.txt");
		printf(RESET WHT"\ntime call -- %d\n", i);
		printf(WHT"total line read -- %d\n", --i);
		printf(YEL"test time taken : %.2f seconds\n"WHT, (double)duration/CLOCKS_PER_SEC  * 100);
	}
	end1 = clock();
	duration1 = (end1 - start1);
	system("echo '\nEnd of Test - - -'$(date '+ %A %d %B %Y%n %T')'\n' >> tester/GNL/GNL_dif.txt");
	printf(RED"\ntotal time taken : %.2f seconds\n"WHT, (double)duration1/CLOCKS_PER_SEC  * 100);
	printf(MAG"[error log: %s]\n", "tester/GNL/GNL_dif.txt"WHT);
}

//system("gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main_utils.c get_next_line_main.c -D ");