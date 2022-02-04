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

struct level_result_defines
{
	static constexpr const char* const victory = "victory";
	static constexpr const char* const defeat = "defeat";
	static constexpr const char* const quit = "quit";
	static constexpr const char* const observer_end = "observer_end";
	static constexpr const char* const result_not_set = "result_not_set";
	static constexpr const char* const pass = "pass";
	static constexpr const char* const fail = "fail";
	static constexpr const char* const test_invalid = "test_invalid";

	enum class type { VICTORY, DEFEAT, QUIT, OBSERVER_END, RESULT_NOT_SET, PASS, FAIL, TEST_INVALID, ENUM_MAX };
	static constexpr std::array<const char*, static_cast<int>(type::ENUM_MAX)> values{ victory, defeat, quit, observer_end, result_not_set, pass, fail, test_invalid };
};
using level_result = string_enums::enum_base<level_result_defines>;
