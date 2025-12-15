#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([number game], [1.0], [example@example.com], [numbergame])
AC_CONFIG_SRCDIR([src/numbergame.c])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([foreign subdir-objects])

DX_INIT_DOXYGEN([numbergame], [Doxyfile], [docs])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([libintl.h])
AC_CHECK_HEADERS([locale.h stdlib.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_FUNCS([setlocale strcspn])
AC_CONFIG_FILES([Makefile Doxyfile])

AC_OUTPUT
