/*
	Copyright (C) 2021 by the Battle for Wesnoth Project https://www.wesnoth.org/

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation; either version 2 of the License, or
	(at your option) any later version.
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY.

	See the COPYING file for more details.
*/

#include "gui/dialogs/multiplayer/match_history.hpp"

#include "formula/string_utils.hpp"
#include "game_initialization/lobby_data.hpp"
#include "gettext.hpp"
#include "gui/widgets/window.hpp"
#include "wesnothd_connection.hpp"

namespace gui2
{
namespace dialogs
{
REGISTER_DIALOG(mp_match_history)

mp_match_history::mp_match_history(mp::user_info& info, wesnothd_connection& connection)
	: info_(info)
	, connection_(connection)
{
	register_label("title", true, VGETTEXT("Match History — $player", {{"player", info.name}}));
}

void mp_match_history::pre_show(window& /*window*/)
{
}

} // namespace dialogs
} // namespace gui2
