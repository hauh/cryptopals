#include "cryptopals.h"


unsigned char	*xoring(const char *hex0, const char *hex1)
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
