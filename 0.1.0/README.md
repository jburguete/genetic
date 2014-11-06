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
* doxygen (optional: standard comments format to generate documentation)
* latex (optional: to build the PDF manual)

FILES
-----

* configure.ac: configure generator.
* Makefile.in: Makefile generator.
* TODO: List of tasks TO DO (in spanish)
* src/*.h: Header files.
* src/*.c: Source files.
* Doxyfile: configuration file to generate doxygen documentation.

BUILDING INSTRUCTIONS
---------------------

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

OpenBSD 5.5
___________

* export AUTOCONF_VERSION=2.69 AUTOMAKE_VERSION=1.14
* cd 0.1.0
* aclocal
* autoconf
* automake --add-missing
* ./configure
* make

MAKING REFERENCE MANUAL INSTRUCTIONS
------------------------------------

* cd 0.1.0
* doxygen
* cd doc/latex
* make
