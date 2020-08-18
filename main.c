#include "cryptopals.h"

const char challenge_01[] = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
const char answer_01[] = "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t";

const char challenge_02_1[] = "1c0111001f010100061a024b53535009181c";
const char challenge_02_2[] = "686974207468652062756c6c277320657965";
const char answer_02[] = "746865206b696420646f6e277420706c6179";

const char challenge_03[] = "1b37373331363f78151b7f2b783431333d78397828372d363c78373e783a393b3736";
const char answer_03[] = "Cooking MC's like a pound of bacon";


int main(void)
{
	unsigned char *answer;

	answer = hex_to_base64(challenge_01);
	assert(!strcmp(answer, answer_01));
	printf("01: %s\n", answer);

	answer = xoring(challenge_02_1, challenge_02_2);
	assert(!strcmp(answer, answer_02));
	printf("02: %s\n", answer);

	answer = decrypt_single_byte(challenge_03);
	assert(!strcmp(answer, answer_03));
	printf("03: %s\n", answer);
}
