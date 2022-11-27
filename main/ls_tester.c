/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anboisve <anboisve@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:56:56 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/27 09:24:49 by anboisve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void menu_loop(char *name,char *call_back)
{
    int size_i = 80;
    char u_input[size_i];
    char copy[size_i];
    int str_p = 0;
    //look for recall input
    if (sm_func_looking(call_back,"",&str_p) == 0)
    {
        printf("%s: ",name);
        sm_get_keybord_input(u_input, size_i);
        sm_clear_str(u_input);
    }
    else
        sm_copy_str_to(call_back, u_input, 0, -1);
    str_p = 0;
    //help func
    if (sm_func_looking(u_input,("help"), &str_p) == 0)
    {
        if (sm_func_looking(u_input,"-a",&str_p) == 0)
        {
			printf("help list -a\n\n");
			printf("\n");
        }
        else if(sm_func_looking(u_input,"",&str_p) == 0)
        {
            printf("help list\n\n");
            printf("\n");
        }
        else
        {
            sm_copy_str_to(u_input ,copy ,str_p +1,-1);
            printf(YEL "help "RED"%s " WHT "is not a valid argumant\n",copy);
        }
        menu_loop(name,"");
        return;
    }
    else if (sm_func_looking(u_input,("gnl"), &str_p) == 0)
    {
        if (sm_func_looking(u_input,"-a",&str_p) == 0)
        {
			printf("help list -a\n\n");
			printf("\n");
        }
        else if(sm_func_looking(u_input,"",&str_p) == 0)
            gnl_tester();
        else
        {
            sm_copy_str_to(u_input ,copy ,str_p +1,-1);
            printf(YEL "gnl "RED"%s " WHT "is not a valid argumant\n",copy);
        }
        menu_loop(name,"");
        return;
    }
    //example
    else if (sm_func_looking(u_input,("yes"), &str_p) == 0)
    {
        if(sm_find_mix_str(u_input,("itwork"), &str_p) == 0)
            printf("yes\n");
        menu_loop(name,"");
    }
    //void
    else if (sm_func_looking(u_input,(""), &str_p) == 0)
    {
        menu_loop(name,"");
        return;
    }
    //exit
    else if (sm_func_looking(u_input,("exit"), &str_p) == 0)
        exit(0);
    //default 
    else
    {
        printf(RED"%s " WHT"is not a valid input\n",u_input);
        menu_loop(name,"");
    }
}

int	main(void)
{
    printf(CLE);
	logo();
	printf("this is not a finish product\n");
    menu_loop("ls-tester","");

	return (0);
}
