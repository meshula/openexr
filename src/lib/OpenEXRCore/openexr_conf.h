/*
** SPDX-License-Identifier: BSD-3-Clause
** Copyright Contributors to the OpenEXR Project.
*/

#ifndef OPENEXR_CONF_H
#define OPENEXR_CONF_H
#pragma once

#ifdef OPENEXR_C_STANDALONE
#define OPENEXR_EXPORT
#else
#include "OpenEXRConfig.h"
#endif

/// \addtogroup ExportMacros
/// @{

// are we making a DLL under windows (might be msvc or mingw or others)
#if defined(OPENEXR_DLL)

// when building as a DLL for windows, typical dllexport/import case
// where we need to switch depending on whether we are compiling
// internally or not
#    if defined(OPENEXRCORE_EXPORTS)
#        define EXR_EXPORT __declspec(dllexport)
#    else
#        define EXR_EXPORT __declspec(dllimport)
#    endif

#else

#    define EXR_EXPORT OPENEXR_EXPORT

#endif

/*
 * MSVC does have printf format checks, but it is not in the form of a
 * function attribute, so just skip for non-GCC/clang builds
 */
#if defined(__GNUC__) || defined(__clang__)
#    define EXR_PRINTF_FUNC_ATTRIBUTE __attribute__ ((format (printf, 3, 4)))
#else
#    define EXR_PRINTF_FUNC_ATTRIBUTE
#endif

#define OPENEXR_USE_NAMESPACES
#if defined(__cplusplus) && defined(OPENEXR_USE_NAMESPACES)

/// @TODO this should be using the OpenEXRConfig macro
#define OPENEXR_EXTERNAL_NAMESPACE cexr
#define OPENEXR_NS OPENEXR_EXTERNAL_NAMESPACE
/// @TODO this should be using the OpenEXRConfig macro
#define OPENXR_INTERNAL_NAMESPACE 2308
#define OPENEXR_INTERNAL_NS exr_ ## OPENEXR_INTERNAL_NAMESPACE ## _reserved
#define OPENEXR_NS_GLOBAL ::OPENEXR_NS

namespace OPENEXR_INTERNAL_NS { }

// The root level namespace for all source in OpenEXRCore
namespace OPENEXR_NS {
    using namespace OPENEXR_INTERNAL_NS;
}

#define OPENEXR_NAMESPACE_OPEN_SCOPE   namespace OPENEXR_INTERNAL_NS {
#define OPENEXR_NAMESPACE_CLOSE_SCOPE  }  
#define OPENEXR_NAMESPACE_USING_DIRECTIVE using namespace OPENEXR_NS;

#else

#define OPENEXR_NAMESPACE_OPEN_SCOPE   
#define OPENEXR_NAMESPACE_CLOSE_SCOPE 
#define OPENEXR_NAMESPACE_USING_DIRECTIVE

#endif // PXR_USE_NAMESPACES


/// @}

#endif /* OPENEXR_CONF_H */
