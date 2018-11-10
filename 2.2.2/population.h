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
  double maximum;               ///< Maximum value allowed.
  double minimum;               ///< Minimum value allowed.
  unsigned int nbits;           ///< Number of bits to encode in the genome.
  unsigned int location;        ///< Bit position in the genome.
} GeneticVariable;

/**
 * \struct Population
 * \brief Population struct.
 */
typedef struct
{
  Entity *entity;               ///< Array of entities.
  GeneticVariable *variable;    ///< Array of variables data.
  double *objective;            ///< Array ot objective function values.
  double threshold;             ///< Threshold to finish the simulations.
  unsigned int nvariables;      ///< Number of variables.
  unsigned int genome_nbits;    ///< Number of bits of the genomes.
  unsigned int genome_nbytes;   ///< Number of bytes of the genomes.
  unsigned int nentities;       ///< Number of entities.
  unsigned int nsurvival;       ///< Number of survival entities.
  unsigned int mutation_min;    ///< Minimum entity to mutation.
  unsigned int mutation_max;    ///< Maximum entity to mutation.
  unsigned int reproduction_min;        ///< Minimum entity to reproduction.
  unsigned int reproduction_max;        ///< Maximum entity to reproduction.
  unsigned int adaptation_min;  ///< Minimum entity to adaptation.
  unsigned int adaptation_max;  ///< Maximum entity to adaptation.
  unsigned int stop;            ///< Variable to finish the simulations.
} Population;

int population_new (Population * population,
                    GeneticVariable * variable,
                    unsigned int nvariables,
                    unsigned int genome_nbits,
                    unsigned int nentities,
                    double mutation_ratio,
                    double reproduction_ratio,
                    double adaptation_ratio, double threshold);
void population_free (Population * population);
void population_init_genomes (Population * population, gsl_rng * rng);

#endif
