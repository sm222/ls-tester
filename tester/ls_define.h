/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_define.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 20:55:13 by anboisve          #+#    #+#             */
/*   Updated: 2023/03/14 20:55:13 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef LS_DEFINE_H
# define LS_DEFINE_H

/*
LS_FULL_TEST
LS_INSP_TEST
LS_RMFILE
LS_SPEED
*/

# ifndef LS_FULL_TEST
//run the test event if you fail
#  define LS_FULL_TEST_T "LS_FULL_TEST"
#  define LS_FULL_TEST 0
# endif


# ifndef LS_INSP_TEST
//be carfull hard to see with big files
#  define LS_INSP_TEST_T "LS_INSP_TEST"
#  define LS_INSP_TEST 0
# endif

# ifndef LS_RMFILE
//be carfull hard to see with big files/line
#  define LS_RMFILE_T "LS_RMFILE"
#  define LS_RMFILE 1
# endif

# ifndef LS_STYLE
//type of style on scren 
#  define LS_STYLE_T "LS_STYLE"
#  define LS_STYLE 0
# endif


# ifndef LS_SPEED
//sleep speed betwen the test in ulseep, LS_SPEED * 1000
#  define LS_SPEED_T "LS_SPEED"
#  define LS_SPEED 1
# endif

# ifndef LS_TRACE
//sleep speed betwen the test in ulseep, LS_SPEED * 1000
#  define LS_TRACE_T "LS_TRACE"
#  define LS_TRACE 0
# endif


#endif // LS_DEFINE_H
