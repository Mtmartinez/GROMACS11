/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 2010- The GROMACS Authors
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
/*! \internal \file
 * \brief Declarations for memory pooling functions.
 *
 * \todo
 * Document these functions.
 *
 * This is an implementation header: there should be no need to use it outside
 * this directory.
 *
 * \author Teemu Murtola <teemu.murtola@gmail.com>
 * \ingroup module_selection
 */
#ifndef GMX_SELECTION_MEMPOOL_H
#define GMX_SELECTION_MEMPOOL_H

#include <cstddef>

struct gmx_ana_index_t;

/** Opaque struct for memory pooling. */
typedef struct gmx_sel_mempool_t gmx_sel_mempool_t;

/** Create an empty memory pool. */
gmx_sel_mempool_t* _gmx_sel_mempool_create();
/** Destroy a memory pool. */
void _gmx_sel_mempool_destroy(gmx_sel_mempool_t* mp);

/** Allocate memory from a memory pool. */
void* _gmx_sel_mempool_alloc(gmx_sel_mempool_t* mp, size_t size);
/** Release memory allocated from a memory pool. */
void _gmx_sel_mempool_free(gmx_sel_mempool_t* mp, void* ptr);
/** Set the size of a memory pool. */
void _gmx_sel_mempool_reserve(gmx_sel_mempool_t* mp, size_t size);

/** Convenience function for allocating an index group from a memory pool. */
void _gmx_sel_mempool_alloc_group(gmx_sel_mempool_t* mp, struct gmx_ana_index_t* g, int isize);
/** Convenience function for freeing an index group from a memory pool. */
void _gmx_sel_mempool_free_group(gmx_sel_mempool_t* mp, struct gmx_ana_index_t* g);

#endif
