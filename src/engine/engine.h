#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "map.h"
#include "map_element.h"

namespace minesweeper {

class engine {
public:
	enum class bomb_policy { none, all };
	void new_game(map::size_type width = 10,
	              map::size_type length = 10,
	              bomb_policy bomb_policy_ = bomb_policy::none);
	void action(map::size_type x, map::size_type y);
	const map& get_current_map() const;

private:
	std::unique_ptr<map> map_;
};
}  // namespace minesweeper
