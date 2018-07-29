#include "map.h"

namespace minesweeper {

map::map(size_type width, size_type height)
    : internal_map(
          map_type(width, std::vector<map_element>(height, map_element()))) {}

map::size_type map::get_height() const {
	internal_map.at(0).size();
}

map::size_type map::get_width() const {
    internal_map.size();
}

void map::set_revealed(map::size_type x, map::size_type y)
{
    internal_map.at(x).at(y).is_revealed = true;
}

const map::map_type& map::get_internal_map() const {
	return internal_map;
}
}
