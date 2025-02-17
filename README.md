GENETIC (3.0.1 version)
=======================

:uk:[english](README.md) :es:[español](README.es.md)

A simple genetic algorithm for optimization

AUTHORS
-------

* Javier Burguete Tolosa (jburguete@eead.csic.es)
* Borja Latorre Garcés (borja.latorre@csic.es)

FILES
-----

* configure.ac: configure generator
* Makefile.in: Makefile generator
* build.sh: simplified building shell script
* README.md: This file
* \*.h: Header files
* \*.c: Source files
* Doxyfile: configuration file to generate doxygen documentation

TOOLS AND LIBRARIES REQUIRED TO BUILD THE EXECUTABLE
----------------------------------------------------

* [gcc](https://gcc.gnu.org) or [clang](http://clang.llvm.org) to compile the
  source code
* [make](http://www.gnu.org/software/make) to build the executable file
* [autoconf](http://www.gnu.org/software/autoconf) to generate the Makefile in
  different operative systems
* [automake](http://www.gnu.org/software/automake) to check the operative
  system
* [pkg-config](http://www.freedesktop.org/wiki/Software/pkg-config) to find the
  libraries to compile
* [gsl](http://www.gnu.org/software/gsl) to generate random numbers
* [glib](https://developer.gnome.org/glib) extended utilities of C to work with
  data, lists, mapped files, regular expressions, using multicores in shared
  memory machines, ...

OPTIONAL TOOLS AND LIBRARIES
----------------------------

* [openmpi](http://www.open-mpi.org) or [mpich](http://www.mpich.org) to run in
parallelized tasks on multiple computers
* [doxygen](http://www.stack.nl/~dimitri/doxygen) standard comments format to
generate documentation
* [latex](https://www.latex-project.org/) to build the PDF manuals

BUILDING THE BINARY FILES
-------------------------

On Fedora Linux 40, in order to use OpenMPI compilation, do in a terminal (in 64 bits
version):
> $ export PATH=$PATH:/usr/lib64/openmpi/bin
with MPIC (in 64 bits version):
> $ export PATH=$PATH:/usr/lib64/mpich/bin

On Microsoft Windows systems you have to install
[MSYS2](http://sourceforge.net/projects/msys2) and the required
libraries and utilities. You can follow detailed instructions in
[install-unix](https://github.com/jburguete/install-unix/blob/master/tutorial.pdf)

On NetBSD 10.0, to compile with last GCC version you have to do first on the
building terminal:
> $ export PATH=/usr/pkg/gcc9/bin:$PATH"

On OpenBSD 7.5 you have to do first on the building terminal to select
adequate versions and deactivate OpenMPI (does not link) building with CLang:
> $ export AUTOCONF\_VERSION=2.69 AUTOMAKE\_VERSION=1.16 CC=clang

On OpenIndiana Hipster, in order to enable OpenMPI compilation, do in a
terminal:
> $ export PATH=$PATH:/usr/lib/openmpi/gcc/bin

On OpenSUSE Linux 15.5, in order to enable OpenMPI compilation, in 64 bits version do
in a terminal:
> $ export PATH=$PATH:/usr/lib64/mpi/gcc/openmpi/bin

This software has been built and tested in the following operative systems:
* Arch Linux
* Debian Linux 12
* Devuan Linux 5
* Dragonfly BSD 6.4.0
* Fedora Linux 40
* FreeBSD 14.1
* Gentoo Linux
* Linux Mint DE 6
* MacOS Ventura + Homebrew
* Manjaro Linux
* Microsoft Windows 11 + MSYS2
* NetBSD 10.0
* OpenBSD 7.5
* OpenInidiana Hipster
* OpenSUSE Linux 15.5
* Ubuntu Linux 

Probably, it can be built in other systems, distributions, or versions but it
has not been tested

Download this repository and execute on a terminal:
> $ git clone https://github.com/jburguete/genetic.git
>
> $ cd genetic/3.0.1
>
> $ ./build.sh

FINAL VERSION
_____________

Optionally, a final compact version without debug information can be built doing
on the terminal:
> $ make strip

BUILDING IN OTHER PROGRAMS
--------------------------

To build dynamically this algorithm in other programs:

1. Build the binary code (follows the former section steps)

2. Link in your source directory the latest code version i.e.
> $ cd YOUR\_PROGRAM\_PATH
>
> $ ln -s PATH\_TO\_GENETIC/3.0.1 genetic

3. Include the genetic headers in your source code files:
> \#include "genetic/genetic.h"

4. Link the dynamic library in your source directory:
> $ ln -s genetic/libgenetic.so
   or in Windows systems:
> $ ln -s genetic/libgenetic.dll

5. Link the genetic library with your code to build the executable file i.e.
> $ gcc YOUR\_CODE.c -L. -Wl,-rpath=. -lgenetic \`pkg-config --libs gsl\`

USING THE ALGORITHM IN OTHER PROGRAMS
-------------------------------------

MAIN FUNCTION
_____________

The prototype of the main function is:

```c
int genetic_algorithm(
  unsigned int nvariables,
  GeneticVariable *variable,
  unsigned int population,
  unsigned int ngenerations,
  double mutation_ratio,
  double reproduction_ratio,
  double adaptation_ratio,
  const gsl_rng_type *type_random,
  unsigned long random_seed,
  unsigned int type_reproduction,
  unsigned int type_selection_mutation,
  unsigned int type_selection_reproduction,
  double thresold,
  double (*simulate_entity)(Entity*),
  char **best_genome,
  double **best_variables,
  double *best_objective);
```

where the parameters are:
* **nvariables**: variables number
* **genetic_variable**: array of data to define each variable. The fields of the
  data structure are:
  * *maximum*: maximum value
  * *minimum*: minimum value
  * *nbits*: number of bits to encode
* **population**: population size
* **ngenerations**: number of generations
* **mutation_ratio**: mutation probability
* **reproduction_ratio**: reproduction probability
* **adaptation_ratio**: adaptation probability
* **type_random**: type of GSL random numbers generator algorithm. See the
[GSL documentation](https://www.gnu.org/software/gsl/manual/html_node/index.html).
Valid algorithms are:
  * *gsl\_rgn\_mt19937* (default value)
  * *gsl\_rng\_taus*
  * *gsl\_rgn\_gfsr4*
  * *gsl\_rgn\_ranlxs0*
  * *gsl\_rgn\_ranlxs1*
  * *gsl\_rgn\_mrg*
  * *gsl\_rgn\_ranlux*
  * *gsl\_rgn\_ranlxd1*
  * *gsl\_rgn\_ranlxs2*
  * *gsl\_rgn\_cmrg*
  * *gsl\_rgn\_ranlux389*
  * *gsl\_rgn\_ranlxd2*
* **random\_seed**: seed to the GSL random numbers generator algorithm (0 uses
  the default GSL seed)
* **type\_reproduction**: type of reproduction algorithm. Valid values are:
  * *REPRODUCTION\_TYPE\_MIXING* (default value): the son genome is a random
    mixing between mother and father genomes in each bit
  * *REPRODUCTION\_TYPE\_SINGLEPOINTS*: the son genome is equal to mother genome
    previous to a random point and next it is equal to the father genome
  * *REPRODUCTION\_TYPE\_DOUBLEPOINTS*: the son genome is equal to father genome
    between two random points and equal to the mother genome in the rest
* **type\_selection\_mutation**: type of algorithm to select the mothers to 
  create sons with a mutation. The mutation inverts a random bit in the son
  genome. Valid values are:
  * *SELECTION\_MUTATION\_TYPE\_LINEARRANK* (default value): the mother is
    selected randomly between the survival entities assigning a linear
    probabiltiy higher for better entities
  * *SELECTION\_MUTATION\_TYPE\_RANDOM*: the mother is selected randomly between
    the survival entities
  * *SELECTION\_MUTATION\_TYPE\_BESTOF2*: the mother is the best of two randomly
    selected between the survival entities
  * *SELECTION\_MUTATION\_TYPE\_BESTOF3*: the mother is the best of three
    randomly selected between the survival entities
  * *SELECTION\_MUTATION\_TYPE\_BEST*: the mother is the best of the survival
    entities
* **type\_selection\_reproduction**: type of algorithm to select the parents to
  reproduce
* **type\_selection\_adaptation**: type of algorithm to select the mothers to
  create sons with a adaptation. An adaption inverts a random bit between the
  lowest significative bits. Valid values are:
  * *SELECTION\_ADAPTATION\_TYPE\_LINEARRANK* (default value): the mother is
    selected randomly between the survival entities assigning a linear
    probabiltiy higher for better entities
  * *SELECTION\_ADAPTATION\_TYPE\_RANDOM*: the mother is selected randomly
    between the survival entities
  * *SELECTION\_ADAPTATION\_TYPE\_BESTOF2*: the mother is the best of two
    randomly selected between the survival entities
  * *SELECTION\_ADAPTATION\_TYPE\_BESTOF3*: the mother is the best of three
    randomly selected between the survival entities
  * *SELECTION\_ADAPTATION\_TYPE\_BEST*: the mother is the best of the survival
    entities
* **thresold**: thresold in objective function to finish the simulations
* **simulate\_entity**: pointer to the function to perform each simulation
* **best\_genome**: new generated best genome
* **best\_variables**: new generated best variables array
* **best\_objective**: obtained best objective function value

CONVENIENT FUNCTION USING DEFAULT ALGORITHMS
____________________________________________

If using default algorithms is considered, the following convenient simplified
function can be used:

```c
int genetic_algorithm_default(
  unsigned int nvariables,
  GeneticVariable *variable,
  unsigned int population,
  unsigned int ngenerations,
  double mutation_ratio,
  double reproduction_ratio,
  double adaptation_ratio,
  unsigned long random_seed,
  double thresold,
  double (*simulate_entity)(Entity*),
  char **best_genome,
  double **best_variables,
  double *best_objective);
```

MAKING REFERENCE MANUAL INSTRUCTIONS (file latex/refman.pdf)
------------------------------------------------------------

Exec on a terminal:
> $ cd genetic/3.0.1
>
> $ doxygen
>
> $ cd latex
>
> $ make
