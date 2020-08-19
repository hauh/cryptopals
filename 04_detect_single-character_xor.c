#include "cryptopals.h"


int				is_best_string(char *s)
{
	static double	best_score = 0.0;
	double			score = 0.0;
	int				i;

	while (*s)
	{
		i = 0;
		while (g_frequent_letters[i])
		{
			if (g_frequent_letters[i] == *s)
				score += FREQUENCY_SCORE(i);
			++i;
		}
		++s;
	}
	if (score <= best_score)
		return (0);
	best_score = score;
	return (1);
}


unsigned char	*decrypt_lines(const char *filename)
{
	char	buf[100] = {0};
	char	*iter = buf;
	char	*result;
	char	*best_result = NULL;
	char	c;
	int		fd;
	int		rd;

	fd = open(filename, O_RDONLY);
	read(fd, &c, 1);
	do
	{
		if (c != '\n')
			*iter++ = c;
		else
		{
			*iter = 0;
			result = decrypt_single_byte(buf);
			if (is_best_string(result))
			{
				free(best_result);
				best_result = result;
			}
			else
				free(result);
			iter = buf;
		}
	}
	while ((rd = read(fd, &c, 1)));
	return (best_result);
}
