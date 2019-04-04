#include "map.h"
#include <stdexcept>

namespace minesweeper {

map::map(size_type width, size_type height)
    : internal_map(
          map_type(width, std::vector<map_element>(height, map_element()))) {}

map::size_type map::get_height() const {
	return internal_map.at(0).size();
}

map::size_type map::get_width() const {
	return internal_map.size();
}

map::map_type map::get_vectors(map::dimension indexed_by) const {
	switch (indexed_by) {
		case dimension::columns:
			return internal_map;
		case dimension::rows:
			return invert();
	}
	throw std::runtime_error("not implemented");
}

void map::set_revealed(map::size_type x, map::size_type y) {
	internal_map.at(x).at(y).is_revealed = true;
}

map::map_type map::invert() const {
	// TODO: map element created and then overwritten - fix
	map_type inverted(get_height(),
	                  std::vector<map_element>(get_width(), map_element()));
	for (unsigned x = 0; x < get_width(); x++) {
		for (unsigned y = 0; y < get_height(); y++) {
			inverted.at(y).at(x) = internal_map.at(x).at(y);
		}
	}
	return inverted;
}
}
