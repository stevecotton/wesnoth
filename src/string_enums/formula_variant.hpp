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

struct formula_variant_defines
{
	static constexpr const char* const type_null = "null";
	static constexpr const char* const type_int = "int";
	static constexpr const char* const type_decimal = "decimal";
	static constexpr const char* const type_object = "object";
	static constexpr const char* const type_list = "list";
	static constexpr const char* const type_string = "string";
	static constexpr const char* const type_map = "map";

	enum class type { TYPE_NULL, TYPE_INT, TYPE_DECIMAL, TYPE_OBJECT, TYPE_LIST, TYPE_STRING, TYPE_MAP, ENUM_MAX };
	static constexpr std::array<const char*, static_cast<int>(type::ENUM_MAX)> values{ type_null, type_int, type_decimal, type_object, type_list, type_string, type_map };
};
using formula_variant = string_enums::enum_base<formula_variant_defines>;
