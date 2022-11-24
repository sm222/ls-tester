/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:45:26 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/24 09:01:38 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "../get_next_line/get_next_line_bonus.h"
# include "../get_next_line/get_next_line.h"
# include "../printf/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

# ifndef INDEX
#  define INDEX 0
# endif

# define RED    "\x1B[31m"
# define GRN    "\x1B[32m"
# define YEL    "\x1B[33m"
# define BLU    "\x1B[34m"
# define MAG    "\x1B[35m"
# define CYN    "\x1B[36m"
# define WHT    "\x1B[37m"
# define RESET  "\x1B[0m"
# define CLE    "\e[1;1H\e[2J"

void	*xfree(void *p);

#endif