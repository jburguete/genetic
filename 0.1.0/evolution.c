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
 * \file evolution.c
 * \brief Source file to define evolution functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <gsl/gsl_rng.h>
//#include "config.h"
#include "bits.h"
#include "sort.h"
#include "entity.h"
#include "population.h"
#include "mutation.h"
#include "reproduction.h"
#include "selection.h"
#include "evolution.h"

/**
 * \def DEBUG_EVOLUTION
 * \brief Macro to debug the evolution functions.
 */
#define DEBUG_EVOLUTION 0

/**
 * \fn void evolution_sort(Population *population)
 * \brief Function to sort the index of the evaluated population
 * \param population
 * \brief Population
 */
void evolution_sort(Population *population)
{
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_sort: start\n");
#endif
	index_new(population->objective, population->index, population->nentities);
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_sort: end\n");
#endif
}

/**
 * \fn void evolution_mutation(Population *population, gsl_rng *rng)
 * \brief Funtion to apply the mutation evolution.
 * \param population
 * \brief Population
 * \param rng
 * \brief GSL random numbers generator.
 */
void evolution_mutation(Population *population, gsl_rng *rng)
{
	unsigned int i;
	Entity *mother, *son;
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_mutation: start\n");
#endif
	for (i = population->mutation_max; i > population->mutation_min;)
	{
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_mutation: selection\n");
#endif
		selection_mutation(population, &mother, rng);
		son = population->entity + population->index[--i];
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_mutation: mutation in %u-%u\n",
i, population->index[i]);
#endif
		mutation(population, mother, son, rng);
	}
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_mutation: end\n");
#endif
}

/**
 * \fn void evolution_reproduction(Population *population, gsl_rng *rng)
 * \brief Funtion to apply the reproduction evolution.
 * \param population
 * \brief Population
 * \param rng
 * \brief GSL random numbers generator.
 */
void evolution_reproduction(Population *population, gsl_rng *rng)
{
	unsigned int i;
	Entity	*mother, *father, *son;
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_reproduction: start\n");
#endif
	for (i = population->reproduction_max; i > population->reproduction_min;)
	{
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_reproduction: selection\n");
#endif
		selection_reproduction(population, &mother, &father, rng);
		son = population->entity + population->index[--i];
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_reproduction: reproduction in %u-%u\n",
i, population->index[i]);
#endif
		reproduction(mother, father, son, population->genome_nbits, rng);
	}
#if DEBUG_EVOLUTION
fprintf(stderr, "evolution_reproduction: end\n");
#endif
}
