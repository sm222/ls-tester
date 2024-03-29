#include "main.h"

/*
skip space and tab
*/
int sm_while_space_tab(int start,char *str)
{
	int i = start;
	while (str[i] == '\t' || str[i] == ' ')
		i++;
	return(i);
}

/*
if p not NULL free p
return NULL
*/
void	*xfree(void *p)
{
	if (p)
		free(p);
	return (NULL);
}

/*
if space return 1
else -1
*/
int	sm_while_space(char *str, int i)
{
	if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		return(1);
	return(-1);
}

/*
get keybord input and put it in *return_txt
size the amount of char
*/
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

/*
rm all space and tab
put a '\0' at the end
*/
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

/*
give a rendom number betwens lower and upper
*/
int	sm_r_num(int lower ,int upper)
{
	int	swap;

	if (lower > upper)
	{
		swap = lower;
		lower = upper;
		upper = swap;
	}
	int	numb = (rand() % (upper - lower + 1)) + lower;
	return(numb);
}

/*
*str to int
*/
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

/*

*/
void	sm_inspect_arr(void *p, char type ,int size, int color)
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
		printf(RED"%c "RESET"type not found\n", type);
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

int	sm_copy_str_to(char *input,char *return_v,int start_p, int end_p)
{
	int i = start_p;
	int j = 0;

	if (end_p < 0)
		end_p = 100000;
	//if(input[i] == '\0' || input[i] == ' ' || input[i] == '\t' || end_p == 0)
	//	return(0);
	while(input[i] != '\0' && input[i] != ' ' && input[i] != '\t' && j < end_p)
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

void *sm_calloc(size_t size, size_t count)
{
	char	*new;

	new = malloc(size * count);
	if (!new)
		return (NULL);
	sm_bzero(new, size * count);
	return (new);
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

void	*sm_bzero(void *p, size_t size)
{
	while (size--)
		((char *)p)[size] = 0;
	return (p);
}

void	*sm_memcpy(void	*old, void *new, size_t size)
{
	while(size--)
		((char *)new)[size] = ((char *)old)[size];
	return (new);
}

void	*sm_realloc(void *p, size_t size, size_t count)
{
	char	*new;

	new = sm_calloc(size + 1, count);
	if (!new)
		return (NULL);
	sm_memcpy(p, new, size * count);
	free(p);
	return (new);
}

//-----------------------------------------------------------------------------
static int	ft_num_s(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	else if (n < 0)
	{	
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	ft_set_str(char *s, int i, int long n)
{
	if (i > 0)
	{
		s[i] = n % 10 + '0';
		ft_set_str(s, i - 1, n / 10);
	}
	else
		s[i] = n % 10 + '0';
}

char	*ft_itoa(int n)
{
	char		*r;
	long int	temp;

	temp = n;
	r = calloc(ft_num_s(n) + 1, sizeof(char));
	if (!r)
		return (NULL);
	else if (temp < 0)
		temp = temp * -1;
	ft_set_str(r, ft_num_s(n) - 1, temp);
	if (n < 0)
		r[0] = '-';
	return (r);
}

char	*sm_str_dup(char	*s)
{
	size_t	i;
	char	*new;

	i = 0;
	while(s && s[i])
		i++;
	new = calloc(i, sizeof(char));
	while (i--)
		new[i] = s[i];
	return (new);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

char	*ft_str_fback_join(char *sfree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = ft_strlen(sfree);
	s2_i = ft_strlen(s2);
	new = calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = xfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = sfree[s1_i];
	return (xfree(sfree), new);
}

char	*ft_str_ffront_join(char *s1, char *sfree)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = strlen(s1);
	s2_i = strlen(sfree);
	new = calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = xfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = sfree[s2_i];
	while (s1_i--)
		new[s1_i] = s1[s1_i];
	return (xfree(sfree), new);
}

char	*f_strjoin(char *s1, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = strlen(s1);
	s2_i = strlen(s2);
	new = calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = xfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = s1[s1_i];
	return (new);
}

char	*ft_str_ff_join(char *s1f, char *s2f)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = ft_strlen(s1f);
	s2_i = ft_strlen(s2f);
	new = calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = xfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2f[s2_i];
	while (s1_i--)
		new[s1_i] = s1f[s1_i];
	return (s1f = xfree(s1f),s2f = xfree(s2f), new);
}

char	*ft_join_select(va_list list, char c)
{
	if (c == 'i' || c == 'd')
		return (ft_itoa(va_arg(list, int)));
	else if (c == 's')
		return (sm_str_dup(va_arg(list, char *)));
	else if (c == '%')
		return (sm_str_dup("%"));
	return (NULL);
}

char	*str_join_char(char *s, char c)
{
	size_t	size;
	char	*new;

	size = strlen(s) + 1;
	new = calloc(size + 1, sizeof(char));
	new = strcpy(new, s);
	new[size - 1] = c;
	free(s);
	return (new);
}

char	*combine(char *s, ...)
{
	va_list	list;
	size_t	i;
	char	*new;

	va_start(list, s);
	new = calloc(1, sizeof(char));
	i = 0;
	while (s[i])
	{
		if(s[i] != '%')
			new = str_join_char(new, s[i++]);
		else
		{
			new = ft_str_ff_join(new, ft_join_select(list, s[++i]));
			i++;
		}
	}
	va_end(list);
	return(new);
}

void	sm_make_file_name(char *name)
{
	char	*cmd;

	cmd = NULL;
	cmd = combine("touch %s", name);
	if (!cmd)
		return ;
	if (system(cmd))
		printf(RED"can't make file"WHT);
	free(cmd);
}

void	sm_log(int fd, char *from, char *log)
{
	char	*cmd;
	time_t rawtime;
	struct tm * timeinfo;
	char	*time_s;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	time_s = asctime(timeinfo);
	while(*time_s <= '0' || *time_s >= '9')
		time_s++;
	while(*time_s != '\n')
		write(fd, time_s++, 1);
	cmd = NULL;
	cmd = combine("[%s]: %s\n", from, log);
	if (!cmd)
		return ;
	write(fd, cmd, strlen(cmd));
	free(cmd);
}

static void	ft_allfree(char **p)
{
	int	i;

	i = 0;
	while (p[i])
		free(p[i++]);
	free(p);
}

static int	nb_word(const char *str, char c)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

static char	*ft_strdup_c(const char *str, char c)
{
	size_t	i;
	char	*new;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	new = ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (i--)
		new[i] = str[i];
	return (new);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	if (!s)
		return (NULL);
	new = (char **)ft_calloc(nb_word(s, c) + 1, sizeof(char *));
	if (!new)
		return (NULL);
	while (nb_word(s + i, c))
	{
		while (s[i] && s[i] == c)
			i++;
		new[index] = ft_strdup_c(s + i, c);
		if (!new[index++])
			return (ft_allfree(new), NULL);
		while (s[i] && s[i] != c)
			i++;
	}
	return (new);
}

void	*ft_calloc(size_t coun, size_t size)
{
	char	*new;

	new = malloc(coun * size);
	if (!new)
		return (NULL);
	ft_bzero(new, coun * size);
	return (new);
}

void	ft_bzero(void *s, size_t n)
{
	if (!s)
		return ;
	while (n--)
		((char *)s)[n] = 0;
}

//
char	*ft_tiny_split(char *s, size_t *cut)
{
	char	*new;
	size_t	i;

	i = 0;
	while (s[i])
		if (s[i++] == '\n')
			break ;
	new = ft_calloc(i + 1, sizeof(char));
	if (!new)
		return (new = ft_sfree(new));
	*cut = i;
	while (i--)
		new[i] = s[i];
	return (new);
}

char	ft_find(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ('\n');
		i++;
	}
	return ('0');
}

char	*sm_get_next_line(int fd)
{
	static char	*book;
	t_info		t_val;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 100000)
		return (book = ft_sfree(book));
	if (!book)
		book = ft_calloc(1, sizeof(char));
	t_val.rv = 1;
	t_val.tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (ft_find(book) == '0')
	{
		ft_bzero(t_val.tmp, BUFFER_SIZE + 1);
		t_val.rv = read(fd, t_val.tmp, BUFFER_SIZE);
		if (t_val.rv <= 0)
			break ;
		book = sm_ft_strjoin(book, t_val.tmp);
	}
	t_val.tmp = ft_sfree(t_val.tmp);
	if (t_val.rv == -1 || (t_val.rv <= 0 && *book == 0))
		return (book = ft_sfree(book), NULL);
	t_val.tmp = ft_tiny_split(book, &t_val.cut);
	t_val.tmp2 = book;
	book = sm_ft_strjoin(NULL, book + t_val.cut);
	return (ft_sfree(t_val.tmp2), t_val.tmp);
}

char	*sm_ft_strjoin(char *sfree, char *s2)
{
	size_t	s1_i;
	size_t	s2_i;
	char	*new;

	s1_i = ft_strlen(sfree);
	s2_i = ft_strlen(s2);
	new = ft_calloc(s1_i + s2_i + 1, sizeof(char));
	if (!new)
		return (new = ft_sfree(new));
	while (s1_i + s2_i-- > s1_i)
		new[s1_i + s2_i] = s2[s2_i];
	while (s1_i--)
		new[s1_i] = sfree[s1_i];
	if (*new == 0)
		new = ft_sfree(new);
	return (ft_sfree(sfree), new);
}

/*
int	*size_arry(char **list)
{
	int	x;
	int	y;
	int	*size;

	size = sm_calloc(1, sizeof(int));
	y = 0;
	while (list[y])
	{
		x = 0;
		while (list[y][x])
			x++;
		y++;

	}
}
*/