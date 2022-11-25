/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:46:54 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/25 18:10:29 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	logo(void)
{
	printf(RED"		██╗░░░░░"BLU"░██████╗	"GRN"████████╗"YEL"███████╗"MAG"░██████╗"CYN"████████╗"RED"███████╗"WHT"██████╗░\n");
	printf(RED"		██║░░░░░"BLU"██╔════╝	"GRN"╚══██╔══╝"YEL"██╔════╝"MAG"██╔════╝"CYN"╚══██╔══╝"RED"██╔════╝"WHT"██╔══██╗\n");
	printf(RED"		██║░░░░░"BLU"╚█████╗░	"GRN"░░░██║░░░"YEL"█████╗░░"MAG"╚█████╗░"CYN"░░░██║░░░"RED"█████╗░░"WHT"██████╔╝\n");
	printf(RED"		██║░░░░░"BLU"░╚═══██╗	"GRN"░░░██║░░░"YEL"██╔══╝░░"MAG"░╚═══██╗"CYN"░░░██║░░░"RED"██╔══╝░░"WHT"██╔══██╗\n");
	printf(RED"		███████╗"BLU"██████╔╝	"GRN"░░░██║░░░"YEL"███████╗"MAG"██████╔╝"CYN"░░░██║░░░"RED"███████╗"WHT"██║░░██║\n");
	printf(RED"		╚══════╝"BLU"╚═════╝░	"GRN"░░░╚═╝░░░"YEL"╚══════╝"MAG"╚═════╝░"CYN"░░░╚═╝░░░"RED"╚══════╝"WHT"╚═╝░░╚═╝\n");
	printf("				Made by "GRN" wdelaros, "BLU"anboisve,"GRN" brheaume"WHT"\n");
}

void	*xfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}
