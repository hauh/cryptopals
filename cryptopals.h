#ifndef CRYPTOPALS_H
# define CRYPTOPALS_H

# include <stdio.h>
# include <fcntl.h>
# include <assert.h>

# define HEX_TO_BIN(hex)		((hex & 0xf) + (hex > '9' ? 9 : 0))
# define FREQUENCY_SCORE(index)	(1.0 - 0.05 * index)

extern const char	g_frequent_letters[];

unsigned char	*hex_to_base64(const char *hex);
unsigned char	*xoring(const char *hex0, const char *hex1);
unsigned char	*decrypt_single_byte(const char *hex);
unsigned char	*decrypt_lines(const char *filename);

#endif
