# include "tester.h"

	const char ft_list[][50] = {
		"test1\0",
		"test2\0",
		"test3\0",
		"test4\0",
		"\0",
	};

static size_t	return_longer(const char *s1, const char *s2)
{
	size_t	i = 0;

	i = 0;
	if (!s1 || !s2)
		return (1);
	while (s1[i] && s2[i])
		i++;
	return (i + 1);
}

short	read_ft(char *s)
{
	size_t	i = 0;

	while (i < 5)
	{
		if (Ct_strncmp(s, ft_list[i], return_longer(s, ft_list[i])) == 0)
			return (i);
		i++;
	}
	return (1);
}