#include "tester.h"

int	main(void)
{
	char	*s;

	s = "test";
	while (s)
	{
		s = readline("ls-tester: ");
		if (s)
			free(s);
	}
	return (0);
}