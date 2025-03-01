/* Definitions of target machine for GNU compiler, for HPs using the
   64bit runtime model.
   Copyright (C) 1999-2025 Free Software Foundation, Inc.

This file is part of GCC.

GCC is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 3, or (at your option)
any later version.

GCC is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with GCC; see the file COPYING3.  If not see
<http://www.gnu.org/licenses/>.  */

/* The default sizes for basic datatypes provided by GCC are not
   correct for the PA64 runtime architecture.

   In PA64, basic types have the following sizes

     char	1 byte
     short	2 bytes
     int	4 bytes
     long	8 bytes
     long long	8 bytes
     pointer	8 bytes
     float	4 bytes
     double	8 bytes
     long double 16 bytes
     size_t	8 bytes
     ptrdiff_t	8 bytes
     wchar	4 bytes

  Make GCC agree with types.h.  */
#undef SIZE_TYPE
#define SIZE_TYPE "long unsigned int"

#undef PTRDIFF_TYPE
#define PTRDIFF_TYPE "long int"

#undef WCHAR_TYPE
#define WCHAR_TYPE "unsigned int"

#undef WCHAR_TYPE_SIZE
#define WCHAR_TYPE_SIZE 32

/* If it is not listed here, then the default selected by GCC is OK.  */
#undef SHORT_TYPE_SIZE
#define SHORT_TYPE_SIZE 16
#undef INT_TYPE_SIZE
#define INT_TYPE_SIZE 32
#undef LONG_TYPE_SIZE
#define LONG_TYPE_SIZE 64
#undef LONG_LONG_TYPE_SIZE
#define LONG_LONG_TYPE_SIZE 64
#undef PA_FLOAT_TYPE_SIZE
#define PA_FLOAT_TYPE_SIZE 32
#undef PA_DOUBLE_TYPE_SIZE
#define PA_DOUBLE_TYPE_SIZE 64
#undef PA_LONG_DOUBLE_TYPE_SIZE
#define PA_LONG_DOUBLE_TYPE_SIZE 128

/* ?!? This needs to be made compile-time selectable.

   The PA64 runtime model has arguments that grow to higher addresses
   (like most other targets).  The older runtime model has arguments
   that grow to lower addresses.  What fun.  */
#undef ARGS_GROW_DOWNWARD

/* If defined, a C expression which determines whether the default
   implementation of va_arg will attempt to pad down before reading the
   next argument, if that argument is smaller than its aligned space as
   controlled by PARM_BOUNDARY.  If this macro is not defined, all such
   arguments are padded down when BYTES_BIG_ENDIAN is true.  We don't
   want aggregates padded down.  */

#define PAD_VARARGS_DOWN \
  (!AGGREGATE_TYPE_P (type) \
   && TREE_CODE (type) != COMPLEX_TYPE \
   && TREE_CODE (type) != VECTOR_TYPE)

/* In the PA architecture, it is not possible to directly move data
   between GENERAL_REGS and FP_REGS.  On the 32-bit port, we use the
   location at SP-16 because PA 1.X only supports 5-bit immediates for
   floating-point loads and stores.  We don't expose this location in
   the RTL to avoid scheduling related problems.  For example, the
   store and load could be separated by a call to a pure or const
   function which has no frame and this function might also use SP-16.

   On the 64-bit port, I couldn't get SECONDARY_MEMORY_NEEDED to work
   with LRA, so I modified the move patterns to use SP-40.  The HP
   compiler also uses this slot in the frame marker for moving data
   between the general and floating-point registers.  */
#define PA_SECONDARY_MEMORY_NEEDED(MODE, CLASS1, CLASS2) false
