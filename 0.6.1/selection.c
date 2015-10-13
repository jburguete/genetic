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
 * \file selection.c
 * \brief Source file to define parents selection functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#define _GNU_SOURCE
#include <math.h>
#include <gsl/gsl_rng.h>
//#include "config.h"
#include "entity.h"
#include "population.h"
#include "selection.h"

/**
 * \var selection_mutation
 * \brief Pointer to the function to apply mutation selection operations.
 * \var selection_reproduction
 * \brief Pointer to the function to apply reproduction selection operations.
 * \var selection_adaptation
 * \brief Pointer to the function to apply adaptation selection operations.
 */
void (*selection_mutation) (Population *, Entity **, gsl_rng *);
void (*selection_reproduction) (Population *, Entity **, Entity **, gsl_rng *);
void (*selection_adaptation) (Population *, Entity **, gsl_rng *);

/**
 * \fn void selection_mutation_random(Population *population, Entity **mother, \
 *   gsl_rng *rng)
 * \brief Function to select a single random entity.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_mutation_random
  (Population * population, Entity ** mother, gsl_rng * rng)
{
  *mother = population->entity
    + gsl_rng_uniform_int (rng, population->nsurvival);
}

/**
 * \fn void selection_mutation_bestof2(Population *population, \
 *   Entity **mother, gsl_rng *rng)
 * \brief Function to select the best of two random entities.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_mutation_bestof2
  (Population * population, Entity ** mother, gsl_rng * rng)
{
  unsigned int i, j;
  i = gsl_rng_uniform_int (rng, population->nsurvival);
  j = gsl_rng_uniform_int (rng, population->nsurvival);
  if (j < i)
    i = j;
  *mother = population->entity + i;
}

/**
 * \fn void selection_mutation_bestof3(Population *population, \
 *   Entity **mother, gsl_rng *rng)
 * \brief Function to select the best of three random entities.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_mutation_bestof3
  (Population * population, Entity ** mother, gsl_rng * rng)
{
  unsigned int i, j;
  i = gsl_rng_uniform_int (rng, population->nsurvival);
  j = gsl_rng_uniform_int (rng, population->nsurvival);
  if (j < i)
    i = j;
  j = gsl_rng_uniform_int (rng, population->nsurvival);
  if (j < i)
    i = j;
  *mother = population->entity + i;
}

/**
 * \fn void selection_mutation_best(Population *population, Entity **mother, \
 *   gsl_rng *rng)
 * \brief Function to select the best entity only.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_mutation_best
  (Population * population, Entity ** mother, gsl_rng * rng)
{
  *mother = population->entity;
}

/**
 * \fn void selection_mutation_linearrank(Population *population, \
 *   Entity **mother, gsl_rng *rng)
 * \brief Function to select an entity based on linear probability distribution
 *   with respect to rank.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_mutation_linearrank
  (Population * population, Entity ** mother, gsl_rng * rng)
{
  unsigned int i;
  i = (1.0 - sqrt (gsl_rng_uniform (rng))) * population->nsurvival;
  *mother = population->entity + i;
}

/**
 * \fn void selection_reproduction_random(Population *population, \
 *   Entity **mother, Entity **father, gsl_rng *rng)
 * \brief Function to select a pair of random entities.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param father
 * \brief Pointer to the father entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_reproduction_random
  (Population * population, Entity ** mother, Entity ** father, gsl_rng * rng)
{
  *mother = population->entity
    + gsl_rng_uniform_int (rng, population->nsurvival);
  do
    *father = population->entity
      + gsl_rng_uniform_int (rng, population->nsurvival);
  while (father == mother);
}

/**
 * \fn void selection_reproduction_bestof2(Population *population, \
 *   Entity **mother, Entity **father, gsl_rng *rng)
 * \brief Function to select a pair of entities. For each parent select the best
 *   of two random entities.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param father
 * \brief Pointer to the father entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_reproduction_bestof2
  (Population * population, Entity ** mother, Entity ** father, gsl_rng * rng)
{
  unsigned int i, j, k;
  i = gsl_rng_uniform_int (rng, population->nsurvival);
  j = gsl_rng_uniform_int (rng, population->nsurvival);
  if (i < j)
    i = j;
  do
    j = gsl_rng_uniform_int (rng, population->nsurvival);
  while (i == j);
  k = gsl_rng_uniform_int (rng, population->nsurvival);
  if (i != k && k < j)
    j = k;
  *mother = population->entity + i;
  *father = population->entity + j;
}

/**
 * \fn void selection_reproduction_bestof3(Population *population, \
 *   Entity **mother, Entity **father, gsl_rng *rng)
 * \brief Function to select a pair of entities. For each parent select the best
 *   of three random entities.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param father
 * \brief Pointer to the father entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_reproduction_bestof3
  (Population * population, Entity ** mother, Entity ** father, gsl_rng * rng)
{
  unsigned int i, j, k;
  i = gsl_rng_uniform_int (rng, population->nsurvival);
  j = gsl_rng_uniform_int (rng, population->nsurvival);
  if (i < j)
    i = j;
  j = gsl_rng_uniform_int (rng, population->nsurvival);
  if (i < j)
    i = j;
  do
    j = gsl_rng_uniform_int (rng, population->nsurvival);
  while (i == j);
  k = gsl_rng_uniform_int (rng, population->nsurvival);
  if (i != k && k < j)
    j = k;
  k = gsl_rng_uniform_int (rng, population->nsurvival);
  if (i != k && k < j)
    j = k;
  *mother = population->entity + i;
  *father = population->entity + j;
}

/**
 * \fn void selection_reproduction_best(Population *population, \
 *   Entity **mother, Entity **father, gsl_rng *rng)
 * \brief Function to select a pair of entities using the best and a random
 *   entity.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param father
 * \brief Pointer to the father entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_reproduction_best
  (Population * population, Entity ** mother, Entity ** father, gsl_rng * rng)
{
  *mother = population->entity
    + gsl_rng_uniform_int (rng, population->nsurvival);
  *father = population->entity;
}

/**
 * \fn void selection_reproduction_linearrank(Population *population, \
 *   Entity **mother, Entity **father, gsl_rng *rng)
 * \brief Function to select a pair of entities based on linear probability
 *   distribution with respect to rank.
 * \param population
 * \brief Population.
 * \param mother
 * \brief Pointer to the mother entity.
 * \param father
 * \brief Pointer to the father entity.
 * \param rng
 * \brief GSL random numbers generator.
 */
void selection_reproduction_linearrank
  (Population * population, Entity ** mother, Entity ** father, gsl_rng * rng)
{
  unsigned int i, j;
  i = (unsigned int) ((1.0 - sqrt (gsl_rng_uniform (rng)))
                      * population->nsurvival);
  *mother = population->entity + i;
  do
    j = (unsigned int) ((1.0 - sqrt (gsl_rng_uniform (rng)))
                        * population->nsurvival);
  while (i == j);
  *father = population->entity + j;
}

/**
 * \fn void selection_init(unsigned int mutation_type, \
 *   unsigned int reproduction_type, unsigned int adaptation_type)
 * \brief Function to select the selection operations.
 * \param mutation_type
 * \brief Type of mutation selection operations.
 * \param reproduction_type
 * \brief Type of reproduction selection operations.
 * \param adaptation_type
 * \brief Type of adaptation selection operations.
 */
void
selection_init (unsigned int mutation_type, unsigned int reproduction_type,
                unsigned int adaptation_type)
{
  switch (mutation_type)
    {
    case SELECTION_MUTATION_TYPE_RANDOM:
      selection_mutation = &selection_mutation_random;
      break;
    case SELECTION_MUTATION_TYPE_BESTOF2:
      selection_mutation = &selection_mutation_bestof2;
      break;
    case SELECTION_MUTATION_TYPE_BESTOF3:
      selection_mutation = &selection_mutation_bestof3;
      break;
    case SELECTION_MUTATION_TYPE_BEST:
      selection_mutation = &selection_mutation_best;
      break;
    default:
      selection_mutation = &selection_mutation_linearrank;
    }
  switch (reproduction_type)
    {
    case SELECTION_REPRODUCTION_TYPE_RANDOM:
      selection_reproduction = &selection_reproduction_random;
      break;
    case SELECTION_REPRODUCTION_TYPE_BESTOF2:
      selection_reproduction = &selection_reproduction_bestof2;
      break;
    case SELECTION_REPRODUCTION_TYPE_BESTOF3:
      selection_reproduction = &selection_reproduction_bestof3;
      break;
    case SELECTION_REPRODUCTION_TYPE_BEST:
      selection_reproduction = &selection_reproduction_best;
      break;
    default:
      selection_reproduction = &selection_reproduction_linearrank;
    }
  switch (adaptation_type)
    {
    case SELECTION_ADAPTATION_TYPE_RANDOM:
      selection_adaptation = &selection_mutation_random;
      break;
    case SELECTION_ADAPTATION_TYPE_BESTOF2:
      selection_adaptation = &selection_mutation_bestof2;
      break;
    case SELECTION_ADAPTATION_TYPE_BESTOF3:
      selection_adaptation = &selection_mutation_bestof3;
      break;
    case SELECTION_ADAPTATION_TYPE_BEST:
      selection_adaptation = &selection_mutation_best;
      break;
    default:
      selection_adaptation = &selection_mutation_linearrank;
    }
}
