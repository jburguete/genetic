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
 * \file population.h
 * \brief Header file to define the population functions and data.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#ifndef POPULATION__H
#define POPULATION__H 1

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
 * \brief Bit position in the genome.
 */
	double maximum, minimum;
	unsigned int nbits, location;
} GeneticVariable;

/**
 * \struct Population
 * \brief Population struct.
 */
typedef struct
{
/**
 * \var entity
 * \brief Array of entities.
 * \var variable
 * \brief Array of variables data.
 * \var objective
 * \brief Array ot objective function values.
 * \var nvariables
 * \brief Number of variables.
 * \var genome_nbits
 * \brief Number of bits of the genomes.
 * \var genome_nbytes
 * \brief Number of bytes of the genomes.
 * \var nentities
 * \brief Number of entities.
 * \var nsurvival
 * \brief Number of survival entities.
 * \var mutation_min
 * \brief Minimum entity to mutation.
 * \var mutation_max
 * \brief Maximum entity to mutation.
 * \var reproduction_min
 * \brief Minimum entity to reproduction.
 * \var reproduction_max
 * \brief Maximum entity to reproduction.
 * \var adaptation_min
 * \brief Minimum entity to adaptation.
 * \var adaptation_max
 * \brief Maximum entity to adaptation.
 */
	Entity *entity;
	GeneticVariable *variable;
	double *objective;
	unsigned int nvariables, genome_nbits, genome_nbytes, nentities, nsurvival,
		mutation_min, mutation_max, reproduction_min, reproduction_max,
		adaptation_min, adaptation_max;
} Population;

int population_new(
	Population *population,
	GeneticVariable *variable,
	unsigned int nvariables,
	unsigned int genome_nbits,
	unsigned int nentities,
	double mutation_ratio,
	double reproduction_ratio,
	double adaptation_ratio);
void population_free(Population *population);
void population_init_genomes(Population *population, gsl_rng *rng);

#endif
