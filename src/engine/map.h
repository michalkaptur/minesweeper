#pragma once
#include <vector>
#include <cstdint>
#include "map_element.h"

namespace minesweeper {
class map {
public:
	using size_type = std::size_t;
	using map_type = std::vector<std::vector<map_element>>;

	map(size_type width, size_type height);
	size_type get_height() const;
	size_type get_width() const;
	void set_revealed(size_type x, size_type y);

	const map_type& get_internal_map() const;  // deprecated

private:
	map_type internal_map;
};
}
