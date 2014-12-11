GENETIC (0.6.0 version)
=======================

A simple genetic algorithm.

AUTHORS
-------

* Javier Burguete Tolosa (jburguete@eead.csic.es)
* Borja Latorre Garcés (borja.latorre@csic.es)

REQUIRED
--------

* gcc or clang (to compile the source code)
* autoconf (to generate the Makefile in different systems)
* automake (to detect the system)
* pkg-config (to find the libraries to compile)
* gsl (the GNU scientific library to generate random numbers)
* gthreads (to use multicores in shared memory machines)
* glib (extended utilities of C to work with data, lists, random numbers, ...)
* openmpi or mpich (optional: to parallelize executions in a computers cluster)
* doxygen (optional: standard comments format to generate documentation)
* latex (optional: to build the PDF manual)

FILES
-----

* configure.ac: configure generator.
* Makefile.in: Makefile generator.
* TODO: List of tasks TO DO (in spanish)
* *.h: Header files.
* *.c: Source files.
* Doxyfile: configuration file to generate doxygen documentation.

BUILDING THE BINARY FILES
-------------------------

This software has been built and tested in the following operative systems:

Debian Linux 7.7
________________
Debian kFreeBSD 7.7
___________________
Debian Hurd 7.7
_______________
DragonFly BSD 4.0.1
___________________
FreeBSD 10.0
____________
NetBSD 6.1.5 (with modular xorg)
________________________________

Download this repository and exec on a terminal
> $ cd PATH_TO_GENETIC_REPOSITORY/0.6.0
>
> $ aclocal
>
> $ autoconf
>
> $ automake --add-missing
>
> $ ./configure
>
> $ make

Microsoft Windows 7 32 bits
___________________________
Microsoft Windows XP 32 bits
____________________________

1. install [MSYS/MinGW](http://www.mingw.org) and the required libraries and
utilities. You can follow detailed instructions in
[MinGW-64-Make](https://github.com/jburguete/MinGW-64-Make)

2. Then, download this repository and exec on a MSYS terminal:
> $ cd PATH_TO_GENETIC_REPOSITORY/0.6.0
>
> $ aclocal
>
> $ autoconf
>
> $ automake --add-missing
>
> $ ./configure
>
> $ make

Microsoft Windows 7 64 bits
___________________________
Microsoft Windows XP 64 bits
____________________________

1. install [MSYS/MinGW](http://www.mingw.org) and the required libraries and
utilities. You can follow detailed instructions in
[MinGW-64-Make](https://github.com/jburguete/MinGW-64-Make)

2. Then, download this repository and exec on a MSYS terminal:
> $ cd PATH_TO_GENETIC_REPOSITORY/0.6.0
>
> $ aclocal
>
> $ autoconf
>
> $ automake --add-missing
>
> $ ./configure --host=x86_64-w64-mingw32
>
> $ make

OpenBSD 5.6
___________

Download this repository and exec on a terminal
> $ export AUTOCONF_VERSION=2.69 AUTOMAKE_VERSION=1.14
>
> $ cd PATH_TO_GENETIC_REPOSITORY/0.6.0
>
> $ aclocal
>
> $ autoconf
>
> $ automake --add-missing
>
> $ ./configure
>
> $ make

BUILDING IN OTHER PROGRAMS
--------------------------

To build this algorithm in other programs:

1. Build the binary code (follows the former section steps)

2. Link in your source directory the latest code version i.e.
> $ cd YOUR_PROGRAM_PATH
>
> $ ln -s PATH_TO_GENETIC/0.6.0 genetic

3. Include the genetic header in your source code files:
> \#include \<genetic/genetic.h\>

4. Include the genetic object files in your compilation instruction i.e.
> $ gcc YOUR_CODE.c genetic/entity.o genetic/population.o \
>
> $ genetic/reproduction.o genetic/selection.o genetic/evolution.o \
>
> $ genetic/genetic.o

USING THE ALGORITHM IN OTHER PROGRAMS
-------------------------------------

MAIN FUNCTION
_____________

The prototype of the main function is:
> int genetic_algorithm(
>
>>	unsigned int nvariables,
>>
>>	GeneticVariable *variable,
>>
>>	unsigned int population,
>>
>>	unsigned int ngenerations,
>>
>>	double mutation_ratio,
>>
>>	double reproduction_ratio,
>>
>>  double adaptation_ratio,
>>
>>  const gsl_rng_type *type_random,
>>
>>	unsigned long random_seed,
>>
>>	unsigned int type_reproduction,
>>
>>	unsigned int type_selection_mutation,
>>
>>	unsigned int type_selection_reproduction,
>>
>>	double (\*simulate_entity)(Entity\*),
>>
>>	char **best_genome,
>>
>>	double **best_variables,
>>
>>	double *best_objective);

Where the parameters are:
* nvariables: variables number
* genetic_variable: array of data to define each variable. The fields of the
	data structure are:
	* maximum: maximum value
	* minimum: minimum value
	* nbits: number of bits to encode
* population: population size
* ngenerations: number of generations
* mutation_ratio: mutation probability
* reproduction_ratio: reproduction probability
* adaptation_ratio: adaptation probability
* type_random: type of GSL random numbers generator algorithm. See the
[GSL documentation]
(https://www.gnu.org/software/gsl/manual/html_node/index.html).
Valid algorithms are:
	* gsl_rgn_mt19937 (default value)
	* gsl_rng_taus
	* gsl_rgn_gfsr4
	* gsl_rgn_ranlxs0
	* gsl_rgn_ranlxs1
	* gsl_rgn_mrg
	* gsl_rgn_ranlux
	* gsl_rgn_ranlxd1
	* gsl_rgn_ranlxs2
	* gsl_rgn_cmrg
	* gsl_rgn_ranlux389
	* gsl_rgn_ranlxd2
* random_seed: seed to the GSL random numbers generator algorithm (0 uses the
default GSL seed)
* type_reproduction: type of reproduction algorithm. Valid values are:
	* REPRODUCTION_TYPE_MIXING (default value): the son genome is a random
		mixing between mother and father genomes in each bit.
	* REPRODUCTION_TYPE_SINGLEPOINTS: the son genome is equal to mother genome
		previous to a random point and next it is equal to the father genome.
	* REPRODUCTION_TYPE_DOUBLEPOINTS: the son genome is equal to father genome
		between two random points and equal to the mother genome in the rest.
* type_selection_mutation: type of algorithm to select the mothers to create
sons with a mutation. A mutation inverts a random bit in the genome. Valid
values are:
	* SELECTION_MUTATION_TYPE_LINEARRANK (default value): the mother is selected
		randomly between the survival entities assigning a linear probabiltiy
		higher for better entities.
	* SELECTION_MUTATION_TYPE_RANDOM: the mother is selected randomly between
		the survival entities
	* SELECTION_MUTATION_TYPE_BESTOF2: the mother is the best of two randomly
		selected between the survival entities
	* SELECTION_MUTATION_TYPE_BESTOF3: the mother is the best of three randomly
		selected between the survival entities
	* SELECTION_MUTATION_TYPE_BEST: the mother is the best of the survival
		entities
* type_selection_reproduction: type of algorithm to select the parents to
reproduce
* type_selection_adaptation: type of algorithm to select the mothers to create
sons with a adaptation. An adaption inverts a random bit between the lowest
significative bits. Valid values are:
	* SELECTION_ADAPTATION_TYPE_LINEARRANK (default value): the mother is
		selected randomly between the survival entities assigning a linear
		probabiltiy higher for better entities.
	* SELECTION_ADAPTATION_TYPE_RANDOM: the mother is selected randomly between
		the survival entities
	* SELECTION_ADAPTATION_TYPE_BESTOF2: the mother is the best of two randomly
		selected between the survival entities
	* SELECTION_ADAPTATION_TYPE_BESTOF3: the mother is the best of three
		randomly selected between the survival entities
	* SELECTION_ADAPTATION_TYPE_BEST: the mother is the best of the survival
		entities
* simulate_entity: pointer to the function to perform each simulation
* best_genome: new generated best genome
* best_variables: new generated best variables array
* best_objective: obtained best objective function value

CONVENIENT FUNCTION USING DEFAULT ALGORITHMS
____________________________________________

If using default algorithms is considered, the following convenient simplified
function can be used:
> int genetic_algorithm_default(
>
>>	unsigned int nvariables,
>>
>>	GeneticVariable *variable,
>>
>>	unsigned int population,
>>
>>	unsigned int ngenerations,
>>
>>	double mutation_ratio,
>>
>>	double reproduction_ratio,
>>
>>  double adaptation_ratio,
>>
>>	double (\*simulate_entity)(Entity\*),
>>
>>	char **best_genome,
>>
>>	double **best_variables,
>>
>>	double *best_objective);


MAKING REFERENCE MANUAL INSTRUCTIONS (file latex/refman.pdf)
------------------------------------------------------------

Exec on a terminal
> $ cd PATH_TO_THIS_REPOSITORY/0.6.0
>
> $ doxygen
>
> $ cd latex
>
> $ make
