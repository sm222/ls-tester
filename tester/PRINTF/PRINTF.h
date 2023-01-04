/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PRINTF.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 21:12:06 by anboisve          #+#    #+#             */
/*   Updated: 2023/01/01 21:12:06 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# ifndef IN_TEST
#  define IN_TEST ("ls-tester %d", 42)
# endif

# ifndef INT_TEST
#  define INT_TEST 5
# endif

# ifndef CHAR_TEST
#  define CHAR_TEST 'a'
# endif

# ifndef STR_TEST
#  define STR_TEST "ls-tester"
# endif

# include <stdio.h>
# include "../../ft_printf/ft_printf.h"

#endif
