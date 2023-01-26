#!/usr/bin/env bash
if [[ $# != 4 ]]; then
	echo "The syntax is: ./build.sh A B C D"
	echo "A: 1 on MPI"
	echo "B: 1 on native"
	echo "C: 1 on PGO"
	echo "D: 1 on strip"
	exit 1
fi
if [[ $1 = 1 ]]; then
	a1="--with-mpi"
fi
if [[ $2 = 1 ]]; then
	a2="--with-native"
fi
if [[ $3 = 1 ]]; then
	a3="--with-pgo"
fi
if [[ $4 = 1 ]]; then
	a4="strip"
fi
aclocal
autoconf
automake --add-missing
./configure $a1 $a2 $a3
if test -x "`command -v gmake`"; then
	gmake $a4
else
	make $a4
fi
