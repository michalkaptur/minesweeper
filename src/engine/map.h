#pragma once
#include <vector>
#include <cstdint>
#include "map_element.h"

namespace minesweeper {
class map {
public:
	using size_type = std::size_t;
	using map_type = std::vector<std::vector<map_element>>;

	enum class dimension { rows, columns };

	map(size_type width, size_type height);
	size_type get_height() const;
	size_type get_width() const;
	void set_revealed(size_type x, size_type y);

	// TODO: replace with iterator iface, instead of copy/create
	map_type get_map(dimension indexed_by = dimension::columns) const;

private:
	map_type internal_map;

	map_type invert() const;
};
}
