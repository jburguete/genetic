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
 * \file genetic.c
 * \brief Source file to define genetic algorithm main function.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <glib.h>
#if HAVE_MPI
	#include <mpi.h>
#endif
#include "bits.h"
#include "entity.h"
#include "population.h"
#include "reproduction.h"
#include "selection.h"
#include "evolution.h"
#include "genetic.h"

/**
 * \def DEBUG_GENETIC
 * \brief Macro to debug the genetic functions.
 */
#define DEBUG_GENETIC 0

/**
 * \var genetic_population
 * \brief Population of the genetic algorithm.
 * \var genetic_simulation
 * \brief Pointer to the function to perform a simulation.
 */
Population genetic_population[1];
double (*genetic_simulation)(Entity*);

/**
 * \fn double genetic_get_variable(Entity *entity, GeneticVariable *variable)
 * \brief Function to get a variable encoded in the genome of an entity.
 * \param entity
 * \brief Entity.
 * \param variable
 * \brief Variable data.
 * \return Variable value.
 */
double genetic_get_variable(Entity *entity, GeneticVariable *variable)
{
	double x;
#if DEBUG_GENETIC
fprintf(stderr, "get variable: start\n");
#endif
	x = variable->minimum
		+ bit_get_value(entity->genome, variable->location, variable->nbits)
		* (variable->maximum - variable->minimum)
		/ ((unsigned long long int)1L << variable->nbits);
#if DEBUG_GENETIC
fprintf(stderr, "get variable: value=%lg\n", x);
fprintf(stderr, "get variable: end\n");
#endif
	return x;
}

/**
 * \fn void genetic_evolution(Population *population, gsl_rng *rng)
 * \brief Funtion to apply the evolution of a population.
 * \param population
 * \brief Population
 * \param rng
 * \brief GSL random numbers generator.
 */
void genetic_evolution(Population *population, gsl_rng *rng)
{
#if DEBUG_GENETIC
fprintf(stderr, "genetic_evolution: start\n");
#endif
	evolution_mutation(population, rng);
	evolution_reproduction(population, rng);
	evolution_adaptation(population, rng);
#if DEBUG_GENETIC
fprintf(stderr, "genetic_evolution: end\n");
#endif
}

/**
 * \fn void genetic_simulation_thread(GeneticThreadData *data)
 * \brief Funtion to perform the simulations on a thread.
 * \param data
 * \brief Thread data.
 */
void genetic_simulation_thread(GeneticThreadData *data)
{
	unsigned int i;
#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_thread: start\n");
fprintf(stderr, "genetic_simulation_thread: nmin=%u nmax=%u\n",
data->nmin, data->nmax);
#endif
	for (i = data->nmin; i < data->nmax; ++i)
		genetic_population->objective[i]
			= genetic_simulation(genetic_population->entity + i);
#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_thread: end\n");
#endif
}

/**
 * \fn void genetic_simulation_master(unsigned int nsurvival)
 * \brief Function to perform the simulations on a task.
 * \param nsurvival
 * \brief Number of survival entities already simulated.
 */
void genetic_simulation_master(unsigned int nsurvival)
{
	unsigned int j, nsimulate, nmin, nmax;
	GThread *thread[nthreads];
	GeneticThreadData thread_data[nthreads];
	Population *population;
#if HAVE_MPI
	unsigned int i;
	unsigned int n[ntasks + 1];
	char *genome_array;
	MPI_Status mpi_status;
#endif

#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_master: start\n");
#endif

	population = genetic_population;
	nmax = population->nentities;
	nsimulate = nmax - nsurvival;
	nmin = nsurvival;

#if HAVE_MPI
	nmax = nmin + nsimulate / ntasks;

	// Send genome information to the slaves
#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_master: nmax=%u nmin=%u nsimulate=%u\n",
nmax, nmin, nsimulate);
#endif

	genome_array = (char*)g_malloc(nsimulate * population->genome_nbytes);
	for (j = 0; j < nsimulate; ++j)
		memcpy(genome_array + j * population->genome_nbytes,
			population->entity[nmin + j].genome, population->genome_nbytes);
	n[0] = 0;
	for (i = 0; ++i < ntasks;)
	{
		n[i] = i * nsimulate / ntasks;
		j = (i + 1) * nsimulate / ntasks - n[i];
#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_master: send %u bytes on %u to task %u\n",
j * population->genome_nbytes, nsurvival + n[i], i);
#endif
		MPI_Send(genome_array + n[i] * population->genome_nbytes,
			j * population->genome_nbytes, MPI_CHAR, i, 1, MPI_COMM_WORLD);
	}
	n[i] = nsimulate;

#if DEBUG_GENETIC
for (j = 0; j <= ntasks; ++j)
fprintf(stderr, "genetic_simulation_master: n[%u]=%u\n", j, n[j]);
#endif
	g_free(genome_array);

	nsimulate = nmax - nmin;

#endif

#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_master: nsimulate=%u\n", nsimulate);
fprintf(stderr, "genetic_simulation_master: performing simulations\n");
#endif

	thread_data[0].nmin = nmin;
	for (j = 0; ++j < nthreads;)
		thread_data[j - 1].nmax = thread_data[j].nmin
			= nmin + j * nsimulate / nthreads;
	thread_data[j - 1].nmax = nmax;
	for (j = 0; j < nthreads; ++j)
		thread[j] = g_thread_new
			(NULL, (void(*))genetic_simulation_thread, thread_data + j);
	for (j = 0; j < nthreads; ++j) g_thread_join(thread[j]);

#if HAVE_MPI
	// Receive objective function resuts from the slaves
	for (j = 0; ++j < ntasks;)
	{
#if DEBUG_GENETIC
fprintf(stderr,
"genetic_simulation_master: receive %u reals from task %u on %u\n",
n[j + 1] - n[j], j, nsurvival + n[j]);
#endif
		MPI_Recv(population->objective + nsurvival + n[j], n[j + 1] - n[j],
			MPI_DOUBLE, j, 1, MPI_COMM_WORLD, &mpi_status);
	}
#endif

#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_master: end\n");
#endif
}

#if HAVE_MPI

/**
 * \fn void genetic_simulation_slave(unsigned int nsurvival, int rank)
 * \brief Function to perform the simulations on a task.
 * \param nsurvival
 * \brief Number of survival entities already simulated.
 * \param rank
 * \brief Number of task.
 */
void genetic_simulation_slave(unsigned int nsurvival, int rank)
{
	unsigned int j, nsimulate, nmin, nmax;
	GThread *thread[nthreads];
	GeneticThreadData thread_data[nthreads];
	Population *population;
	char *genome_array;
	MPI_Status mpi_status;

#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_slave: rank=%d start\n", rank);
#endif

	population = genetic_population;
	nmax = population->nentities;
	nsimulate = nmax - nsurvival;
	nmin = nsurvival;
	nmax = nmin + (rank + 1) * nsimulate / ntasks;
	nmin += rank * nsimulate / ntasks;

	// Receive genome information from the master
	nsimulate = nmax - nmin;
	genome_array = (char*)g_malloc(nsimulate * population->genome_nbytes);
#if DEBUG_GENETIC
fprintf(stderr,
"genetic_simulation_slave: rank=%d receive %u bytes from master\n",
rank, nsimulate * population->genome_nbytes);
#endif
	MPI_Recv(genome_array, nsimulate * population->genome_nbytes, MPI_CHAR, 0,
		1, MPI_COMM_WORLD, &mpi_status);
#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_slave: rank=%d nmin=%u nsimulate=%u\n",
rank, nmin, nsimulate);
#endif
	for (j = 0; j < nsimulate; ++j)
		memcpy(population->entity[nmin + j].genome,
			genome_array + j * population->genome_nbytes,
			population->genome_nbytes);
#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_slave: rank=%d freeing\n", rank);
#endif
	g_free(genome_array);

#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_slave: rank=%d performing simulations\n",
rank);
#endif
	thread_data[0].nmin = nmin;
	for (j = 0; ++j < nthreads;)
		thread_data[j - 1].nmax = thread_data[j].nmin
			= nmin + j * nsimulate / nthreads;
	thread_data[j - 1].nmax = nmax;
	for (j = 0; j < nthreads; ++j)
		thread[j] = g_thread_new
			(NULL, (void(*))genetic_simulation_thread, thread_data + j);
	for (j = 0; j < nthreads; ++j) g_thread_join(thread[j]);

#if DEBUG_GENETIC
fprintf(stderr,
"genetic_simulation_slave: rank=%d send %u reals on %u to master\n",
rank, nsimulate, nmin);
#endif
	// Send the objective function resuts to the master
	MPI_Send(population->objective + nmin, nsimulate, MPI_DOUBLE, 0, 1,
		MPI_COMM_WORLD);

#if DEBUG_GENETIC
fprintf(stderr, "genetic_simulation_slave: rank=%d end\n", rank);
#endif
}

#endif

/**
 * \fn int genetic_new(unsigned int nvariables, \
 *   GeneticVariable *variable, unsigned int nentities, \
 *   unsigned int ngenerations, double mutation_ratio, \
 *   double reproduction_ratio, double adaptation_ratio)
 * \brief Function to create the data of the genetic algorithm.
 * \param nvariables
 * \brief Number of variables.
 * \param variable
 * \brief Array of variables data.
 * \param nentities
 * \brief Number of entities in each generation.
 * \param ngenerations
 * \brief Number of generations.
 * \param mutation_ratio
 * \brief Mutation ratio.
 * \param reproduction_ratio
 * \brief Reproduction ratio.
 * \param adaptation_ratio
 * \brief Adaptation ratio.
 * \return 1 on succes, 0 on error.
 */
int genetic_new(
	unsigned int nvariables,
	GeneticVariable *variable,
	unsigned int nentities,
	unsigned int ngenerations,
	double mutation_ratio,
	double reproduction_ratio,
	double adaptation_ratio)
{
	unsigned int i, genome_nbits, nprocesses;

#if DEBUG_GENETIC
fprintf(stderr, "genetic_new: start\n");
#endif

	// Checking variables number
	if (!nvariables)
	{
		fprintf(stderr, "ERROR: no variables\n");
		return 0;
	}

	// Checking variable bits number
	for (i = genome_nbits = 0; i < nvariables; ++i)
	{
		if (!variable[i].nbits || variable[i].nbits > 32)
		{
			fprintf(stderr, "ERROR: bad bits number in variable %u\n", i + 1);
			return 0;
		}
		variable[i].location = genome_nbits;
		genome_nbits += variable[i].nbits;
	}

	// Checking processes number
	nprocesses = ntasks * nthreads;
	if (!nprocesses)
	{
		fprintf(stderr, "ERROR: no processes\n");
		return 0;
	}

	// Init the population
#if DEBUG_GENETIC
fprintf(stderr, "genetic_new: init the population\n");
#endif
	if (!population_new(genetic_population, variable, nvariables, genome_nbits,
		nentities, mutation_ratio, reproduction_ratio, adaptation_ratio))
			return 0;

#if DEBUG_GENETIC
fprintf(stderr, "genetic_new: end\n");
#endif
	return 1;
}

/**
 * \fn int genetic_algorithm(unsigned int nvariables, \
 *   GeneticVariable *variable, unsigned int nentities, \
 *   unsigned int ngenerations, double mutation_ratio, \
 *   double reproduction_ratio, double adaptation_ratio, \
 *   const gsl_rng_type *type_random, unsigned long random_seed, \
 *   unsigned int type_reproduction, unsigned int type_selection_mutation, \
 *   unsigned int type_selection_reproduction, \
 *   unsigned int type_selection_adaptation, \
 *   double (*simulate_entity)(Entity*), char **best_genome, \
 *   double **best_variables, double *best_objective)
 * \brief Function to perform the genetic algorithm.
 * \param nvariables
 * \brief Number of variables.
 * \param variable
 * \brief Array of variables data.
 * \param nentities
 * \brief Number of entities in each generation.
 * \param ngenerations
 * \brief Number of generations.
 * \param mutation_ratio
 * \brief Mutation ratio.
 * \param reproduction_ratio
 * \brief Reproduction ratio.
 * \param adaptation_ratio
 * \brief Adaptation ratio.
 * \param type_random
 * \brief Type of GSL random numbers generator algorithm.
 * \param random_seed
 * \brief Seed of the GSL random numbers generator.
 * \param type_reproduction
 * \brief Type of reproduction algorithm.
 * \param type_selection_mutation
 * \brief Type of mutation selection algorithm.
 * \param type_selection_reproduction
 * \brief Type of reproduction selection algorithm.
 * \param type_selection_adaptation
 * \brief Type of adaptation selection algorithm.
 * \param simulate_entity
 * \brief Pointer to the function to perform a simulation of an entity.
 * \param best_genome
 * \brief Best genome. 
 * \param best_variables
 * \brief Best array of variables.
 * \param best_objective
 * \brief Best objective function value.
 * \return 1 on succes, 0 on error.
 */
int genetic_algorithm(
	unsigned int nvariables,
	GeneticVariable *variable,
	unsigned int nentities,
	unsigned int ngenerations,
	double mutation_ratio,
	double reproduction_ratio,
	double adaptation_ratio,
	const gsl_rng_type *type_random,
	unsigned long random_seed,
	unsigned int type_reproduction,
	unsigned int type_selection_mutation,
	unsigned int type_selection_reproduction,
	unsigned int type_selection_adaptation,
	double (*simulate_entity)(Entity*),
	char **best_genome,
	double **best_variables,
	double *best_objective)
{
	unsigned int i;
	double *bv;
	gsl_rng *rng;
	Entity *best_entity;
#if HAVE_MPI
	int rank;
#endif

#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: start\n");
#endif

	// Init the data
	if (!genetic_new(nvariables, variable, nentities, ngenerations,
		mutation_ratio, reproduction_ratio, adaptation_ratio))
			return 0;

	// Init the evaluation function
	genetic_simulation = simulate_entity;
	
	// Get the rank
#if HAVE_MPI
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
#endif

	// Variables to init only by master task
#if HAVE_MPI
	if (rank == 0)
	{
#endif
		// Init the GSL random numbers generator
		rng = gsl_rng_alloc(type_random);
		if (random_seed) gsl_rng_set(rng, random_seed);

		// Init genomes
		population_init_genomes(genetic_population, rng);

		// Init selection, mutation and reproduction algorithms
		reproduction_init(type_reproduction);
		selection_init(type_selection_mutation, type_selection_reproduction,
			type_selection_adaptation);

#if HAVE_MPI
	}
	if (rank == 0)
	{
#endif

		// First simulation of all entities
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: first simulation of all entities\n");
#endif
		genetic_simulation_master(0);

		// Sorting by objective function results
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: sorting by objective function results\n");
#endif
		evolution_sort(genetic_population);

		// Population generations
		for (i = 1; i < ngenerations; ++i)
		{
			// Evolution
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: evolution of the population\n");
#endif
			genetic_evolution(genetic_population, rng);

			// Simulation of the new entities
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: simulation of the new entities\n");
#endif
			genetic_simulation_master(genetic_population->nsurvival);

			// Sorting by objective function results
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: sorting by objective function results\n");
#endif
			evolution_sort(genetic_population);
		}
		
		// Saving the best
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: saving the best\n");
#endif
		best_entity = genetic_population->entity;
		*best_objective = genetic_population->objective[0];
		*best_genome = g_malloc(genetic_population->genome_nbytes);
		memcpy(*best_genome, best_entity->genome,
			genetic_population->genome_nbytes);
		*best_variables = bv = g_malloc(nvariables * sizeof(double));
		for (i = 0; i < nvariables; ++i)
			bv[i] = genetic_get_variable(best_entity, variable + i);
		gsl_rng_free(rng);

#if HAVE_MPI

	}
	else
	{
		// First simulation of all entities
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: first simulation of all entities\n");
#endif
		genetic_simulation_slave(0, rank);

		// Population generations
		for (i = 1; i < ngenerations; ++i)
		{
			// Simulation of the new entities
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: simulation of the new entities\n");
#endif
			genetic_simulation_slave(genetic_population->nsurvival, rank);
		}
	}

#endif

	// Freeing memory
#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: freeing memory\n");
#endif
	population_free(genetic_population);

#if DEBUG_GENETIC
fprintf(stderr, "genetic_algorithm: end\n");
#endif
	return 1;
}

/**
 * \fn int genetic_algorithm_default(unsigned int nvariables, \
 *   GeneticVariable *variable, unsigned int nentities, \
 *   unsigned int ngenerations, double mutation_ratio, \
 *   double reproduction_ratio, double adaptation_ratio, \
 *   double (*simulate_entity)(Entity*), char **best_genome, \
 *   double **best_variables, double *best_objective)
 * \brief Function to perform the genetic algorithm with default random and
 *   evolution algorithms.
 * \param nvariables
 * \brief Number of variables.
 * \param variable
 * \brief Array of variables data.
 * \param nentities
 * \brief Number of entities in each generation.
 * \param ngenerations
 * \brief Number of generations.
 * \param mutation_ratio
 * \brief Mutation ratio.
 * \param reproduction_ratio
 * \brief Reproduction ratio.
 * \param adaptation_ratio
 * \brief Adaptation ratio.
 * \param simulate_entity
 * \brief Pointer to the function to perform a simulation of an entity.
 * \param best_genome
 * \brief Best genome. 
 * \param best_variables
 * \brief Best array of variables.
 * \param best_objective
 * \brief Best objective function value.
 * \return 1 on succes, 0 on error.
 */
int genetic_algorithm_default(
	unsigned int nvariables,
	GeneticVariable *variable,
	unsigned int nentities,
	unsigned int ngenerations,
	double mutation_ratio,
	double reproduction_ratio,
	double adaptation_ratio,
	double (*simulate_entity)(Entity*),
	char **best_genome,
	double **best_variables,
	double *best_objective)
{
	return genetic_algorithm(
		nvariables,
		variable,
		nentities,
		ngenerations,
		mutation_ratio,
		reproduction_ratio,
		adaptation_ratio,
		gsl_rng_mt19937,
		0l,
		0,
		0,
		0,
		0,
		simulate_entity,
		best_genome,
		best_variables,
		best_objective);
}
