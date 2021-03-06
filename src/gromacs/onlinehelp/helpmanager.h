/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 2012- The GROMACS Authors
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
/*! \libinternal \file
 * \brief
 * Declares gmx::HelpManager.
 *
 * \author Teemu Murtola <teemu.murtola@gmail.com>
 * \inlibraryapi
 * \ingroup module_onlinehelp
 */
#ifndef GMX_ONLINEHELP_HELPMANAGER_H
#define GMX_ONLINEHELP_HELPMANAGER_H

#include <memory>
#include <string>

namespace gmx
{

class HelpWriterContext;
class IHelpTopic;

/*! \libinternal \brief
 * Helper for providing interactive online help.
 *
 * \inlibraryapi
 * \ingroup module_onlinehelp
 */
class HelpManager
{
public:
    /*! \brief
     * Creates a manager that uses a given root topic.
     *
     * \param[in] rootTopic  Help topic that can be accessed through this
     *      manager.
     * \param[in] context    Context object for writing the help.
     * \throws    std::bad_alloc if out of memory.
     *
     * The provided topic and context objects must remain valid for the
     * lifetime of this manager object.
     */
    HelpManager(const IHelpTopic& rootTopic, const HelpWriterContext& context);
    ~HelpManager();

    /*! \brief
     * Enters a subtopic with the given name under the active topic.
     *
     * \param[in] name  Subtopic name to enter.
     * \throws    std::bad_allod if out of memory.
     * \throws    InvalidInputError if topic with \p name is not found.
     */
    void enterTopic(const char* name);
    //! \copydoc enterTopic(const char *)
    void enterTopic(const std::string& name);

    /*! \brief
     * Writes out the help for the currently active topic.
     *
     * \throws  std::bad_alloc if out of memory.
     * \throws  FileIOError on any I/O error.
     */
    void writeCurrentTopic() const;

private:
    class Impl;

    std::unique_ptr<Impl> impl_;
};

} // namespace gmx

#endif
