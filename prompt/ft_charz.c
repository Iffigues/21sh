#include <unistd.h>

int		ft_charz(int a)
{
	return (write(0, &a, 1));
}
