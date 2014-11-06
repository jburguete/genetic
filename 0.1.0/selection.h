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
 * \file selection.h
 * \brief Header file to define parents selection functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#ifndef SELECTION__H
#define SELECTION__H 1

/**
 * \enum SelectionMutationType
 * \brief Enumeration to define the types of mutation selection operations.
 */
enum SelectionMutationType
{
/**
 * \var SELECTION_MUTATION_TYPE_RANDOM
 * \brief Random mutation selection operation type.
 * \var SELECTION_MUTATION_TYPE_BESTOF2
 * \brief Best of two random mutation selection operation type.
 * \var SELECTION_MUTATION_TYPE_BESTOF3
 * \brief Best of three random mutation selection operation type.
 * \var SELECTION_MUTATION_TYPE_BEST
 * \brief Best mutation selection operation type.
 * \var SELECTION_MUTATION_TYPE_LINEARRANK
 * \brief Mutation selection operation type based on linear probability
 *   distribution with respect to rank.
 */
	SELECTION_MUTATION_TYPE_RANDOM = 1,
	SELECTION_MUTATION_TYPE_BESTOF2 = 2,
	SELECTION_MUTATION_TYPE_BESTOF3 = 3,
	SELECTION_MUTATION_TYPE_BEST = 4,
	SELECTION_MUTATION_TYPE_LINEARRANK = 5
};

/**
 * \enum SelectionReproductionType
 * \brief Enumeration to define the types of reproduction selection operations.
 */
enum SelectionReproductionType
{
/**
 * \var SELECTION_REPRODUCTION_TYPE_RANDOM
 * \brief Random reproduction selection operation type.
 * \var SELECTION_REPRODUCTION_TYPE_BESTOF2
 * \brief Best of two random reproduction selection operation type.
 * \var SELECTION_REPRODUCTION_TYPE_BESTOF3
 * \brief Best of three random reproduction selection operation type.
 * \var SELECTION_REPRODUCTION_TYPE_BEST
 * \brief Best reproduction selection operation type.
 * \var SELECTION_REPRODUCTION_TYPE_LINEARRANK
 * \brief Reproduction selection operation type based on linear probability
 *   distribution with respect to rank.
 */
	SELECTION_REPRODUCTION_TYPE_RANDOM = 1,
	SELECTION_REPRODUCTION_TYPE_BESTOF2 = 2,
	SELECTION_REPRODUCTION_TYPE_BESTOF3 = 3,
	SELECTION_REPRODUCTION_TYPE_BEST = 4,
	SELECTION_REPRODUCTION_TYPE_LINEARRANK = 5
};

extern void (*selection_mutation)(Population*, Entity**, gsl_rng*);
extern void (*selection_reproduction)(Population*, Entity**, Entity**, gsl_rng*);

void selection_mutation_random
(Population *population, Entity **mother, gsl_rng *rng);
void selection_mutation_bestof2
(Population *population, Entity **mother, gsl_rng *rng);
void selection_mutation_bestof3
(Population *population, Entity **mother, gsl_rng *rng);
void selection_mutation_best
(Population *population, Entity **mother, gsl_rng *rng);
void selection_mutation_linearrank
(Population *population, Entity **mother, gsl_rng *rng);

void selection_reproduction_random
(Population *population, Entity **mother, Entity **father, gsl_rng *rng);
void selection_reproduction_bestof2
(Population *population, Entity **mother, Entity **father, gsl_rng *rng);
void selection_reproduction_bestof3
(Population *population, Entity **mother, Entity **father, gsl_rng *rng);
void selection_reproduction_best
(Population *population, Entity **mother, Entity **father, gsl_rng *rng);
void selection_reproduction_linearrank
(Population *population, Entity **mother, Entity **father, gsl_rng *rng);

void selection_init(unsigned int mutation_type, unsigned int reproduction_type);

#endif
