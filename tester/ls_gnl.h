/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_gnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 21:27:53 by anboisve          #+#    #+#             */
/*   Updated: 2023/02/05 21:27:53 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LS_GNL_H
# define LS_GNL_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_lsgnl
{
	char	*tmp;
	char	*tmp2;
	int		rv;
	size_t	cut;
}	t_lsgnl;

# define OUTFILE "tester/GNL/GNL_dif.txt"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*sm_get_next_line(int fd);

#endif // LS_GNL_H
