/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:46:54 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/28 13:10:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	logo(void)
{
	printf("\x1b[40m");
	printf(RED"          ██╗      "BLU" ██████╗     "GRN"████████╗ "YEL"███████╗ "MAG" ██████╗ "CYN"████████╗"PIK" ███████╗"ORG " ██████╗      \n");
	printf(RED"          ██║      "BLU"██╔════╝     "GRN"╚══██╔══╝ "YEL"██╔════╝ "MAG"██╔════╝ "CYN"╚══██╔══╝"PIK" ██╔════╝"ORG " ██╔══██╗     \n");
	printf(RED"          ██║      "BLU"╚█████╗      "GRN"   ██║    "YEL"█████╗   "MAG"╚█████╗  "CYN"   ██║   "PIK" █████╗  "ORG " ██████╔╝     \n");
	printf(RED"          ██║      "BLU" ╚═══██╗     "GRN"   ██║    "YEL"██╔══╝   "MAG" ╚═══██╗ "CYN"   ██║   "PIK" ██╔══╝  "ORG " ██╔══██╗     \n");
	printf(RED"          ███████╗ "BLU"██████╔╝     "GRN"   ██║    "YEL"███████╗ "MAG"██████╔╝ "CYN"   ██║   "PIK" ███████╗"ORG " ██║  ██║     \n");
	printf(RED"          ╚══════╝ "BLU"╚═════╝      "GRN"   ╚═╝    "YEL"╚══════╝ "MAG"╚═════╝  "CYN"   ╚═╝   "PIK" ╚══════╝"ORG " ╚═╝  ╚═╝     \n");
	printf("\x1b[0m");
	printf("				Made by "GRN" wdelaros, "BLU"anboisve,"GRN" brheaume"WHT"\n");
}

void	*xfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

// int	intlen(long int n, int base)
// {
// 	int	i;

// 	i = 1;
// 	if (n < 0)
// 	{
// 		n *= -1;
// 		i++;
// 	}
// 	while (n > (base - 1))
// 	{
// 		n /= base;
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_itoa(int n)
// {
// 	char		*str;
// 	int			len;
// 	long int	nb;

// 	nb = n;
// 	len = intlen(nb);
// 	str = calloc(len * sizeof(char) + 1);
// 	if (!str)
// 		return (0);
// 	if (nb == 0)
// 		str[len--] = 48;
// 	if (nb < 0)
// 	{
// 		str[0] = 45;
// 		nb *= -1;
// 	}
// 	while (nb > 0)
// 	{
// 		str[len--] = (nb % 10) + 48;
// 		nb /= 10;
// 	}
// 	return (str);
// }

// static size_t	peepy_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!s)
// 		return (0);
// 	while (s[i++])
// 		continue ;
// 	return (i - 1);
// }

// char	*ft_str_f_join(char *s1, char *s2, int nb)
// {
// 	int		i;
// 	int		j;
// 	int		k;
// 	char	*str;

// 	i = 0;
// 	j = 0;
// 	k = 0;
// 	str = calloc(peepy_strlen(s1) + peepy_strlen(s2) + intlen(nb) + 1, sizeof(char));
// 	if (!str)
// 		return (str = xfree(str));
// 	while (s1[i])
// 		str[j++] = s1[i++];
// 	while (s2[k])
// 		str[j++] = s2[k++];
// 	i = 0;
// 	while (++i <= intlen(nb))
// 		str[peepy_strlen(s1) + peepy_strlen(s2) + i] = itoa(nb);
// 	return (xfree(s1), str);
// }
