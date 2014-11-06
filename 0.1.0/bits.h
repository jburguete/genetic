/*
GENETIC - A simple genetic algorithm.

Copyright 2014, Javier Burguete Tolosa.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
 
1. Redistributions of source code must retain the above copyright notice, this
	list of conditions and the following disclaimer.
 
2. Redistributions in binary form must reproduce the above copyright notice,
	this list of conditions and the following disclaimer in the documentation
	and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY Javier Burguete Tolosa ``AS IS'' AND ANY EXPRESS
OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
EVENT SHALL Javier Burguete Tolosa OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF 
ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

/**
 * \file bits.h
 * \brief Header file to define bits functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#ifndef BITS__H
#define BITS__H 1

/**
 * \fn static inline void bit_set(char *bit, unsigned int n)
 * \brief Function to set up a single bit in a string.
 * \param bit
 * \brief String.
 * \param n
 * \brief Bit index.
 */
static inline void bit_set(char *bit, unsigned int n)
{
	bit[n / 8] |= 1 << (n % 8);
}

/**
 * \fn static inline void bit_clear(char *bit, unsigned int n)
 * \brief Function to set down a single bit in a string.
 * \param bit
 * \brief String.
 * \param n
 * \brief Bit index.
 */
static inline void bit_clear(char *bit, unsigned int n)
{
	bit[n / 8] &= ~(1 << (n % 8));
}

/**
 * \fn static inline void bit_invert(char *bit, unsigned int n)
 * \brief Function to invert a single bit in a string.
 * \param bit
 * \brief String.
 * \param n
 * \brief Bit index.
 */
static inline void bit_invert(char *bit, unsigned int n)
{
 	bit[n / 8] ^= 1 << (n % 8);
}

/**
 * \fn static inline int bit_get(char *bit, unsigned int n)
 * \brief Function to get the state of a single bit in a string.
 * \param bit
 * \brief String.
 * \param n
 * \brief Bit index.
 * \return The bit's state.
 */
static inline int bit_get(char *bit, unsigned int n)
{
	return bit[n / 8] & (1 << (n % 8));
}

/**
 * \fn static inline void bit_randomize(char *bit, unsigned int n)
 * \brief Function to set randomly the state of a single bit in a string.
 * \param bit
 * \brief String.
 * \param n
 * \brief Bit index.
 */
static inline void bit_randomize(char *bit, unsigned int n, gsl_rng *rng)
{
	gsl_rng_uniform_int(rng, 2)? bit_set(bit, n): bit_clear(bit, n);
}

/**
 * \fn static inline void bit_copy(char *dest, char *src, unsigned int ndest, \
 *   unsigned int nsrc, unsigned int length)
 * \brief Function to copy a set of bits in a string. If dest and src are the
 *   same overlapping sequences of bits are safely handled.
 * \param dest
 * \brief Destination string.
 * \param src
 * \brief Source string
 * \param ndest
 * \brief Initial bit index of destination bits.
 * \param nsrc
 * \brief Initial bit index of source bits.
 * \param length
 * \brief Number of bits to copy.
 */
static inline void bit_copy(char *dest, char *src, unsigned int ndest,
	unsigned int nsrc, unsigned int length)
{
	unsigned int i;

	if (dest != src || ndest < nsrc)
		for (i = 0; i < length; ++i)
			bit_get(src, nsrc + i)?
				bit_set(dest, ndest + i):
				bit_clear(dest, ndest + i);
	else
		for (i = length; i-- > 0;)
			bit_get(src, nsrc + i)?
				bit_set(dest, ndest + i):
				bit_clear(dest, ndest + i);
}

/**
 * \fn static inline unsigned int bit_sizeof(unsigned int length)
 * \brief Function to get the size required for the given number of bits,
 *   rounded up if needed.
 * \param length
 * \brief Number of bits.
 */
static inline unsigned int bit_sizeof(unsigned int length)
{
	return (unsigned int)((length + 7) / 8);
}

/**
 * \fn static inline unsigned int bit_get_value(char *bit, \
 *   unsigned int location, unsigned int nbits)
 * \brief Function to get the value of an encoded integer.
 * \param bit
 * \brief String.
 * \param location
 * \brief Location of the encoded integer in the string.
 * \param nbits
 * \brief Number of bits of the encoded integer.
 * \return Encoded integer.
 */
static inline unsigned int bit_get_value
(char *bit, unsigned int location, unsigned int nbits)
{
	unsigned int i, j, k;
	for (i = k = 0, j = 1; i < nbits; ++i, j <<= 1)
		if (bit_get(bit, location + i)) k += j;
	return k;
}

#endif
