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

struct plugin_manager_status_defines
{
	static constexpr const char* const not_created = "not created";
	static constexpr const char* const running = "running";
	static constexpr const char* const stopped = "stopped";

	enum class type { NOT_CREATED, RUNNING, STOPPED, ENUM_MAX };
	static constexpr std::array<const char*, static_cast<int>(type::ENUM_MAX)> values{ not_created, running, stopped };
};
using plugin_manager_status = string_enums::enum_base<plugin_manager_status_defines>;
