/* This testcase is part of GDB, the GNU debugger.

   Copyright 2013-2016 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

#include "trace-common.h"

int
main(void)
{
  /* Note: 'volatile' is used to make sure the compiler doesn't
     optimize out these variables.  We want to be sure instructions
     are generated for accesses.  */
  volatile int i = 0;

  /* Generate a single line with a label in the middle where we can
     place either a trap tracepoint or a fast tracepoint.  */
#define LINE_WITH_FAST_TRACEPOINT					\
  do {									\
    i = 1;								\
    FAST_TRACEPOINT_LABEL(set_point);					\
    i = 2;								\
 } while (0)

  LINE_WITH_FAST_TRACEPOINT; /* location 1 */

  return 0;
}
