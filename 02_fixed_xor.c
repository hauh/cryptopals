#include <stdio.h>
#include "header.h"


unsigned char	*xoring(unsigned char *hex0, unsigned char *hex1)
{
	unsigned char *result;
	unsigned char *iter;
	unsigned char xor;

	result = (unsigned char *)malloc(sizeof(char) * (strlen(hex0) + 1));
	iter = result;

	while (*hex0)
	{
		xor = HEX_TO_BIN(*hex0) ^ HEX_TO_BIN(*hex1);
		*iter++ = xor + (xor < 10 ? '0' : 'a' - 10);
		++hex0;
		++hex1;
	}
	*iter = 0;
	return (result);
}


int main(int argc, unsigned char **argv)
{
	if (argc > 2)
		printf("%s", xoring(argv[1], argv[2]));
}
