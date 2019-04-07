#include "engine.h"
#include <exception>

namespace minesweeper {

void engine::new_game(map::size_type width,
                      map::size_type height,
                      bomb_policy bomb_policy_) {
	map_ = std::make_unique<map>(width, height);
	if (bomb_policy_ == bomb_policy::all) {
		// FIXME: construct it that way at the first place
		for (unsigned x = 0; x < width; x++) {
			for (unsigned y = 0; y < height; y++) {
				map_->put_bomb(x, y);
			}
		}
	}
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
}  // namespace minesweeper
