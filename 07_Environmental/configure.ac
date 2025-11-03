#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.71])
AC_INIT([rhasher], [0.01], [example@mail.com])
AC_CONFIG_SRCDIR([src/rhasher.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_INIT_AUTOMAKE

# Checks for libraries.
AC_CHECK_LIB([rhash],[rhash_library_init],[],[AC_MSG_ERROR([librhash is required])])
AC_CHECK_LIB([readline],[readline])

# Checks for header files.
AC_CHECK_HEADER([rhash.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T

# Checks for library functions.
AC_CHECK_FUNCS([strcasecmp strerror])

# Optional
AC_ARG_ENABLE([readline],
    AS_HELP_STRING([--enable-readline], [Enable readline input]),
    AC_DEFINE(USE_READLINE,[],[readline input])
  )

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
