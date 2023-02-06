/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 19:42:36 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/04 19:42:36 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ls_gnl.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static void	*ft_sfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

static void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	while (n--)
		((char *)s)[n] = 0;
}

static void	*ft_calloc(size_t coun, size_t size)
{
	char	*new;

	new = malloc(coun * size);
	if (!new)
		return (NULL);
	ft_bzero(new, coun * size);
	return (new);
}

char	*ft_tiny_split(char *s, size_t *cut)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (new = ft_sfree(new));
	*cut = i;
	while (i--)
		new[i] = s[i];
	return (new);
}

char	ft_find(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ('\n');
		i++;
	}
	return ('0');
}

char	*sm_ft_strjoin(char *sfree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = ft_strlen(sfree);
	s2_i = ft_strlen(s2);
	new = ft_calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = ft_sfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = sfree[s1_i];
	if (*new == 0)
		new = ft_sfree(new);
	return (ft_sfree(sfree), new);
}

char	*sm_get_next_line(int fd)
{
	static char	*book;
	t_lsgnl		t_val;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 100000)
		return (book = ft_sfree(book));
	if (!book)
		book = ft_calloc(1, sizeof(char));
	t_val.rv = 1;
	t_val.tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ft_find(book) == '0')
	{
		ft_bzero(t_val.tmp, BUFFER_SIZE + 1);
		t_val.rv = read(fd, t_val.tmp, BUFFER_SIZE);
		if (t_val.rv <= 0)
			break ;
		book = sm_ft_strjoin(book, t_val.tmp);
	}
	t_val.tmp = ft_sfree(t_val.tmp);
	if (t_val.rv == -1 || (t_val.rv <= 0 && *book == 0))
		return (book = ft_sfree(book), NULL);
	t_val.tmp = ft_tiny_split(book, &t_val.cut);
	t_val.tmp2 = book;
	book = sm_ft_strjoin(NULL, book + t_val.cut);
	return (ft_sfree(t_val.tmp2), t_val.tmp);
}
