/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:46:54 by wdelaros          #+#    #+#             */
/*   Updated: 2022/12/17 20:15:14 by anboisve         ###   ########.fr       */
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

void	*ft_sfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

//	system("echo '\nStart of Test - - -⏱'$(date '+ %A %d %B %Y%n %T')'\n' >> tester/GNL/GNL_dif.txt");