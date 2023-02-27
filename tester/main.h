/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 06:45:26 by wdelaros          #+#    #+#             */
/*   Updated: 2023/01/18 12:04:30 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

//			System			//
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <time.h>
# include "ls_gnl.h"

//			ls-tester		//
# include "color.h"
# define  GCC "gcc"
# define  GCCF "gcc -Wall -Werror -Wextra"
# define VAL "valgrind"
# define VALL "valgrind --leak-check=full"
# define TF "text/"
# define C_TOOLS "/C_tools/C_tool.a"

// system("ls | tee -a output.txt");

//				GNL				//
# define GNL_PATH_O " tester/GNL/GNL_main.c -o "
# define GNL_FT " tester/GNL/GNL_FT.c "
# define GNL_C "get_next_line/get_next_line.c"
# define GNLU_C "get_next_line/get_next_line_utils.c"
# define GNL_H "get_next_line/get_next_line.h"
# define VAL_GNL "get_next_line/get_next_line_utils.c get_next_line/get_next_line.c tester/main/GNL/val_gnl_main.c"
//				GNLB			//
# define GNLB_PATH_O " tester/GNL/GNLB_main.c -o "
# define GNLB_C "get_next_line/get_next_line_bonus.c"
# define GNLUB_C "get_next_line/get_next_line_utils_bonus.c"
# define GNLB_H "get_next_line/get_next_line_bonus.h"
# define VAL_GNLB "get_next_line/get_next_line_utils_bonus.c get_next_line/get_next_line_bonus.c tester/main/GNL/val_gnl_main.c"
//				FT_PRINTF		//
# define FT_PRINTF "ft_printf"


void	logo(void);
void	*ft_sfree(void *p);
int		test_take_time(void);
void	gnl_buffer_tester(void);
void	put_time_file(char type, char *file);
char	*menu_loop(int *loop, char *call_back);

# include "sm_ft.h"


//char	*get_next_line(int fd);
char	*sm_ft_strjoin(char *s1, char *s2);

void	new_gnl_test(void);

//-----------------------------------------------

//--------- wdelaros ft
int		peepy_atoi(const char *str);
int		intlen(long int n, int base);

//tester INT32_MAX / 50

void	printf_tester(void);

#endif
