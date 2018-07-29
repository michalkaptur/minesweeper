#pragma once

namespace minesweeper {

struct map_element {
	bool has_bomb{false};
	bool is_revealed{false};
};

inline bool operator==(const map_element& rhs, const map_element& lhs) {
	return rhs.has_bomb == lhs.has_bomb &&
	       lhs.is_revealed == rhs.is_revealed;
}
}
