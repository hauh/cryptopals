#include "cryptopals.h"

const char g_frequent_letters[] = "etaoinshrdlu";


unsigned char	*decrypt_single_byte(const char *hex)
{
	unsigned char	*iter;
	unsigned char	*result;
	double			frequency_score;
	double			best_score = 0.0;
	int				key = 0;
	int				i;
	unsigned char	decrypted;

	for (int check = 0; check <= 0xff; ++check)
	{
		frequency_score = 0.0;
		iter = (unsigned char *)hex;
		while (*iter)
		{
			decrypted = (HEX_TO_BIN(*iter) << 4 | HEX_TO_BIN(*(iter + 1))) ^ check;
			i = 0;
			while (g_frequent_letters[i])
			{
				if (g_frequent_letters[i] == decrypted)
					frequency_score += FREQUENCY_SCORE(i);
				++i;
			}
			iter += 2;
		}
		if (frequency_score > best_score)
		{
			best_score = frequency_score;
			key = check;
		}
	}

	result = (unsigned char *)malloc(sizeof(char) * (strlen(hex) / 2 + 1));
	iter = result;
	while (*hex)
	{
		*iter++ = (HEX_TO_BIN(*hex) << 4 | HEX_TO_BIN(*(hex + 1))) ^ key;
		hex += 2;
	}
	*iter = 0;
	return (result);
}
