/*
   Copyright (C) 2016 - 2018 by Ján Dugáček
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

#include "utils/name_generator.hpp"

#include <list>
#include <vector>
#include <cstdint>

class context_free_grammar_generator : public name_generator
{
private:

	struct nonterminal {
		std::vector<std::vector<std::string>> possibilities_;
	};

	/**
	 * Exactly one instance of this is created and used for each call to generate().
	 */
	struct internal_state {
		// ensure we're passing around references to a single instance
		internal_state(const internal_state&) = delete;
		internal_state& operator=(const internal_state&) = delete;

		// Construction results in a fixed number of calls to one of the main random number generators
		internal_state();
		// Reuses the data generated during the construction, does not result in any additional calls to the
		// main RNG.
		unsigned int get_random();

		static const short unsigned int seed_size = 20;
		std::array<uint32_t, seed_size> seed;
		short int seed_pos;

		/** This map uses the same keys as context_free_grammar_generator::nonterminals_ */
		std::map<std::string, unsigned int> last_picked;
	};

	std::map<std::string, nonterminal> nonterminals_;
	std::string print_nonterminal(const std::string& name, internal_state& state) const;

public:
	/** Initialisation
	 * @param source the definition of the context-free grammar to use
	 */
	context_free_grammar_generator(const std::string& source);

	/** Initialisation
	 * @param source A map of nonterminals to lists of possibilities
	 */
	context_free_grammar_generator(const std::map<std::string, std::vector<std::string>>& source);

	/** Generates a possible word in the grammar set before
	 * @return the word
	 */
	std::string generate() const override;

	~context_free_grammar_generator();
};
