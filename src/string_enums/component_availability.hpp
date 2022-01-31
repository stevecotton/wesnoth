/*
	Copyright (C) 2008 - 2021
	Part of the Battle for Wesnoth Project https://www.wesnoth.org/

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY.

	See the COPYING file for more details.
*/

#pragma once

#include <array>

#include "string_enums/enum_base.hpp"

struct component_availability_defines
{
	static constexpr const char* const sp = "sp";
	static constexpr const char* const mp = "mp";
	static constexpr const char* const hybrid = "hybrid";

	enum class type { SP, MP, HYBRID, ENUM_MAX };
	static constexpr std::array<const char*, static_cast<int>(type::ENUM_MAX)> values{ sp, mp, hybrid };
};
using component_availability = string_enums::enum_base<component_availability_defines>;
