# Header
AC_PREREQ([2.69])
AC_INIT([GENETIC],[3.0.1],[jburguete@eead.csic.es])

# Checks for operative systems
AC_CANONICAL_TARGET
AM_INIT_AUTOMAKE
AC_MSG_NOTICE([Build: $build])
AC_MSG_NOTICE([Host: $host])
win=0
mac=0
native=1
if test $host = "x86_64-w64-mingw32"; then
	AC_MSG_NOTICE([Microsoft Windows 64 bits])
	CPPFLAGS="$CPPFLAGS -I/mingw/include"
	AC_SUBST(ccflags, "-march=corei7 -mfpmath=sse -msse3 -mwindows")
	win=1
	native=0
elif test $host = "i686-w64-mingw32"; then
	AC_MSG_NOTICE([Microsoft Windows 32 bits])
	CPPFLAGS="$CPPFLAGS -I/mingw/include"
	AC_SUBST(ccflags, "-march=pentium4 -mfpmath=sse -msse2 -mwindows")
	win=1
	native=0
elif test `uname -s` = "NetBSD"; then
	AC_MSG_NOTICE([NetBSD])
	LDFLAGS="$LDFLAGS -L/usr/pkg/lib"
	CPPFLAGS="$CPPFLAGS -I/usr/pkg/include"
	PATH="/usr/pkg/gcc12/bin:$PATH"
elif test `uname -s` = "DragonFly"; then
	AC_MSG_NOTICE([DragonFly BSD])
	LDFLAGS="$LDFLAGS -L/usr/local/lib"
	CPPFLAGS="$CPPFLAGS -I/usr/local/include"
elif test `uname -s` = "OpenBSD"; then
	AC_MSG_NOTICE([OpenBSD])
	native=0
elif test `uname -s ` = "Darwin"; then
	AC_MSG_NOTICE([MacOS])
	mac=1
fi
if test "x$win" = "x0"; then
	AC_SUBST(SO, [.so])
else
	AC_SUBST(SO, [.dll])
	AC_SUBST(EXE, [.exe])
fi

# Checks for programs.
AC_PROG_CC([mpicc gcc-12 gcc12 gcc-11 gcc11 gcc-10 gcc10 egcc gcc clang])
AC_MSG_NOTICE([Compiler: $CC])
$CC -v
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_LANG([C])
PKG_PROG_PKG_CONFIG
if test "`command -v gmake`"; then
	AC_SUBST(MAKE, [gmake])
else
	AC_SUBST(MAKE, [make])
fi
if test $CC = "clang" || test $mac = 1; then
	AC_SUBST(RPATH, [-rpath,])
	AC_SUBST(CLANG, [1])
	AC_CHECK_PROGS([LLVM_PROFDATA], [llvm-profdata llvm-profdata-15], 0)
	if test $LLVM_PROFDATA = 0; then
	      	AC_MSG_ERROR([No llvm-profdata])
	fi
	AC_MSG_NOTICE([llvm-profdata: $LLVM_PROFDATA])
else
	AC_SUBST(RPATH, [-rpath=])
	AC_SUBST(CLANG, [0])
fi
if test $mac = 1; then
	AC_SUBST(STRIP, "strip -x")
else
	AC_SUBST(STRIP, [strip])
fi

# Checking MPI
AC_ARG_WITH([mpi], AS_HELP_STRING([--with-mpi], [Build with MPI]))
if test "x$with_mpi" = "xyes"; then
	if test "x$CC" = "xmpicc"; then
		AC_MSG_NOTICE([checking for MPI... yes])
		AC_DEFINE([HAVE_MPI], [1])
	else
		AC_MSG_NOTICE([checking for MPI... no])
	fi
fi
	
# Checks for compiler flags
compiler=$CC

# Checking -march=native compiler flag
if test $native = 1; then
	AC_ARG_WITH([native], AS_HELP_STRING([--with-native],
		[Build using -march=native flag]))
	if test "x$with_native" = "xyes"; then
		CC="$CC -march=native"
		AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[]])], [arch=1], [arch=0])
		CC=$compiler
		if test $arch = 0; then
			AC_MSG_NOTICE([checking for -march=native... no])
		else
			AC_MSG_NOTICE([checking for -march=native... yes])
			AC_SUBST(ARCH, "-march=native")
		fi
	fi
fi

# Checking -flto compiler flag
CC="$CC -flto"
AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[]])], [lto=1], [lto=0])
CC=$compiler
if test $lto = 0; then
	AC_MSG_NOTICE([checking for -flto... no])
else
	AC_MSG_NOTICE([checking for -flto... yes])
	AC_SUBST(LTO, "-flto")
fi

# Checking PGO optimiztion
AC_ARG_WITH([pgo],
	AS_HELP_STRING([--with-pgo], [Build using PGO]))
pgo=0
if test "x$with_pgo" = "xyes"; then
	CC="$CC -fprofile-generate"
	AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[]])], [pgo=1])
	CC=$compiler
	if test $pgo = 0; then
		CC="$CC -fprofile-instr-generate"
		AC_LINK_IFELSE([AC_LANG_PROGRAM([[]], [[]])], [pgo=1])
		CC=$compiler
	fi
fi
if test $pgo = 0; then
		AC_MSG_NOTICE("checking for PGO... no")
else
		AC_MSG_NOTICE("checking for PGO... yes")
fi
AC_SUBST(PGO, [$pgo])

# Checks for libraries.
AC_CHECK_LIB([m], [sqrt])
PKG_CHECK_MODULES([GSL], [gsl])
PKG_CHECK_MODULES([GLIB], [glib-2.0])
PKG_CHECK_MODULES([GTHREAD], [gthread-2.0])

# Checks for header files.
AC_CHECK_HEADERS([string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_SIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([sqrt])

# Output
mk=Makefile.in
AC_CONFIG_SRCDIR([genetic.c])
AC_CONFIG_FILES([Makefile:$mk])
AC_OUTPUT
