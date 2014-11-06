GENETIC (0.1.0 version)
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
DragonFly BSD 3.8.2
___________________
FreeBSD 10.0
____________
NetBSD 6.1.5 (with modular xorg)
________________________________

* cd 0.1.0
* aclocal
* autoconf
* automake --add-missing
* ./configure
* make

Microsoft Windows 7 32 bits
___________________________
Microsoft Windows XP 32 bits
____________________________

* install [MSYS/MinGW](http://www.mingw.org) and the required libraries and
utilities. You can follow detailed instructions in
[MinGW-64-Make](https://github.com/jburguete/MinGW-64-Make)
* cd 0.1.0
* aclocal
* autoconf
* automake --add-missing
* ./configure
* make


Microsoft Windows 7 64 bits
___________________________
Microsoft Windows XP 64 bits
____________________________

* install [MSYS/MinGW](http://www.mingw.org) and the required libraries and
utilities. You can follow detailed instructions in
[MinGW-64-Make](https://github.com/jburguete/MinGW-64-Make)
* cd 0.1.0
* aclocal
* autoconf
* automake --add-missing
* configure --host=x86_64-w64-mingw32
* make

OpenBSD 5.6
___________

* export AUTOCONF_VERSION=2.69 AUTOMAKE_VERSION=1.14
* cd 0.1.0
* aclocal
* autoconf
* automake --add-missing
* ./configure
* make

BUILDING IN OTHER PROGRAMS
--------------------------

To build this algorithm in other programs:

1) Build the binary code (follows the former section steps)

2) Link in your source directory the latest code version i.e.
> $ cd YOUR_PROGRAM_PATH
>
> $ ln -s PATH_TO_GENETIC/0.1.0 genetic

2) Include the genetic header in your source code files:
> #include <genetic/genetic.h>

3) Include the genetic object files in your compilation instruction i.e.
> $ gcc YOUR_CODE.c genetic/entity.o genetic/population.o \
> $ genetic/reproduction.o genetic/selection.o genetic/evolution.o \
> $ genetic/genetic.o

USING THE ALGORITHM IN OTHER PROGRAMS
-------------------------------------

The algorithm function prototype is:
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
>>	unsigned int type_reproduction,
>>
>>	unsigned int type_selection_mutation,
>>
>>	unsigned int type_selection_reproduction,
>>
>>	double (*simulate_entity)(Entity*),
>>
>>	char **best_genome,
>>
>>	double **best_variables,
>>
>>	double *best_objective);

Where the parameters are:
* nvariables: variables number
* genetic_variable: array of data to define each variable
* population: population size
* ngenerations: number of generations
* mutation_ration: mutation probability
* reproduction_ration: reproduction probability
* type_reproduction: type of reproduction
* type_selection_mutation: type of mother selection to mutate
* type_selection_reproduction: type of selection parents to reproduce
* simulate_entity: pointer to the function to perform each simulation
* best_genome: new generated best genome
* best_variables: new generated best variables array
* best_objective: obtained best objective function value

MAKING REFERENCE MANUAL INSTRUCTIONS
------------------------------------

* cd 0.1.0
* doxygen
* cd doc/latex
* make
