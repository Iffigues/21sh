#include <sys/ioctl.h>
#include "ft_21.h"
int get_size(t_prompt *a)
{
	int i;

	i = ioctl(0, TIOCGWINSZ, a->w) > -1;
	return (i);
}
