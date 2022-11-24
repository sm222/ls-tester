/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 11:42:18 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/24 16:34:35 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_getline(char *str)
{
	int		i;
	char	*line;

	i = 0;
	if (!str || !str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	if (!line)
	{
		line = ft_calloc(1, sizeof(char));
		return (line);
	}
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*nextline(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i] || !str)
		return (free(str), NULL);
	buff = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	if (!buff)
		return (free(str), NULL);
	i++;
	j = 0;
	while (str[i])
		buff[j++] = str[i++];
	return (free(str), buff);
}

char	*readstr(int fd, char *str)
{
	char	*buff;
	int		i;

	if (!str)
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
	}
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buff)
		return (free(str), NULL);
	i = 1;
	while (!(ft_strchr(str, '\n')) && i > 0)
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			return (free(buff), free(str), NULL);
		buff[i] = 0;
		str = ft_strjoin2(str, buff);
		if (!str)
			return (free(buff), NULL);
	}
	return (free(buff), str);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (free(str), NULL);
	str = readstr(fd, str);
	if (!str)
		return (NULL);
	line = ft_getline(str);
	str = nextline(str);
	return (line);
}
