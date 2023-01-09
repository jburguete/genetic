GENETIC (versión 3.0.1)
=======================

:uk:[english](README.md) :es:[español](README.es.md)

Un algoritmo genético simple para optimización

AUTORES
-------

* Javier Burguete Tolosa (jburguete@eead.csic.es)
* Borja Latorre Garcés (borja.latorre@csic.es)

FICHEROS
--------

* configure.ac: generador de configurarción
* Makefile.in: generador del Makefile
* build.sh: shell script simplificado de construcción
* \*.h: ficheros de cabecera
* \*.c: ficheros fuente
* Doxyfile: fichero de configuración para generar la documentación doxygen

UTILIDADES Y BIBLIOTECAS REQUERIDAS PARA CONSTRUIR EL EJECUTABLE
----------------------------------------------------------------

* [gcc](https://gcc.gnu.org) o [clang](http://clang.llvm.org) para compilar el
  código fuente
* [make](http://www.gnu.org/software/make) para construir el fichero ejecutable
* [autoconf](http://www.gnu.org/software/autoconf) para generar el Makefile en
  diferentes sistemas operativos
* [automake](http://www.gnu.org/software/automake) para detectar el sistema
  operativo
* [pkg-config](http://www.freedesktop.org/wiki/Software/pkg-config) para
  encontrar las bibliotecas para compilar
* [glib](https://developer.gnome.org/glib) utilidades extendidas de C para
  trabajar con datos, listas, ficheros mapeados, expresiones regulares, usar
  multiprocesador en máquinas de memoria compartida, ...
* [gsl](http://www.gnu.org/software/gsl) para generar números pseudo-aleatorios

UTILIDADES Y BIBLIOTECAS OPCIONALES
-----------------------------------

* [openmpi](http://www.open-mpi.org) o [mpich](http://www.mpich.org) para
  ejecutarse en tareas paralelizadas en múltiples computadoras
* [doxygen](http://www.stack.nl/~dimitri/doxygen) formato de comentarios
  estándar para generar documentación
* [latex](https://www.latex-project.org/) para construir los manuales PDF

CONSTRUIR LOS FICHEROS BINARIOS
-------------------------------

En Fedora Linux 37, para usar compilación con OpenMPI, haga en un terminal (en
la versión de 64 bits):
> $ export PATH=$PATH:/usr/lib64/openmpi/bin
con MPICH (en la versión de 64 bits):
> $ export PATH=$PATH:/usr/lib64/mpich/bin

En sistemas Microsoft Windows hay que instalar
[MSYS2](http://sourceforge.net/projects/msys2) con las biliotecas y utilidades
requeridas. Puede seguir las instrucciones detalladas en
[install-unix](https://github.com/jburguete/install-unix/blob/master/tutorial.pdf)

En NetBSD 9.3, para compilar con la última versión del compilador GCC hay que
hacer primero en el terminal de construcción:
> $ export PATH=/usr/pkg/gcc9/bin:$PATH"

En OpenBSD 7.2 hay que hacer primero en el terminal de construcción para
seleccionar versiones adecuadas:
> $ export AUTOCONF\_VERSION=2.69 AUTOMAKE\_VERSION=1.16

En OpenIndiana Hipster, para activar la compilación con OpenMPI, haga en el
terminal de construcción:
> $ export PATH=$PATH:/usr/lib/openmpi/gcc/bin

En OpenSUSE Linux 15.4, para activar la compilación con OpenMPI, haga en el
terminal de construcción (en la versión de 64 bits):
> $ export PATH=$PATH:/usr/lib64/mpi/gcc/openmpi/bin

Esta biblioteca ha sido construida y probada en los siguientes sistemas
operativos:
* Arch Linux
* Debian Linux 11
* Devuan Linux 4
* Dragonfly BSD 6.4
* Fedora Linux 37
* FreeBSD 13.1
* Gentoo Linux
* Linux Mint DE 5
* Manjaro Linux
* Microsoft Windows 10 + MSYS2
* NetBSD 9.3
* OpenBSD 7.2
* OpenInidiana Hipster
* OpenSUSE Linux 15.4
* Ubuntu Linux 22.10

Probablemente puede construirse en otros sistemas, distribuciones o versiones
pero no ha sido probada

Descárgese este repositorio y ejecute en un terminal:
> $ git clone https://github.com/jburguete/genetic.git
>
> $ cd genetic/3.0.1
>
> $ sh build.sh

VERSIÓN FINAL
_____________

Opcionalmente, se puede construir una versión final compacta sin información de
depuración haciendo en el terminal:
> $ make strip

ENLAZANDO EN OTROS PROGRAMAS
----------------------------

Para enlazar dinámicamente este algoritmo en otros programas:

1. Construa el código binario siguiendo las intrucciones de la sección anterior

2. Enlace en su carpeta fuente la última versión del código, p. ej:
> $ cd RUTA\_A\_SU\_PROGRAMA
>
> $ ln -s RUTA\_A\_GENETIC/3.0.1 genetic

3. Incluya las cabeceras de genetic en sus ficheros de código fuente:
> \#include "genetic/genetic.h"

4. Enlace la bibloteca dinámica en su carpeta fuente:
> $ ln -s genetic/libgenetic.so
   o en sistemas Windows:
> $ ln -s genetic/libgenetic.dll

5. Enlace la biblioteca genetic con su código para construir el fichero
   ejecutable, p. ej:
> $ gcc SU\_CÓDIGO.c -L. -Wl,-rpath=. -lgenetic \`pkg-config --libs gsl\`

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
  create sons with a mutation. A mutation inverts a random bit in the genome.
  Valid values are:
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

INSTRUCCIONES PARA CONSTRUIR EL MANUAL DE REFERENCIA (fichero latex/refman.pdf)
-------------------------------------------------------------------------------

Ejeecute en un terminal:
> $ cd genetic/3.0.1
>
> $ doxygen
>
> $ cd latex
>
> $ make
