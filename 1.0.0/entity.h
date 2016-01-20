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
 * \file entity.h
 * \brief Header file to define the entity functions and data.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#ifndef ENTITY__H
#define ENTITY__H 1

/**
 * \struct Entity
 * \brief Entity struct.
 */
typedef struct
{
  char *genome;                 ///< Genome data.
  unsigned int id;              ///< Identifier number.
} Entity;

void entity_new (Entity * entity, unsigned int genome_nbytes, unsigned int id);
void entity_init (Entity * entity, unsigned int genome_nbytes, gsl_rng * rng);
void entity_free (Entity * entity);

#endif
