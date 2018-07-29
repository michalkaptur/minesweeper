#pragma once

namespace minesweeper {

struct map_element {
	bool has_bomb{false};
	bool is_revealed{false};
};
}
