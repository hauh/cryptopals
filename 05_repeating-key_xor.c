#include "cryptopals.h"


unsigned char	*encrypt_repeating_xoring(const char *string, const char *key)
{
	unsigned char	*result;
	unsigned char	*iter;
	const char		*key_byte = key;
	unsigned char	xor;

	result = (unsigned char *)malloc(sizeof(char) * (strlen(string) * 2 + 1));
	iter = result;
	while (*string)
	{
		xor = *string++ ^ *key_byte++;
		*iter++ = BIN_TO_HEX(xor >> 4);
		*iter++ = BIN_TO_HEX(xor & 0xf);
		if (!*key_byte)
			key_byte = key;
	}
	*iter = 0;
	return (result);
}
