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
 * \file adaptation.h
 * \brief Header file to define the adaptation function.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#ifndef ADAPTATATION__H
#define ADAPTATATION__H 1

/**
 * \fn static inline void adaptation(Population *population, Entity *mother, \
 *   Entity *son, gsl_rng *rng)
 * \brief Function to apply an adaptation operation.
 * \param mother
 * \brief Mother.
 * \param son
 * \brief Son.
 * \param rng
 * \brief GSL random number generator.
 */
static inline void adaptation
  (Population * population, Entity * mother, Entity * son, gsl_rng * rng)
{
  unsigned int i, j;
  memcpy (son->genome, mother->genome, population->genome_nbytes);
  i = (unsigned int) gsl_rng_uniform_int (rng, population->nvariables);
  j = (1. - sqrt (gsl_rng_uniform (rng))) * population->variable[i].nbits;
  bit_invert (son->genome, population->variable[i].location + j);
}

#endif
