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

/**
 * \def GENETIC_RANDOM_GENERATOR
 * \brief Macro to define the GSL random numbers generator algorithm.
 */
#define GENETIC_RANDOM_GENERATOR gsl_rng_mt19937

/**
 * \struct GeneticThreadData
 * \brief Structure to define the parallel data needed on each thread.
 */
typedef struct
{
/**
 * \var nmin
 * \brief The lowest simulation number to execute in the thread.
 * \var nmax
 * \brief The highest simulation number to execute in the thread.
 */
	unsigned int nmin, nmax;
} GeneticThreadData;

/**
 * \struct GeneticVariable
 * \brief Structure to define a variable to optimize in a genetic algorithm.
 */
typedef struct
{
/**
 * \var maximum
 * \brief Maximum value allowed.
 * \var minimum
 * \brief Minimum value allowed.
 * \var nbits
 * \brief Number of bits to encode in the genome.
 * \var location
 * \brief Bit posistion in the genome.
 */
	double maximum, minimum;
	unsigned int nbits, location;
} GeneticVariable;

extern unsigned int ntasks;
extern unsigned int nthreads;
extern Population genetic_population[1];
extern double (*genetic_simulation)(Entity*);

double genetic_get_variable(Entity *entity, GeneticVariable *variable);
void genetic_simulation_thread(GeneticThreadData *data);
void genetic_simulation_population(unsigned int nsurvival);
int genetic_algorithm(
	unsigned int nvariables,
	GeneticVariable *variable,
	unsigned int nentities,
	unsigned int ngenerations,
	double mutation_ratio,
	double reproduction_ratio,
	unsigned int type_reproduction,
	unsigned int type_selection_mutation,
	unsigned int type_selection_reproduction,
	double (*simulate_entity)(Entity*),
	char **best_genome,
	double **best_variables,
	double *best_objective);

#endif
