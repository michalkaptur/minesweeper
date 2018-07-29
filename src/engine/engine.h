#pragma once

#include <cstdint>
#include <memory>
#include <tuple>
#include <vector>

#include "map_element.h"

namespace minesweeper {

class engine {
public:
	using size_t = std::uint8_t;
	using map_t = std::vector<std::vector<map_element>>;

	void new_game(size_t width = 10, size_t length = 10);
	void action(size_t x, size_t y);
	map_t& get_current_map();

private:
	size_t width, height;
	void reset_map(engine::size_t width, engine::size_t height);
	std::unique_ptr<map_t> map;
};
}
