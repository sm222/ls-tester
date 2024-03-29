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

# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>
# include <time.h>

//			System			//

# define  GCC "gcc"
# define  GCCF "gcc -Wall -Werror -Wextra"
# define VAL "valgrind"
# define VALL "valgrind --leak-check=full"
# define TF "text/"

// system("ls | tee -a output.txt");

//				GNL				//
# define GNL_PATH_O " tester/GNL/GNL_main.c -o "
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

//--			Color			--//
//https://talyian.github.io/ansicolors/
//	https://ansi.gabebanks.net/
# define RED	"\x1B[31m"
# define GRN	"\x1B[32m"
# define YEL	"\x1B[33m"
# define BLU	"\x1B[34m"
# define MAG	"\x1B[35m"
# define CYN	"\x1B[36m"
# define WHT	"\x1B[37m"
# define RESET	"\x1B[0m"
# define ORG	"\x1b[38;5;202m"
# define PIK	"\x1b[38;5;176m"
# define CLE 	"\e[1;1H\e[2J"
/*
	text art
http://www.patorjk.com/software/taag/#p=display&f=Slant%20Relief&t=
*/
void	logo(void);
void	*ft_sfree(void *p);
int		test_take_time(void);
void	gnl_buffer_tester(void);
void	put_time_file(char type, char *file);
char	*menu_loop(int *loop, char *call_back);

//--------- anboisve ft

//gnl
int		gnl_mem_info(void);
void	gnl_tester(int buff);
void	gnlb_tester(int buff);
int		gnl_mem(int test, int BS);
void	gnl_partial_tester(int buff, char *test);

//text
int		sm_atoi(char *str);
char	*combine(char *s, ...);
void	sm_clear_str(char *str);
char	**ft_split(char const *s, char c);
int		sm_look_for_word(char *str, char *word);
int		sm_while_space_tab(int start, char *str);
int		sm_get_keybord_input(char *return_txt, int size);
int		sm_copy_str_to(char *input, char *return_v, int start_p, int end_p);

//menu
int		sm_ls(char *path);
void	val_install(void);
void	sm_signature(void);
int		sm_print_file(char *name);
void	sm_make_file_name(char *name);
void	sm_log(int fd, char *from, char *log);
int		sm_func_looking(char *str, char *word, int *path);
int		sm_find_mix_str(char *str, char *word, int *path);
int		sm_look_for_char_p(char *str, int start_p, int number, char look);

//other
int		sm_r_num(int lower, int upper);
void	sm_inspect_arr(void *p, char type, int size, int color);
void	noise(int loop, int size);
void	*sm_calloc(size_t type, size_t size);
void	show_color(void);
void	*sm_bzero(void *p, size_t size);
char	*sm_str_dup(char	*s);
char	*ft_str_ffront_join(char *s1, char *sfree);
char	*ft_str_fback_join(char *sfree, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_str_ff_join(char *s1f, char *s2f);
char	*ft_itoa(int n);
char	*f_strjoin(char *s1, char *s2);
void	*ft_calloc(size_t coun, size_t size);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);
char	*sm_get_next_line(int fd);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

typedef struct s_info
{
	char	*tmp;
	char	*tmp2;
	int		rv;
	size_t	cut;
}	t_info;

//char	*get_next_line(int fd);
char	*sm_ft_strjoin(char *s1, char *s2);

//-----------------------------------------------

//--------- wdelaros ft
int		peepy_atoi(const char *str);
int		intlen(long int n, int base);

//tester INT32_MAX / 50

void	printf_tester(void);

#endif
