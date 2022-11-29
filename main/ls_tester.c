/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_tester.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdelaros <wdelaros@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 08:56:56 by anboisve          #+#    #+#             */
/*   Updated: 2022/11/29 13:22:36 by wdelaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

char	*menu_loop(int *loop, char *call_back)
{
	int		size_i = 80;
	char	u_input[size_i];
	char	copy[size_i];
	int		str_p = 0;
	char	up[4] = {27, 91, 65, 0};

	if (call_back != NULL)
		printf("lc : "YEL "%s\n" WHT, call_back);
	printf("ls-tester: ");
	//						look for recall input					//
	if (call_back && *loop == 1)
	{
		*loop = 0;
		sm_copy_str_to(call_back, u_input, 0, -1);
		free(call_back);
	}
	else
	{
		*loop = 0;
		sm_get_keybord_input(u_input, size_i);
		sm_clear_str(u_input);
	}
	str_p = 0;
	//							help func							//
	if (sm_func_looking(u_input, "help", &str_p) == 0)
	{
		if(sm_func_looking(u_input, "", &str_p) == 0)
		{
			printf("\nHelp List\n");
			printf("gnl - GNL tester\n");
			printf("norm - norminette all the files\n");
			printf("exit or q - exit the program\n");
			printf("\n");
		}
		else
		{
			sm_copy_str_to(u_input ,copy ,str_p +1,-1);
			printf(YEL "help "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		
		return (sm_str_dup(u_input));
	}
	//						PRINTF								//
	/* else if (sm_func_looking(u_input,"printf", &str_p) == 0)
	{
		if (sm_func_looking(u_input,"-a",&str_p) == 0)
		{
			printf("help list -a\n");
			printf("\n");
		}
		else if(sm_func_looking(u_input, "", &str_p) == 0)
			printf_tester();
		else
		{
			sm_copy_str_to(u_input ,copy ,str_p +1,-1);
			printf(YEL "printf "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return(sm_str_dup(u_input));
	} */
	//							GNL									//
	else if (sm_func_looking(u_input,"gnl", &str_p) == 0)
	{
		if (sm_func_looking(u_input,"-a",&str_p) == 0)
		{
			printf("help list -a\n");
			printf("\n");
		}
		else if(sm_func_looking(u_input, "", &str_p) == 0)
			gnl_tester();
		else
		{
			sm_copy_str_to(u_input ,copy ,str_p +1,-1);
			printf(YEL "gnl "RED"%s " WHT "is not a valid argumant\n", copy);
		}
		return(sm_str_dup(u_input));
	}
	//							NORMINETTE							//
	else if (sm_func_looking(u_input,"norm", &str_p) == 0)
	{
		printf(BLU"\n-	"GRN"-	"RED"-	\n");
		system("echo " WHT);
		system("norminette *.c *.h");
		printf(RED"\n-	"GRN"-	"BLU"-	\n"WHT);
		return(sm_str_dup(u_input));
	}
	//							example								//
	else if (sm_func_looking(u_input,("yes"), &str_p) == 0)
	{
		if(sm_find_mix_str(u_input,("itwork"), &str_p) == 0)
			printf("yes\n");
	}
	//							void								//
	else if (sm_func_looking(u_input,(""), &str_p) == 0)
		return(call_back);
	//							UP									//
	else if (sm_func_looking(u_input,(up), &str_p) == 0)
	{
		*loop = 1;
		printf("\n");
		return(call_back);
	}
	//							exit								//
	else if (sm_func_looking(u_input,("exit"), &str_p) == 0 || sm_func_looking(u_input,("q"), &str_p) == 0)
	{
		if (call_back)
			free(call_back);
		exit(0);
	}
	//							default								//
	else
		printf(RED"%s " WHT"is not a valid input\n",u_input);
	return(sm_str_dup(u_input));
}

int	main(void)
{
	int		loop;
	char	*last_call;

	loop = 0;
	logo();
	printf("this is not a finish product\n");
	last_call = NULL;
	while (1)
		last_call = menu_loop(&loop, last_call);
	return (0);
}
