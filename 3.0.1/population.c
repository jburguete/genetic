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
 * \file population.c
 * \brief Header file to define the population functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <gsl/gsl_rng.h>
#include <glib.h>
#include "bits.h"
#include "entity.h"
#include "population.h"

/**
 * Function to init a population.
 *
 * \return 1 on succes, 0 on error.
 */
int
population_new (Population * population,        ///< Population.
                GeneticVariable * variable,     ///< Variables data.
                unsigned int nvariables,        ///< Number of variables.
                unsigned int genome_nbits,
                ///< Number of bits of each entity genome.
                unsigned int nentities, ///< Number of entities.
                double mutation_ratio,  ///< Mutation ratio.
                double reproduction_ratio,      ///< Reproduction ratio.
                double adaptation_ratio,        ///< Adaptation ratio.
                double threshold)
                ///< Threshold to finish the simulations.
{
  unsigned int i, nmutations, nreproductions, nadaptations;
  nmutations = mutation_ratio * nentities;
  nreproductions = reproduction_ratio * nentities;
  nadaptations = adaptation_ratio * nentities;
  i = nmutations + nreproductions + nadaptations;
  if (!i)
    {
      fprintf (stderr, "ERROR: no evolution\n");
      return 0;
    }
  if (i >= nentities)
    {
      fprintf (stderr, "ERROR: no survival of entities\n");
      return 0;
    }
  population->nsurvival = nentities - i;
  if (population->nsurvival < 2)
    {
      fprintf (stderr, "ERROR: unable to reproduce the entities\n");
      return 0;
    }
  population->variable = variable;
  population->nvariables = nvariables;
  population->nentities = nentities;
  population->mutation_max = nentities;
  population->mutation_min = population->reproduction_max
    = nentities - nmutations;
  population->reproduction_min = population->adaptation_max
    = population->reproduction_max - nreproductions;
  population->adaptation_min = population->nsurvival;
  population->genome_nbits = genome_nbits;
  population->genome_nbytes = bit_sizeof (genome_nbits);
  population->objective
		= (double *) g_slice_alloc (nentities * sizeof (double));
  population->entity = (Entity *) g_slice_alloc (nentities * sizeof (Entity));
  for (i = 0; i < population->nentities; ++i)
    {
      entity_new (population->entity + i, population->genome_nbytes, i);
      population->objective[i] = G_MAXDOUBLE;
    }
  population->threshold = threshold;
  population->stop = 0;
  return 1;
}

/**
 * Function to free the memory allocated in a population.
 */
void
population_init_genomes (Population * population,       ///< Population.
                         gsl_rng * rng) ///< GSL random numbers generator.
{
  unsigned int i;
  for (i = 0; i < population->nentities; ++i)
    entity_init (population->entity + i, rng);
}

/**
 * Function to free the memory allocated in a population.
 */
void
population_free (Population * population)       ///< Population.
{
  unsigned int i, nentities;
	nentities = population->nentities;
  for (i = 0; i < nentities; ++i)
    entity_free (population->entity + i);
  g_slice_free1 (nentities * sizeof (Entity), population->entity);
  g_slice_free1 (nentities * sizeof (double), population->objective);
}
