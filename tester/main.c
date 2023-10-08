#include "tester.h"

static char	*get_env(char **en, char *seed)
{
	size_t	i = 0;
	size_t	len = Ct_strlen(seed);

	while (en && en[i])
	{
		if (Ct_strncmp(en[i], seed, len) == 0)
		{
			if (en[i][len] == '=')
				return (en[i] + len + 1);
		}
		i++;
	}
	return (NULL);
}

int	main(int ac, char **av, char **en)
{
	t_ls_data	data;
	//int			index;

	Ct_bzero(&data, sizeof(t_ls_data));
	data.user = get_env(en, "USER");
	(void)ac;
	(void)av;
	data.read_out = "test";
	while (data.read_out)
	{
		Ct_printf(-1, "%o%S%s|ls-tester: ", &data.promp, Ct_make_color(50, 150, 255) ,data.user);
		data.read_out = readline(data.promp);
		Ct_free(data.promp);
		read_ft(data.read_out);
		Ct_free(data.read_out);
	}
	return (0);
}
