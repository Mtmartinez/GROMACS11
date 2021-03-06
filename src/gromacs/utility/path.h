/*
 * This file is part of the GROMACS molecular simulation package.
 *
 * Copyright 2011- The GROMACS Authors
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
 * Declares functions for OS-independent path handling.
 *
 * \author Teemu Murtola <teemu.murtola@gmail.com>
 * \inlibraryapi
 * \ingroup module_utility
 */
#ifndef GMX_UTILITY_PATH_H
#define GMX_UTILITY_PATH_H

#include <string>
#include <string_view>
#include <utility>
#include <vector>

namespace gmx
{

class Path
{
public:
    static bool containsDirectory(const std::string& path);
    static bool isAbsolute(const char* path);
    static bool isAbsolute(const std::string& path);
    static bool isEquivalent(const std::string& path1, const std::string& path2);

    static std::string join(const std::string& path1, const std::string& path2);
    static std::string join(const std::string& path1, const std::string& path2, const std::string& path3);
    //! Return a path using directory separators that suit the execution OS.
    static std::string normalize(const std::string& path);
    /*! \brief Returns a copy of the parent path (ie. directory
     * components) of \c input ie. up to but excluding the last
     * directory separator (if one exists).
     *
     * \returns A copy of the parent path-components, or empty if
     * no directory separator exists. */
    static std::string getParentPath(const std::string& input);
    /*! \brief Returns a copy of the filename in \c input
     * ie. after the last directory separator (if one exists). */
    static std::string getFilename(const std::string& input);
    //! Returns whether an extension is present in \c input.
    static bool hasExtension(const std::string& input);
    /*! \brief Returns whether the extension present in \c input
     * matches \c extension (which does not include the separator
     * character). */
    static bool extensionMatches(std::string_view input, std::string_view extension);
    /*! \brief Returns a copy of the input without any trailing
     * extension found in the filename component. */
    static std::string stripExtension(const std::string& input);
    /*! \brief Concatenate \c stringToAdd to a copy of \c input,
     * before any file extension (if one exists), and return the
     * result. */
    static std::string concatenateBeforeExtension(const std::string& input, const std::string& stringToAdd);

    static const char* stripSourcePrefix(const char* path);

    static bool        exists(const char* path);
    static bool        exists(const std::string& path);
    static std::string getWorkingDirectory();

    static void splitPathEnvironment(const std::string& pathEnv, std::vector<std::string>* result);
    static std::vector<std::string> getExecutablePaths();

    static std::string resolveSymlinks(const std::string& path);

private:
    // Disallow instantiation.
    Path();
};

class File
{
public:
    struct NotFoundInfo
    {
        NotFoundInfo(const char* filename, const char* message, const char* call, bool wasError, int err) :
            filename(filename), message(message), call(call), wasError(wasError), err(err)
        {
        }

        const char* filename;
        const char* message;
        const char* call;
        bool        wasError;
        int         err;
    };

    static void              returnFalseOnError(const NotFoundInfo& info);
    static void              throwOnError(const NotFoundInfo& info);
    [[noreturn]] static void throwOnNotFound(const NotFoundInfo& info);

    typedef void (*NotFoundHandler)(const NotFoundInfo& info);

    /*! \brief
     * Checks whether a file exists and is a regular file.
     *
     * \param[in] filename    Path to the file to check.
     * \param[in] onNotFound  Function to call when the file does not
     *     exists or there is an error accessing it.
     * \returns   `true` if \p filename exists and is accessible.
     *
     * Does not throw, unless onNotFound throws.
     */
    static bool exists(const char* filename, NotFoundHandler onNotFound);
    //! \copydoc exists(const char *, NotFoundHandler)
    static bool exists(const std::string& filename, NotFoundHandler onNotFound);

private:
    // Disallow instantiation.
    File();
};

class Directory
{
public:
    static int  create(const char* path);
    static int  create(const std::string& path);
    static bool exists(const char* path);
    static bool exists(const std::string& path);

private:
    // Disallow instantiation.
    Directory();
};

} // namespace gmx

#endif
