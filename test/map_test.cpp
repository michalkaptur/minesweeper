#include <catch.hpp>
#include <engine/map.h>

namespace {
constexpr auto width = 4;
constexpr auto height = 6;
}

TEST_CASE("proper_width_and_height", "map_test") {
	minesweeper::map mymap(width, height);
	REQUIRE(mymap.get_width() == width);
	REQUIRE(mymap.get_height() == height);
}

TEST_CASE("hidden_map_by_default", "map_test") {
	minesweeper::map mymap(width, height);
	const auto& internal_map = mymap.get_internal_map();
	for (const auto& row : internal_map) {
		for (const auto& el : row) {
			REQUIRE(not el.is_revealed);
		}
	}
}

TEST_CASE("reveal_proper_map_element", "map_test") {
	constexpr auto x = 2, y = 3;
	minesweeper::map mymap(width, height);
	mymap.set_revealed(x, y);
	REQUIRE(mymap.get_internal_map().at(x).at(y).is_revealed);
}
