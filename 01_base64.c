#include <stdio.h>
#include "header.h"

const char base64[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";


char	*hex_to_base64(unsigned char *hex)
{
	unsigned char	*encoded;
	unsigned char	*result;
	unsigned char	bits[3];
	unsigned int	i = 0;

	encoded = (unsigned char *)malloc(sizeof(char) * (strlen(hex) * 8 / 3 + 4));
	result = encoded;

	while (*hex)
	{
		bits[i] = HEX_TO_BIN(*hex);
		if (++i == 3)  // 3 hex chars (12 bits) == 2 base64 chars
		{
			*encoded++ = base64[bits[0] << 2 | (bits[1] & 0xc) >> 2];
			*encoded++ = base64[(bits[1] & 0x3) << 4 | bits[2]];
			i = 0;
		}
		++hex;
	}
	if (i)  // encoding leftover hex chars
	{
		if (i > 1)
		{
			*encoded++ = base64[bits[0] << 2 | (bits[1] & 0xc) >> 2];
			*encoded++ = base64[(bits[1] & 0x3) << 4];
		}
		else
			*encoded++ = base64[bits[0] << 2];
	}
	while ((encoded - result) % 4)  // padding
		*encoded++ = '=';
	*encoded = 0;

	return (result);
}


int		main(int argc, unsigned char **argv)
{
	for (int i = 1; i < argc; ++i)
		printf("%s", hex_to_base64(argv[i]));
}
