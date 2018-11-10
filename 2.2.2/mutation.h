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
 * \file mutation.h
 * \brief Header file to define the mutation function.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#ifndef MUTATION__H
#define MUTATION__H 1

/**
 * Function to apply a mutation operation.
 */
static inline void
mutation (Population * population,      ///< Population.
          Entity * mother,      ///< Mother entity.
          Entity * son,         ///< Son entity.
          gsl_rng * rng)        ///< GSL random number generator.
{
  memcpy (son->genome, mother->genome, population->genome_nbytes);
  bit_invert (son->genome, gsl_rng_uniform_int (rng, population->genome_nbits));
}

#endif
