/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:04:36 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/27 16:59:07 by anboisve         ###   ########.fr       */
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

int	main(int ac, char **av)
{
	int		fd;
	char	*tmp;
	int		i;

	(void)ac;
	i = 0;
	fd = open("main/text/peepy.ans", O_RDONLY);
	if (fd < 0)
		printf(RED"can't open file\n"WHT);
	tmp = "\n";
	while (tmp)
	{
		tmp = get_next_line(fd);
		printf(GRN"%4d "YEL"%4zu"WHT" = %s", i + 1, peepy_strlen(tmp), tmp);
		peepyfree(tmp);
		i++;
		if (i > 10000)
		{
			printf(RED"Never return NULL!\n"WHT);
			break ;
		}
	}
	printf(RESET WHT"\ntime call -- %d\n", i);
	printf(WHT"\ntotal line read -- %d\n", --i);
	printf(RED"!%s\n!"WHT, av[1]);
}

//system("gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main_utils.c get_next_line_main.c -D ");