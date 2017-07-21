#include "engine.h"
#include <exception>

namespace saper {

void engine::new_game(engine::size_t width, engine::size_t height) {
	this->width = width;
	this->height = height;
	reset_map(width, height);
}

void engine::reset_map(engine::size_t width, engine::size_t height) {
	map = std::unique_ptr<engine::map_t>(new engine::map_t(
	    width, std::vector<map_element>(
	               height, map_element())));  // use make_unique with c++14
}

void engine::action(size_t x, size_t y) {
	if (x >= width or y >= height) {
		throw std::out_of_range(
		    "Called action on coordinates out of range");
	}
	(*map)[x][y].is_revealed = true;
}

engine::map_t& engine::get_current_map() {
	return *map;
}
}
