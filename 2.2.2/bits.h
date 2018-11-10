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
 * Function to set up a single bit in a string.
 */
static inline void
bit_set (char *bit,             ///< String.
         unsigned int n)        ///< Bit index.
{
  bit[n / 8] |= 1 << (n % 8);
}

/**
 * Function to set down a single bit in a string.
 */
static inline void
bit_clear (char *bit,           ///< String.
           unsigned int n)      ///< Bit index.
{
  bit[n / 8] &= ~(1 << (n % 8));
}

/**
 * Function to invert a single bit in a string.
 */
static inline void
bit_invert (char *bit,          ///< String.
            unsigned int n)     ///< Bit index.
{
  bit[n / 8] ^= 1 << (n % 8);
}

/**
 * Function to get the state of a single bit in a string.
 *
 * \return The bit's state.
 */
static inline int
bit_get (char *bit,             ///< String.
         unsigned int n)        ///< Bit index.
{
  return bit[n / 8] & (1 << (n % 8));
}

/**
 * Function to set randomly the state of a single bit in a string.
 */
static inline void
bit_randomize (char *bit,       ///< String.
               unsigned int n,  ///< Bit index.
               gsl_rng * rng)   ///< GSL pseudo-random numbers generator.
{
  gsl_rng_uniform_int (rng, 2) ? bit_set (bit, n) : bit_clear (bit, n);
}

/**
 * Function to copy a set of bits in a string. If dest and src are the same
 *   overlapping sequences of bits are safely handled.
 */
static inline void
bit_copy (char *dest,           ///< Destination string.
          char *src,            ///< Source string
          unsigned int ndest,   ///< Initial bit index of destination bits.
          unsigned int nsrc,    ///< Initial bit index of source bits.
          unsigned int length)  ///< Number of bits to copy.
{
  unsigned int i;

  if (dest != src || ndest < nsrc)
    for (i = 0; i < length; ++i)
      bit_get (src, nsrc + i) ?
        bit_set (dest, ndest + i) : bit_clear (dest, ndest + i);
  else
    for (i = length; i-- > 0;)
      bit_get (src, nsrc + i) ?
        bit_set (dest, ndest + i) : bit_clear (dest, ndest + i);
}

/**
 * Function to get the size required for the given number of bits, rounded up if
 *   needed.
 */
static inline unsigned int
bit_sizeof (unsigned int length)        ///< Number of bits.
{
  return (unsigned int) ((length + 7) / 8);
}

/**
 * Function to get the value of an encoded integer.
 *
 * \return Encoded integer.
 */
static inline unsigned int
bit_get_value (char *bit,       ///< String.
               unsigned int location,
               ///< Location of the encoded integer in the string.
               unsigned int nbits)
               ///< Number of bits of the encoded integer.
{
  unsigned int i, j, k;
  for (i = k = 0, j = 1; i < nbits; ++i, j <<= 1)
    if (bit_get (bit, location + i))
      k += j;
  return k;
}

#endif
