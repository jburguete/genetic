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
 * \file reproduction.h
 * \brief Header file to define the reproduction functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#ifndef REPRODUCTION__H
#define REPRODUCTION__H 1

/**
 * \enum ReproductionType
 * \brief Enumeration to define the types of reproduction operations.
 */
enum ReproductionType
{
/**
 * \var REPRODUCTION_TYPE_SINGLEPOINTS
 * \brief Single points reproduction operation type.
 * \var REPRODUCTION_TYPE_DOUBLEPOINTS
 * \brief Double points reproduction operation type.
 * \var REPRODUCTION_TYPE_MIXING
 * \brief Mixing all bits reproduction operation type.
 */
	REPRODUCTION_TYPE_SINGLEPOINTS = 1,
	REPRODUCTION_TYPE_DOUBLEPOINTS = 2,
	REPRODUCTION_TYPE_MIXING = 3
};

extern void
(*reproduction)(Entity*, Entity*, Entity*, unsigned int, gsl_rng*);

void reproduction_singlepoints(Entity *father, Entity *mother, Entity *son,
	unsigned int nbits, gsl_rng *rng);
void reproduction_doublepoints(Entity *father, Entity *mother, Entity *son,
	unsigned int nbits, gsl_rng *rng);
void reproduction_mixing(Entity *father, Entity *mother, Entity *son,
	unsigned int nbits, gsl_rng *rng);
void reproduction_init(unsigned int type);

#endif
