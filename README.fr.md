GENETIC (version 3.0.1)
=======================

:uk:[english](README.md) :es:[español](README.es.md)
:fr:[français](README.fr.md)

Un algorithme génétique simple pour l'optimisation

AUTEURS
-------

* Javier Burguete Tolosa (jburguete@eead.csic.es)
* Borja Latorre Garcés (borja.latorre@csic.es)

FICHIERS
--------

* configure.ac: générateur de configuration
* Makefile.in: générateur du Makefile
* build.sh: script shell simplifié pour la construction
* \*.h: fichiers d'en-tête
* \*.c: fichiers source
* Doxyfile: fichier de configuration pour générer la documentation doxygen

OUTILS ET BIBLIOTHÈQUES REQUIS POUR CONSTRUIRE L'EXÉCUTABLE
-----------------------------------------------------------

* [gcc](https://gcc.gnu.org) ou [clang](http://clang.llvm.org) pour compiler le code source
* [make](http://www.gnu.org/software/make) pour construire le fichier exécutable
* [autoconf](http://www.gnu.org/software/autoconf) pour générer le Makefile sur différents systèmes d'exploitation
* [automake](http://www.gnu.org/software/automake) pour détecter le système d'exploitation
* [pkg-config](http://www.freedesktop.org/wiki/Software/pkg-config) pour trouver les bibliothèques nécessaires à la compilation
* [glib](https://developer.gnome.org/glib) utilitaires étendus de C pour travailler avec des données, listes, fichiers mappés, expressions régulières, utiliser le multiprocesseur sur des machines à mémoire partagée, ...
* [gsl](http://www.gnu.org/software/gsl) pour générer des nombres pseudo-aléatoires

OUTILS ET BIBLIOTHÈQUES OPTIONNELS
----------------------------------

* [openmpi](http://www.open-mpi.org) ou [mpich](http://www.mpich.org) pour exécuter des tâches parallélisées sur plusieurs ordinateurs
* [doxygen](http://www.stack.nl/~dimitri/doxygen) format de commentaires standard pour générer la documentation
* [latex](https://www.latex-project.org/) pour construire les manuels PDF

CONSTRUIRE LES FICHIERS BINAIRES
--------------------------------

Sur Fedora Linux 42, pour utiliser la compilation avec OpenMPI, exécutez dans un terminal (version 64 bits):
> $ export PATH=$PATH:/usr/lib64/openmpi/bin
avec MPICH (version 64 bits):
> $ export PATH=$PATH:/usr/lib64/mpich/bin

Sur les systèmes Microsoft Windows, il faut installer [MSYS2](http://sourceforge.net/projects/msys2) avec les bibliothèques et utilitaires requis. Vous pouvez suivre les instructions détaillées dans [install-unix](https://github.com/jburguete/install-unix/blob/master/tutorial.pdf)

Sur NetBSD 10.1, pour compiler avec la dernière version du compilateur GCC, il faut d'abord exécuter dans le terminal de construction:
> $ export PATH=/usr/pkg/gcc9/bin:$PATH

Sur OpenBSD 7.7, il faut d'abord exécuter dans le terminal de construction pour sélectionner les versions appropriées:
> $ export AUTOCONF\_VERSION=2.69 AUTOMAKE\_VERSION=1.16

Sur OpenIndiana Hipster, pour activer la compilation avec OpenMPI, exécutez dans le terminal de construction:
> $ export PATH=$PATH:/usr/lib/openmpi/gcc/bin

Sur OpenSUSE Linux 15.6, pour activer la compilation avec OpenMPI, exécutez dans le terminal de construction (version 64 bits):
> $ export PATH=$PATH:/usr/lib64/mpi/gcc/openmpi/bin

Cette bibliothèque a été construite et testée sur les systèmes d'exploitation suivants:
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
* OpenIndiana Hipster
* OpenSUSE Linux 15.6
* Ubuntu Linux 25.04

Elle peut probablement être construite sur d'autres systèmes, distributions ou versions, mais n'a pas été testée.

Téléchargez ce dépôt et exécutez dans un terminal:
> $ git clone https://github.com/jburguete/genetic.git
>
> $ cd genetic/3.0.1
>
> $ ./build.sh

VERSION FINALE
______________

Optionnellement, vous pouvez construire une version finale compacte sans informations de débogage en exécutant dans le terminal:
> $ make strip

LIER À D'AUTRES PROGRAMMES
---------------------------

Pour lier dynamiquement cet algorithme à d'autres programmes:

1. Construisez le code binaire en suivant les instructions de la section précédente.

2. Liez dans votre dossier source la dernière version du code, par exemple:
> $ cd CHEMIN\_VERS\_VOTRE\_PROGRAMME
>
> $ ln -s CHEMIN\_VERS\_GENETIC/3.0.1 genetic

3. Incluez les en-têtes de genetic dans vos fichiers de code source:
> \#include "genetic/genetic.h"

4. Liez la bibliothèque dynamique dans votre dossier source:
> $ ln -s genetic/libgenetic.so
   ou sur les systèmes Windows:
> $ ln -s genetic/libgenetic.dll

5. Liez la bibliothèque genetic avec votre code pour construire le fichier exécutable, par exemple:
> $ gcc VOTRE\_CODE.c -L. -Wl,-rpath=. -lgenetic \`pkg-config --libs gsl\`

UTILISER L'ALGORITHME DANS D'AUTRES PROGRAMMES
----------------------------------------------

FONCTION PRINCIPALE
__________________

Le prototype de la fonction principale est:

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

où les paramètres sont:
* **nvariables**: nombre de variables
* **genetic_variable**: vecteur de données pour définir chaque variable. Les champs de chaque structure de données sont:
  * *maximum*: valeur maximale
  * *minimum*: valeur minimale
  * *nbits*: nombre de bits à encoder
* **population**: taille de la population
* **ngenerations**: nombre de générations
* **mutation_ratio**: probabilité de mutation
* **reproduction_ratio**: probabilité de reproduction
* **adaptation_ratio**: probabilité d'adaptation
* **type_random**: type d'algorithme GSL générateur de nombres aléatoires. Voir [GSL documentation](https://www.gnu.org/software/gsl/manual/html_node/index.html). Les algorithmes valides sont:
  * *gsl\_rgn\_mt19937* (valeur par défaut)
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
* **random\_seed**: graine de l'algorithme GSL générateur de nombres aléatoires (0 utilise la valeur par défaut de GSL)
* **type\_reproduction**: type d'algorithme de reproduction. Les valeurs valides sont:
  * *REPRODUCTION\_TYPE\_MIXING* (valeur par défaut): le génome enfant est un mélange aléatoire entre les génomes mère et père pour chaque bit
  * *REPRODUCTION\_TYPE\_SINGLEPOINTS*: le génome enfant est égal au génome mère jusqu'à un point aléatoire et ensuite égal au génome père
  * *REPRODUCTION\_TYPE\_DOUBLEPOINTS*: le génome enfant est égal au génome père entre deux points aléatoires et égal au génome mère pour le reste
* **type\_selection\_mutation**: type d'algorithme pour sélectionner les mères pour générer des enfants avec une mutation. La mutation inverse un bit aléatoire dans le génome enfant. Les valeurs valides sont:
  * *SELECTION\_MUTATION\_TYPE\_LINEARRANK* (valeur par défaut): la mère est sélectionnée aléatoirement parmi la population survivante en attribuant une probabilité linéairement plus grande aux meilleurs individus
  * *SELECTION\_MUTATION\_TYPE\_RANDOM*: la mère est sélectionnée aléatoirement parmi les individus survivants
  * *SELECTION\_MUTATION\_TYPE\_BESTOF2*: la mère est la meilleure parmi deux individus sélectionnés aléatoirement
  * *SELECTION\_MUTATION\_TYPE\_BESTOF3*: la mère est la meilleure parmi trois individus sélectionnés aléatoirement
  * *SELECTION\_MUTATION\_TYPE\_BEST*: la mère est la meilleure parmi les individus survivants
* **type\_selection\_reproduction**: type d'algorithme pour sélectionner les ancêtres à reproduire
* **type\_selection\_adaptation**: type d'algorithme pour sélectionner les mères qui créent des enfants avec une adaptation. L'adaptation inverse un bit aléatoire parmi les bits les moins significatifs. Les valeurs valides sont:
  * *SELECTION\_ADAPTATION\_TYPE\_LINEARRANK* (valeur par défaut): la mère est sélectionnée aléatoirement parmi la population survivante en attribuant une probabilité linéairement plus grande aux meilleurs individus
  * *SELECTION\_ADAPTATION\_TYPE\_RANDOM*: la mère est sélectionnée aléatoirement parmi les individus survivants
  * *SELECTION\_ADAPTATION\_TYPE\_BESTOF2*: la mère est la meilleure parmi deux individus sélectionnés aléatoirement
  * *SELECTION\_ADAPTATION\_TYPE\_BESTOF3*: la mère est la meilleure parmi trois individus sélectionnés aléatoirement
  * *SELECTION\_ADAPTATION\_TYPE\_BEST*: la mère est la meilleure parmi les individus survivants
* **thresold**: seuil dans la fonction objectif pour terminer les simulations
* **simulate\_entity**: pointeur vers la fonction pour effectuer chaque simulation
* **best\_genome**: meilleur génome de la nouvelle génération
* **best\_variables**: vecteur des meilleures variables de la nouvelle génération
* **best\_objective**: meilleure valeur obtenue de la fonction objectif

FONCTION PRATIQUE UTILISANT LES ALGORITHMES PAR DÉFAUT
_______________________________________________________

Si vous souhaitez utiliser les algorithmes par défaut, vous pouvez utiliser la fonction pratique simplifiée suivante:

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

INSTRUCTIONS POUR CONSTRUIRE LE MANUEL DE RÉFÉRENCE (fichier latex/refman.pdf)
-----------------------------------------------------------------------------

Exécutez dans un terminal :
> $ cd genetic/3.0.1
>
> $ doxygen
>
> $ cd latex
>
> $ make
