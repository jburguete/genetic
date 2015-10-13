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
 * \file reproduction.c
 * \brief Source file to define the reproduction functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#define _GNU_SOURCE
#include <string.h>
#include <glib.h>
#include <gsl/gsl_rng.h>
//#include "config.h"
#include "bits.h"
#include "entity.h"
#include "reproduction.h"

/**
 * \var reproduction
 * \brief Pointer to the function to apply the reproduction operation.
 */
void (*reproduction) (Entity *, Entity *, Entity *, unsigned int, gsl_rng *);

/**
 * \fn void reproduction_singlepoints(Entity *father, Entity *mother, \
 *   Entity *son, unsigned int nbits, gsl_rng *rng)
 * \brief Function to mate two genotypes by single-point reproduction of each
 *   genome.
 * \param father
 * \brief Father.
 * \param mother
 * \brief Mother.
 * \param son
 * \brief Son.
 * \param nbits
 * \brief Genome nbits.
 * \param rng
 * \brief GSL random numbers generator.
 */
void
reproduction_singlepoints (Entity * father, Entity * mother, Entity * son,
                           unsigned int nbits, gsl_rng * rng)
{
  int i;
  i = gsl_rng_uniform_int (rng, nbits);
  bit_copy (son->genome, mother->genome, 0, 0, i);
  bit_copy (son->genome, father->genome, i, i, nbits - i);
}

/**
 * \fn void reproduction_doublepoints(Entity *father, Entity *mother, \
 *   Entity *son, unsigned int nbits, gsl_rng *rng)
 * \brief Function to mate two genotypes by double-point reproduction of each
 *   genome.
 * \param father
 * \brief Father.
 * \param mother
 * \brief Mother.
 * \param son
 * \brief Son.
 * \param nbits
 * \brief Genome nbits.
 * \param rng
 * \brief GSL random numbers generator.
 */
void
reproduction_doublepoints (Entity * father, Entity * mother, Entity * son,
                           unsigned int nbits, gsl_rng * rng)
{
  unsigned int i, j, k;
  i = gsl_rng_uniform_int (rng, nbits);
  j = gsl_rng_uniform_int (rng, nbits);
  if (i > j)
    k = i, i = j, j = k;
  bit_copy (son->genome, mother->genome, 0, 0, i);
  bit_copy (son->genome, father->genome, i, i, j - i);
  bit_copy (son->genome, mother->genome, j, j, nbits - j);
}

/**
 * \fn void reproduction_mixing(Entity *father, Entity *mother, Entity *son, \
 *   unsigned int nbits, gsl_rng *rng)
 * \brief Function to mate two genotypes by random mixing both genomes.
 * \param father
 * \brief Father.
 * \param mother
 * \brief Mother.
 * \param son
 * \brief Son.
 * \param nbits
 * \brief Genome nbits.
 * \param rng
 * \brief GSL random numbers generator.
 */
void
reproduction_mixing (Entity * father, Entity * mother, Entity * son,
                     unsigned int nbits, gsl_rng * rng)
{
  int i;
  for (i = 0; i < nbits; i++)
    {
      if (gsl_rng_uniform_int (rng, 2))
        {
          bit_get (father->genome, i) ?
            bit_set (son->genome, i) : bit_clear (son->genome, i);
        }
      else
        {
          bit_get (mother->genome, i) ?
            bit_set (son->genome, i) : bit_clear (son->genome, i);
        }
    }
}

/**
 * \fn void reproduction_init(unsigned int type)
 * \brief Function to select the reproduction operations.
 * \param type
 * \brief Type of reproduction operations.
 */
void
reproduction_init (unsigned int type)
{
  switch (type)
    {
    case REPRODUCTION_TYPE_SINGLEPOINTS:
      reproduction = &reproduction_singlepoints;
      break;
    case REPRODUCTION_TYPE_DOUBLEPOINTS:
      reproduction = &reproduction_doublepoints;
      break;
    default:
      reproduction = &reproduction_mixing;
    }
}
