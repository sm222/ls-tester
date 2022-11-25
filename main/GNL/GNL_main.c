/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:04:36 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/25 12:04:43 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "GNL.h"

static int	ft_intlen(long int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long int	nb;

	nb = n;
	len = ft_intlen(nb);
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	if (nb == 0)
		str[len--] = 48;
	if (nb < 0)
	{
		str[0] = 45;
		nb *= -1;
	}
	while (nb > 0)
	{
		str[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	return (str);
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
	char	*i;

	i = ft_itoa(C);
	fd = open("text/peepy.ans", O_RDONLY);
	if (fd < 0)
		printf("can't open file\n");
	tmp = "\n";
	while (tmp)
	{
		tmp = get_next_line(fd);
		printf("%s", tmp);
		peepyfree(tmp);
	}
	peepyfree(i);
}

//system("gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main_utils.c get_next_line_main.c -D ");