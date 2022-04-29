/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 2014- The GROMACS Authors
 * and the project initiators Erik Lindahl, Berk Hess and David van der Spoel.
 * Consult the AUTHORS/COPYING files and https://www.gromacs.org for details.
 *
 * GROMACS is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1
 * of the License, or (at your option) any later version.
 *
 * GROMACS is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with GROMACS; if not, see
 * https://www.gnu.org/licenses, or write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA.
 *
 * If you want to redistribute modifications to GROMACS, please
 * consider that scientific software is very special. Version
 * control is crucial - bugs must be traceable. We will be happy to
 * consider code for inclusion in the official distribution, but
 * derived work must not be called official GROMACS. Details are found
 * in the README & COPYING files - if they are missing, get the
 * official version at https://www.gromacs.org.
 *
 * To help us fund GROMACS development, we humbly ask that you cite
 * the research papers on the package. Check out https://www.gromacs.org.
 */

#ifndef GMX_SIMD_IMPLEMENTATION_IBM_VSX_H
#define GMX_SIMD_IMPLEMENTATION_IBM_VSX_H

// At high optimization levels, gcc 7.2 gives false
// positives.
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"

// While we do our best to also test VSX with Power7, that depends on having
// access to big-endian hardware, so for the long term our focus will be
// little-endian Power8.

#include "impl_ibm_vsx_definitions.h"
#include "impl_ibm_vsx_general.h"
#include "impl_ibm_vsx_simd4_float.h"
#include "impl_ibm_vsx_simd_double.h"
#include "impl_ibm_vsx_simd_float.h"
#include "impl_ibm_vsx_util_double.h"
#include "impl_ibm_vsx_util_float.h"

#pragma GCC diagnostic pop

#endif // GMX_SIMD_IMPLEMENTATION_IBM_VSX_H
