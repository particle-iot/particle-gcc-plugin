/*
 * Copyright (C) 2017 Particle Industries, Inc.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "common.h"

// GCC 5.4.x: Including this header helps to avoid some weird global name conflicts when the
// plugin API is used in C++ code
#include <locale>

// Pretend that this is a Bison parser to avoid poisoning of the malloc() function
#define YYBISON 1

#include <gcc-plugin.h>
#include <plugin-version.h>

#if GCCPLUGIN_VERSION < 5003
#error "GCC Plugin API >= 5.3.x is required to compile this code"
#endif

#include <tree.h>
#include <c-family/c-pragma.h> // For parse_in
#include <basic-block.h>
#include <tree-ssa-alias.h>
#include <gimple-expr.h>
#include <gimple.h>
#include <gimple-iterator.h>
#include <tree-pass.h>
#include <cgraph.h>
#include <context.h>
#include <diagnostic.h>

#ifndef NDEBUG

#include <print-tree.h>
#include <tree-pretty-print.h>
#include <gimple-pretty-print.h>

#endif // !defined(NDEBUG)

// Undefine dummy macros defined in safe-ctype.h
#undef isalpha
#undef isalnum
#undef iscntrl
#undef isdigit
#undef isgraph
#undef islower
#undef isprint
#undef ispunct
#undef isspace
#undef isupper
#undef isxdigit
#undef toupper
#undef tolower
