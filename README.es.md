GENETIC (versión 3.0.1)
=======================

:uk:[english](README.md) :es:[español](README.es.md)
:fr:[français](README.fr.md)

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

En Fedora Linux 42, para usar compilación con OpenMPI, haga en un terminal (en
la versión de 64 bits):
> $ export PATH=$PATH:/usr/lib64/openmpi/bin
con MPICH (en la versión de 64 bits):
> $ export PATH=$PATH:/usr/lib64/mpich/bin

En sistemas Microsoft Windows hay que instalar
[MSYS2](http://sourceforge.net/projects/msys2) con las biliotecas y utilidades
requeridas. Puede seguir las instrucciones detalladas en
[install-unix](https://github.com/jburguete/install-unix/blob/master/tutorial.pdf)

En NetBSD 10.1, para compilar con la última versión del compilador GCC hay que
hacer primero en el terminal de construcción:
> $ export PATH=/usr/pkg/gcc9/bin:$PATH"

En OpenBSD 7.7 hay que hacer primero en el terminal de construcción para
seleccionar versiones adecuadas:
> $ export AUTOCONF\_VERSION=2.69 AUTOMAKE\_VERSION=1.16

En OpenIndiana Hipster, para activar la compilación con OpenMPI, haga en el
terminal de construcción:
> $ export PATH=$PATH:/usr/lib/openmpi/gcc/bin

En OpenSUSE Linux 15.6, para activar la compilación con OpenMPI, haga en el
terminal de construcción (en la versión de 64 bits):
> $ export PATH=$PATH:/usr/lib64/mpi/gcc/openmpi/bin

Esta biblioteca ha sido construida y probada en los siguientes sistemas
operativos:
* Arch Linux
* Debian Linux 12
* Devuan Linux 5
* Dragonfly BSD 6.4.1
* Fedora Linux 42
* FreeBSD 14.2
* Gentoo Linux
* Linux Mint DE 6
* MacOS Ventura + Homebrew
* Manjaro Linux
* Microsoft Windows 11 + MSYS2
* NetBSD 10.1
* OpenBSD 7.7
* OpenInidiana Hipster
* OpenSUSE Linux 15.6
* Ubuntu Linux 25.04

Probablemente puede construirse en otros sistemas, distribuciones o versiones
pero no ha sido probada

Descárgese este repositorio y ejecute en un terminal:
> $ git clone https://github.com/jburguete/genetic.git
>
> $ cd genetic/3.0.1
>
> $ ./build.sh

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

USANDO EL ALGORITMO EN OTROS PROGRAMAS
-------------------------------------

FUNCIÓN PRINCIPAL
_____________

El prototipo de la función principal es:

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

donde los parámetros son:
* **nvariables**: número de variables
* **genetic_variable**: vector de datos para definir cada variable. Los campos
  de cada estructura de datos son:
  * *maximum*: valor máximo
  * *minimum*: valor mínimo
  * *nbits*: número de bits a codificar
* **population**: tamaño de la población
* **ngenerations**: número de generaciones
* **mutation_ratio**: probabilidad de mutación
* **reproduction_ratio**: probabilidad de reproducción
* **adaptation_ratio**: probabilidad de adaptación
* **type_random**: tipo de algoritmo GSL generador de números aleatorios. Véase
  [GSL documentation](https://www.gnu.org/software/gsl/manual/html_node/index.html).
  Algoritmos válidos son:
  * *gsl\_rgn\_mt19937* (valor por defecto)
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
* **random\_seed**: semilla del algoritmo GSL generador de números aletorios (0
  usa el valor por defecto de GSL)
* **type\_reproduction**: tipo de algoritmo de reproducción. Son valores
  válidos:
  * *REPRODUCTION\_TYPE\_MIXING* (valor por defecto): el genoma hijo es una
    mezcla aleatoria entre los genomas madre y padre en cada bit
  * *REPRODUCTION\_TYPE\_SINGLEPOINTS*: el genoma hijo es igual al genoma madre
    hasta un punto aleatorio y a partir de ahí igual al genoma padre
  * *REPRODUCTION\_TYPE\_DOUBLEPOINTS*: el genoma hijo es igual al genoma padre
    entre dos puntos aleatorios e igual al genoma madre en el resto
* **type\_selection\_mutation**: tipo de algoritmo para seleccionar las madres
  para generar hijos con una mutación. La mutación invierte un bit aleatorio en
  el genoma hijo. Son valores válidos:
  * *SELECTION\_MUTATION\_TYPE\_LINEARRANK* (valor por defecto): la madre se
    selecciona aleatoriamente entre la población superviviente asignando una
    probabilidad linealmente mayor para los mejores individuos
  * *SELECTION\_MUTATION\_TYPE\_RANDOM*: la madre se selecciona aleatoriamente
    entre los individuos supervivientes
  * *SELECTION\_MUTATION\_TYPE\_BESTOF2*: la madre es la mejor entre dos
    individuos seleccionados aleatoriamente
  * *SELECTION\_MUTATION\_TYPE\_BESTOF3*: la madre es la mejor entre tres
    individuos seleccionados aleatoriamente
  * *SELECTION\_MUTATION\_TYPE\_BEST*: la madre es la mejor de los individuos
    supervivientes
* **type\_selection\_reproduction**: tipo de algoritmo para seleccionar los
  ancestros a reproducir
* **type\_selection\_adaptation**: tipo de algoritmo para seleccionar madres que
  creen hijos con una adaptación. La adaptación invierte un bit aleatorio entre
  los bits menos significativos. Son valores válidos:
  * *SELECTION\_ADAPTATION\_TYPE\_LINEARRANK* (valor por defecto): la madre se
    selecciona aleatoriamente entre la población superviviente asignando una
    probabilidad linealmente mayor para los mejores individuos
  * *SELECTION\_ADAPTATION\_TYPE\_RANDOM*: the mother is selected randomly
    between the survival entities
  * *SELECTION\_ADAPTATION\_TYPE\_RANDOM*: la madre se selecciona aleatoriamente
    entre los individuos supervivientes
  * *SELECTION\_ADAPTATION\_TYPE\_BESTOF2*: la madre es la mejor entre dos
    individuos seleccionados aleatoriamente
  * *SELECTION\_ADAPTATION\_TYPE\_BESTOF3*: la madre es la mejor entre tres
    individuos seleccionados aleatoriamente
  * *SELECTION\_ADAPTATION\_TYPE\_BEST*: la madre es la mejor de los individuos
    supervivientes
* **thresold**: umbral en la función objetivo para finalizar las simulaciones
* **simulate\_entity**: puntero a la función para realizar cada simulación
* **best\_genome**: mejor genoma de la nueva generación
* **best\_variables**: vector de las mejores variables de la nueva generación
* **best\_objective**: valor mejor obtenido de la función objetivo

FUNCIÓN CONVENIENTE USANDO ALGORITMOS POR DEFECTO
_________________________________________________

Si se considera usar los algoritmos por defecto, se puede usar la siguiente
función conveniente simplificada:

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
