/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:04:36 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/28 17:51:32 by anboisve         ###   ########.fr       */
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
	size_t	j;
	char	*new;
	
	va_start(list, s);
	new = calloc(1, sizeof(char));
	i = 0;
	j = 0;
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
	return(new);
}


//
int	main(int ac, char **av)
{
	int		fd;
	char	*tmp;
	char	*tmp2;
	int		i;
	int		test;

	if (system("touch main/GNL/GNL_dif.txt"))
		printf(RED"can't make file"WHT);
	system("echo '\nStart of Test - - -'$(date '+ %A %d %B %Y%n %T')'\n' >> main/GNL/GNL_dif.txt");
	while (--ac)
	{
		sleep(1);
		printf(GRN"\n\n\n[file use : %s]\n"WHT, av[ac]);
		i = 0;
		//av[1] main/text/peepy.ans
		fd = open(av[ac], O_RDONLY);
		if (fd < 0)
			printf(RED"can't open file\n"WHT);
		tmp = "\n";
		system("touch main/text/result.txt");
		test = open("main/text/result.txt", O_RDWR);
		while (tmp)
		{
			tmp = get_next_line(fd);
			write(test, tmp, peepy_strlen(tmp));
			printf(GRN"%4d "YEL"%4zu"WHT" = %s", i + 1, peepy_strlen(tmp), tmp);
			peepyfree(tmp);
			i++;
			usleep(10000);
			if (i > 10000)
			{
				printf(RED"Never return NULL!\n"WHT);
				system("echo break\n >> main/GNL/GNL_dif.txt");
				
				break ;
			}
		}
		sleep(1);
		tmp2 = combine("diff -a main/text/result.txt %s >> main/GNL/GNL_dif.txt", av[ac]);
		printf("\n %s", ac[av]);
		system(tmp2);
		free(tmp2);
		close(test);
		system("rm main/text/result.txt");
		printf(RESET WHT"\ntime call -- %d\n", i);
		printf(WHT"total line read -- %d\n", --i);
	}
	system("echo '\nEnd of Test - - -'$(date '+ %A %d %B %Y%n %T')'\n' >> main/GNL/GNL_dif.txt");
}

//system("gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main_utils.c get_next_line_main.c -D ");