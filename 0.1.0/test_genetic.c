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
 * \file test_genetic.c
 * \brief Source file to test the genetic algorithm functions.
 * \author Javier Burguete Tolosa.
 * \copyright Copyright 2014 Javier Burguete Tolosa. All rights reserved.
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <gsl/gsl_rng.h>
#include <glib.h>
#include "entity.h"
#include "population.h"
#include "reproduction.h"
#include "selection.h"
#include "evolution.h"
#include "genetic.h"

/**
 * \var ntasks
 * \brief Number of tasks.
 * \var nthreads
 * \brief Number of threads.
 * \var v
 * \brief Array of variables to optimize.
 */
unsigned int ntasks = 1;
unsigned int nthreads = 1;
GeneticVariable v[2];

/**
 * \fn double evaluate(Entity *entity)
 * \brief Evaluation function.
 * \param entity
 * \brief Entity to simulate.
 * \return RMSE error on the linear equations system: x+y=3, x-y=1.
 */
double evaluate(Entity *entity)
{
	double x, y, e1, e2;
	x = genetic_get_variable(entity, v);
	y = genetic_get_variable(entity, v + 1);
	e1 = x + y - 3.;
	e2 = x - y - 1.;
	e1 = e1 * e1 + e2 * e2;
	return e1;
}

/**
 * \fn int main()
 * \brief Main function.
 * \return 0 always.
 */
int main()
{
	char *best_genome;
	double *best_variables, best_objective;
	v[0].maximum = 10.;
	v[0].minimum = -10.;
	v[0].nbits = 7;
	v[1].maximum = 10.;
	v[1].minimum = -10.;
	v[1].nbits = 7;
	genetic_algorithm(
		2,
		v,
		129,
		10,
		0.4,
		0.4,
		0,
		0,
		0,
		&evaluate,
		&best_genome,
		&best_variables,
		&best_objective);
	printf("x=%lg y=%lg error=%lg\n",
		best_variables[0], best_variables[1], best_objective);
	g_free(best_genome);
	g_free(best_variables);
	nthreads = 4;
	genetic_algorithm(
		2,
		v,
		129,
		10,
		0.4,
		0.4,
		0,
		0,
		0,
		&evaluate,
		&best_genome,
		&best_variables,
		&best_objective);
	printf("x=%lg y=%lg error=%lg\n",
		best_variables[0], best_variables[1], best_objective);
	g_free(best_genome);
	g_free(best_variables);
	return 0;
}
