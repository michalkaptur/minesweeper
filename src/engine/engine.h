#pragma once

#include <cstdint>
#include <memory>
#include <vector>

#include "map_element.h"
#include "map.h"

namespace minesweeper {

class engine {
public:
	void new_game(map::size_type width = 10, map::size_type length = 10);
	void action(map::size_type x, map::size_type y);
	const map& get_current_map() const;

private:
	std::unique_ptr<map> map_;
};
}
