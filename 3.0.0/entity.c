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
 * \file entity.c
 * \brief Source file to define the entity functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#define _GNU_SOURCE
#include <gsl/gsl_rng.h>
#include <glib.h>
#include "entity.h"

/**
 * Function to create an entity.
 */
void
entity_new (Entity * entity,    ///< Entity struct.
            unsigned int genome_nbytes,
            ///< Number of bytes of the entity genome. 
            unsigned int id)    ///< Identifier number.
{
  entity->id = id;
  // Aligning in 4 bytes
  entity->nbytes = ((genome_nbytes + 3) / 4) * 4;
  entity->genome = (char *) g_slice_alloc (entity->nbytes);
}

/**
 * Function to init randomly the genome of an entity.
 */
void
entity_init (Entity * entity,   ///< Entity struct.
             gsl_rng * rng)     ///< GSL random numbers generator.
{
  unsigned int i;
  for (i = 0; i < entity->nbytes; ++i)
    entity->genome[i] = (char) gsl_rng_uniform_int (rng, 256);
}

/**
 * Function to free the memory used by an entity.
 */
void
entity_free (Entity * entity)   ///< Entity struct.
{
  g_slice_free1 (entity->nbytes, entity->genome);
}
