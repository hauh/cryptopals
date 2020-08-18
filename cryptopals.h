#ifndef CRYPTOPALS_H
# define CRYPTOPALS_H

# include <stdio.h>
# include <assert.h>

# define HEX_TO_BIN(hex)	((hex & 0xf) + (hex > '9' ? 9 : 0))

unsigned char	*hex_to_base64(const char *hex);
unsigned char	*xoring(const char *hex0, const char *hex1);
unsigned char	*decrypt_single_byte(const char *hex);

#endif
