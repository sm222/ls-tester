/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GNL.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:05:44 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/29 14:16:33 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# define	RED		"\x1B[31m"
# define	GRN		"\x1B[32m"
# define	YEL		"\x1B[33m"
# define	BLU		"\x1B[34m"
# define	MAG		"\x1B[35m"
# define	CYN		"\x1B[36m"
# define	WHT		"\x1B[37m"
# define	RESET	"\x1B[0m"
# define	CLE		"\e[1;1H\e[2J"

# define	NB_CHAR	"\x1b[38;5;6m"
# define	LINE	"\x1b[38;5;28m"

// Standard Library headers
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdlib.h>
# include <stdarg.h>
# include <time.h>
# include "../../get_next_line/get_next_line.h"

// Function declarations

#endif // GNL_H