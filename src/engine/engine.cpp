#include "engine.h"
#include <exception>

namespace minesweeper {

void engine::new_game(map::size_type width, map::size_type height) {
	map_.reset(new map(width, height));
}

void engine::action(map::size_type x, map::size_type y) {
	if (x >= map_->get_width() or y >= map_->get_height()) {
		throw std::out_of_range(
		    "Called action on coordinates out of range");
	}
    map_->set_revealed(x, y);
}

const map& engine::get_current_map() const {
	return *map_;
}
}
