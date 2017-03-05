#include "libft.h"
#include <stdio.h>


int main(void)
{
	int a = 2554332;

	printf("%d\n", a);
	printf("%#x\n", a);
	char *str ="0x26f9dc\n";
	int b = ft_atohex_shift_pointer(&str);
	printf("%d\n", b);

	return 0;
}