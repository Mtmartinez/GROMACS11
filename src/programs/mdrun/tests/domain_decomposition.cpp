/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 2015- The GROMACS Authors
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
 * \brief
 * Tests special cases in domain decomposition
 *
 * \author Mark Abraham <mark.j.abraham@gmail.com>
 * \ingroup module_mdrun_integration_tests
 */
#include "gmxpre.h"

#include <string>

#include <gtest/gtest.h>

#include "testutils/cmdlinetest.h"

#include "moduletest.h"

namespace
{

//! Test fixture for domain decomposition special cases
class DomainDecompositionSpecialCasesTest : public gmx::test::MdrunTestFixture
{
};

//! When run with 2+ domains, ensures an empty cell, to make sure that zero-sized things work
TEST_F(DomainDecompositionSpecialCasesTest, AnEmptyDomainWorks)
{
    runner_.useStringAsMdpFile("cutoff-scheme = Verlet\n");
    runner_.useTopGroAndNdxFromDatabase("spc2");
    /* Over-ride the use of spc2.gro with one with both waters close
     * together.
     *
     * TODO Maybe refactor to avoid over-writing the .gro filename set
     * above. */
    runner_.useGroFromDatabase("spc2_and_vacuum");
    ASSERT_EQ(0, runner_.callGrompp());

    ASSERT_EQ(0, runner_.callMdrun());
}

} // namespace
