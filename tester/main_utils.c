/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:46:54 by wdelaros          #+#    #+#             */
/*   Updated: 2022/12/01 07:12:48 by wdelaros         ###   ########.fr       */
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
