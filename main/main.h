/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:45:26 by wdelaros          #+#    #+#             */
/*   Updated: 2022/11/24 17:52:50 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include "get_next_line.h"
# define  GCCF "gcc -Wall -Werror -Wextra"

//$(shell find . -name '*.c')

# ifndef INDEX
#  define INDEX 0
# endif

# define GNL_C "get_next_line.c"
# define GNLU_C "get_next_line_utils.c"
# define GNL_H "get_next_line.h"
# define GNLB_C "get_next_line_bonus.c"
# define GNLUB_C "get_next_line_utils_bonus.c"
# define GNLB_H "get_next_line_bonus.h"

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
void	logo(void);

#endif