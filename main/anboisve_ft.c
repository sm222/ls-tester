#include "main.h"

int sm_while_space_tab(int start,char *str)
{
	int i = start;
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	return(i);
}

int	sm_while_space(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return(1);

	return(-1);
}

int	sm_get_keybord_input(char *return_txt,int size)
{
    if(fgets(return_txt,size + 1,stdin))
    {
        char *p;
        if((p = strchr(return_txt, '\n')))
        {//check exist newline
            *p = 0;
        }
        else
        {
            scanf("%*[^\n]");
            scanf("%*c");
        }
    }
	return(strlen(return_txt));
}

void sm_clear_str(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	i--;
	while (str[i] == ' ' || str[i] == '\t')
		i--;
	str[i + 1] = '\0';
}

int		sm_r_num(int lower ,int upper)
{
	int swap;
	if (lower > upper)
	{
		swap = lower;
		lower = upper;
		upper = swap;
	}
	int numb = (rand() % (upper - lower + 1)) + lower;
	return(numb);
}

int	sm_atoi(char *str)
{
	int	i = 0;
	int	num = 0;
	int	min = 1;
	
	while(sm_while_space(str,i) > 0)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = min * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] -'0');
		i++;
	}
	return (num * min);
}

void sm_inspect_arr(void *p, char type ,int size, int color)
{
	int i = 0;
	int item = 0;

	int *d = (int *)p;
	char *c = (char *)p;
	switch (type)
	{
	//for char
	case 'c':
		do
		{
			if (item == color)
				printf(RED);
			printf("/%3d",item++);
			printf(WHT);
		} while(item < size);

		printf("\n|");
		while(i < size)
		{
			if (i % 2 == 0)
				printf(YEL);
			if (i == color)
				printf(RED);
			if (c[i] == '\0')
				printf("NUL");
			else if (c[i] == '\t')
				printf(" \\t");
			else if (c[i] == '\v')
				printf(" \\v");
			else if (c[i] <= 0)
				printf("-n ");
			else if (c[i] == 127)
				printf("DEL");
			else if (c[i] > 126)
				printf("+n ");
			else if (c[i] == 31)
				printf("US ");
			else if (c[i] == 1)
				printf("SOH");
			else
				printf(" %c " ,c[i]);
			printf(RESET "|");
			i++;
		}
		if (i < size)
			printf("NUL|\n");
		else
			printf("\n");
		break;
		
	case 'i':
		while(item < size)
			printf("/%9d",item++);
		printf("\n|");
		while(i <  size)
		{
			if (i == color)
				printf(RED);
			printf("%9d|" ,d[i++]);
			printf(WHT);
		}
		printf("\n");
		break;

	case 'p':
		printf("%p\n", &p);
		break;
	
	default:
		printf(RED"%c "RESET"not reconise\n", type);
		break;
	}
}


int sm_func_looking(char *str,char *word, int *path)
{
	int i = *path;
	int back = i;
	int j = 0;

	while(str[i] == ' ' || str[i] == '\t')
		i++;

	while(word[j])
	{
		if (word[j] != str[i])
		{
			*path = back;
			return(1);
		}
		j++;	
		i++;
	}
	if (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
	{
		*path = i;
		return(0);
	}
	*path = back;
	return(1);
}

int sm_find_mix_str(char *str,char *word, int *path)
{
	int back = *path;
	char look_for[14];
	int i = back;
	int j = 0;
	while(str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '\0')
	{
		*path = back;
		return(1);
	}
	while(word[j])
	{
		look_for[j] = word[j];
		j++;
	}
	look_for[j] = '\r';
	j++;
	look_for[j] = '\0';
	j = 0;
	while(str[i] != '\0' && str[i] != 32 && str[i] != '\t')
	{
		while(look_for[j])
		{
			if (look_for[j] == '\r')
			{
				*path = back;
				return(1);
			}
			else if(look_for[j] == str[i])
			{
				look_for[j] = '\a';
				j = 0;
				break; 
			}
			j++;
		}
		i++;
	}
	j = 0;
	while(look_for[j])
	{
		if(look_for[j] != '\a' && look_for[j] != '\r')
		{
			*path = back;
			return(1);
		}
	j++;
	}
	*path = i;
	return(0);
}

int sm_copy_str_to(char *input,char *return_v,int start_p, int end_p)
{
	int i = start_p;
	int j = 0;

	if (end_p < 0)
		end_p = 100000;
	if(input[i] == '\0' || input[i] == ' ' || input[i] == '\t' || end_p == 0)
		return(0);
	while(input[i] != '\0' && j < end_p)
	{
		return_v[j] = input[i];
		j++;
		i++;
	}
	return_v[j] = '\0';
	return(j);
}

int sm_look_for_char_p(char *str, int start_p ,int number ,char look)
{
	int i = start_p;
	int count = 0;
	
	while(str[i])
	{
		if (count == number)
			return(i);
		if (str[i] == look)
			count++;
		i++;
	}
	return(0);
}

void *sm_calloc(size_t type, size_t size)
{
	char	*p;
	size_t	i;

	p = malloc(type * size);
	if (!p)
		return (NULL);
	i = type * size;
	while (i--)
		p[i] = 0;
	return (p);
}

int sm_look_for_word(char *str,char *word)
{
	int i = 0;
	while(word[i])
	{
		if (word[i] != str[i])
			return(1);
		i++;
	}
	if (str[i] == '\0' || str[i] == ' ' || str[i] == '\t')
		return(0);
	return(1);
}

void rd_color(void)
{
	int tem = sm_r_num(0,5);
	if (tem == 0)
		write(1, &RED, 6);
	if (tem == 1)
		write(1, &GRN, 6);
	if (tem == 2)
		write(1, &YEL, 6);
	if (tem == 3)
		write(1, &BLU, 6);
	if (tem == 4)
		write(1, &MAG, 6);
	if (tem == 5)
		write(1, &CYN, 6);
}

void noise(int loop, int size)
{
	int i = 0;
	int j = 0;
	int temp;

	while(i < loop)
	{
		while(j < size)
		{
			temp = sm_r_num(0,105) + 21;
			rd_color();
			write(1, &temp, 1);
			write(1, &RESET,5);
			j++;
		}
		write(1, "\n", 2);
		i++;
		j = sm_r_num(0,size);
	}
}

int sm_print_file(char *name)
{
    int f;
    char d[1];
    f = open(name,O_RDWR);
    if (f == -1)
        return (1);
    while(read(f ,d ,1) > 0)
        putchar(d[0]);
    close(f);
	write(1,"\n",1);
    return (0);
}

void    show_color(void)
{
    int i, j, n;

    for (i = 0; i < 11; i++) {
        for (j = 0; j < 10; j++) {
            n = 10 * i + j;
            if (n > 108) break;
            printf("\033[%dm %3d\033[m", n, n);
        }
        printf("\n");
    }
            printf(WHT
        "\nwhite\n"
        RED "red\n"
        GRN "green\n"
        YEL "yellow\n"
        BLU "blue\n"
        MAG "magenta\n"
        CYN "cyan\n"
        WHT
        "\n");
}
