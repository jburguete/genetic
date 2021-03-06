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
 * \file genetic.h
 * \brief Header file to define genetic algorithm main functions and data.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#ifndef GENETIC__H
#define GENETIC__H 1

#include "entity.h"
#include "population.h"

/**
 * \struct GeneticThreadData
 * \brief Structure to define the parallel data needed on each thread.
 */
typedef struct
{
  unsigned int nmin;
  ///< The lowest simulation number to execute in the thread.
  unsigned int nmax;
  ///< The highest simulation number to execute in the thread.
} GeneticThreadData;

extern int ntasks;
extern unsigned int nthreads;
extern GMutex mutex[1];

double genetic_get_variable (Entity * entity, GeneticVariable * variable);
int genetic_new (unsigned int nvariables,
                 GeneticVariable * variable,
                 unsigned int nentities,
                 double mutation_ratio,
                 double reproduction_ratio,
                 double adaptation_ratio, double threshold);
int genetic_algorithm (unsigned int nvariables,
                       GeneticVariable * variable,
                       unsigned int nentities,
                       unsigned int ngenerations,
                       double mutation_ratio,
                       double reproduction_ratio,
                       double adaptation_ratio,
                       const gsl_rng_type * type_random,
                       unsigned long random_seed,
                       unsigned int type_reproduction,
                       unsigned int type_selection_mutation,
                       unsigned int type_selection_reproduction,
                       unsigned int type_selection_adaptation,
                       double threshold,
                       double (*simulate_entity) (Entity *),
                       char **best_genome,
                       double **best_variables, double *best_objective);
int genetic_algorithm_default (unsigned int nvariables,
                               GeneticVariable * variable,
                               unsigned int nentities,
                               unsigned int ngenerations,
                               double mutation_ratio,
                               double reproduction_ratio,
                               double adaptation_ratio,
                               unsigned long random_seed,
                               double threshold,
                               double (*simulate_entity) (Entity *),
                               char **best_genome,
                               double **best_variables, double *best_objective);

#endif
