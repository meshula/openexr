/*
** SPDX-License-Identifier: BSD-3-Clause
** Copyright Contributors to the OpenEXR Project.
*/

#ifndef OPENEXR_CORE_STD_ATTR_H
#define OPENEXR_CORE_STD_ATTR_H

#include "openexr_attr.h"

#ifdef __cplusplus
extern "C" {
#endif
OPENEXR_CORE_INTERNAL_NAMESPACE_SOURCE_ENTER

/** @file */

/** 
 * @defgroup Standard attributes
 * @brief These are a group of attributes which are not strictly required,
 * but have common definitions and should be preferred for representing
 * the information they describe.
 * @{
 */

/*
chromaticities
whiteLuminance
adoptedNeutral
renderingTransform
lookModTransform
xDensity
owner
comments
capDate
utcOffset
longitude
latitude
altitude
focus
expTime
aperture
isoSpeed
envmap
keyCode
timeCode
wrapmodes
framesPerSecond
multiView
worldToCamera
worldToNDC
deepImageState
originalDataWindow
dwaCompressionLevel
*/

/** @} */

OPENEXR_CORE_INTERNAL_NAMESPACE_SOURCE_EXIT
#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* OPENEXR_CORE_STD_ATTR_H */
