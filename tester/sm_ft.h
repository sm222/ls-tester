/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sm_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:30:44 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/24 18:30:44 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SM_FT_H
# define SM_FT_H

# include "sm_ft.h"
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <stdarg.h>

# define SM_FT "tester/anboisve_ft.c"

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
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);

//menu
void	val_install(void);
int		sm_print_file(char *name);
void	sm_make_file_name(char *name);
void	sm_log(int fd, char *from, char *log);
int		sm_func_looking(char *str, char *word, int *path);
int		sm_find_mix_str(char *str, char *word, int *path);
int		sm_look_for_char_p(char *str, int start_p, int number, char look);

//other
int		ft_memcmp(const void *s1, const void *s2, size_t n);
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
void	*sm_calloc(size_t coun, size_t size);
size_t	sm_strlen(const char *s);
void	*sm_free(void *ptr);
void	sm_putstr(char *s, int fd);

#endif // SM_FT_H
