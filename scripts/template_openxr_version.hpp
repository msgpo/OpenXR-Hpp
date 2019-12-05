//## Copyright (c) 2017-2019 The Khronos Group Inc.
//## Copyright (c) 2019 Collabora, Ltd.
//##
//## Licensed under the Apache License, Version 2.0 (the "License");
//## you may not use this file except in compliance with the License.
//## You may obtain a copy of the License at
//##
//##     http://www.apache.org/licenses/LICENSE-2.0
//##
//## Unless required by applicable law or agreed to in writing, software
//## distributed under the License is distributed on an "AS IS" BASIS,
//## WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//## See the License for the specific language governing permissions and
//## limitations under the License.
//##
//## ---- Exceptions to the Apache 2.0 License: ----
//##
//## As an exception, if you use this Software to generate code and portions of
//## this Software are embedded into the generated code as a result, you may
//## redistribute such product without providing attribution as would otherwise
//## be required by Sections 4(a), 4(b) and 4(d) of the License.
//##
//## In addition, if you combine or link code generated by this Software with
//## software that is licensed under the GPLv2 or the LGPL v2.0 or 2.1
//## ("`Combined Software`") and if a court of competent jurisdiction determines
//## that the patent provision (Section 3), the indemnity provision (Section 9)
//## or other Section of the License conflicts with the conditions of the
//## applicable GPL or LGPL license, you may retroactively and prospectively
//## choose to deem waived or otherwise exclude such Section(s) of the License,
//## but only in their entirety and only with respect to the Combined Software.

//# set type = "Version"
//# set comparison_operators = ('<', '>', '<=', '>=', '==', '!=')
//# set invalid = ""
//# extends "template_openxr_wrapperclass.hpp"

//## No validity methods
//# block validity
//# endblock

//# block extra_methods
//! Get the major component.
OPENXR_HPP_CONSTEXPR uint16_t major() const noexcept
{
    return static_cast<uint16_t>(val_ >> 48);
}
//! Set the major component.
void major(uint16_t val) noexcept
{
    // blank the top 16 bits
    val_ &= 0x0000ffffffffffff;
    val_ |= uint64_t(val) << 48;
}

//! Get the minor component.
OPENXR_HPP_CONSTEXPR uint16_t minor() const noexcept
{
    return static_cast<uint16_t>((val_ >> 32) & 0xffff);
}
//! Set the minor component.
void minor(uint16_t val) noexcept
{
    // blank the correct 16 bits
    val_ &= 0xffff0000ffffffff;
    val_ |= uint64_t(val) << 32;
}

//! Get the patch component.
OPENXR_HPP_CONSTEXPR uint32_t patch() const noexcept
{
    return static_cast<uint32_t>(val_ & 0xffffffff);
}
//! Set the patch component.
void patch(uint32_t val) noexcept
{
    // blank the least-significant 32 bits
    val_ &= 0xffffffff00000000;
    val_ |= val;
}

//! Get the current version.
static OPENXR_HPP_CONSTEXPR Version current() noexcept
{
    return Version{XR_CURRENT_API_VERSION};
}
//# endblock
