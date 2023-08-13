#include "tester.h"

int	main(void)
{
	char	*s;

	s = "test";
	while (s)
	{
		s = readline("ls-tester: ");
		read_ft(s);
		Ct_free(s);
	}
	return (0);
}