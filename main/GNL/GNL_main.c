/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:04:36 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/25 17:29:39 by wdelaros         ###   ########.fr       */
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

int	main(void)
{
	int		fd;
	char	*tmp;
	int		i;

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
	}
	printf(WHT"\ntime call -- %d\n", i);
	printf(WHT"\ntotal line read -- %d\n", --i);
}

//system("gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main_utils.c get_next_line_main.c -D ");