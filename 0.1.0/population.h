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
 * \struct Population
 * \brief Population struct.
 */
typedef struct
{
/**
 * \var entity
 * \brief Array of entities.
 * \var objective
 * \brief Array ot objective function values.
 * \var index
 * \brief Array of index sorting the entities.
 * \var genome_nbits
 * \brief Number of bits of the genomes.
 * \var genome_nbytes
 * \brief Number of bytes of the genomes.
 * \var nentities
 * \brief Number of entities.
 * \var nsurvival
 * \brief Number of survival entities.
 * \var mutation_min
 * \brief Minimum index to mutation.
 * \var mutation_max
 * \brief Maximum index to mutation.
 * \var reproduction_min
 * \brief Minimum index to reproduction.
 * \var reproduction_max
 * \brief Maximum index to reproduction.
 */
	Entity *entity;
	double *objective;
	unsigned int *index;
	unsigned int genome_nbits, genome_nbytes, nentities, nsurvival,
		mutation_min, mutation_max, reproduction_min, reproduction_max;
} Population;

int population_new(Population *population, unsigned int genome_nbits,
	unsigned int nentities, double mutation_ratio, double reproduction_ratio,
	gsl_rng *rng);
void population_free(Population *population);

#endif
