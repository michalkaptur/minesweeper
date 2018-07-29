#include <catch.hpp>
#include <engine/map.h>

TEST_CASE("proper_width_and_height", "[map_test]") {
	constexpr auto width = 4;
	constexpr auto height = 6;

	minesweeper::map mymap(width, height);
	REQUIRE(mymap.get_width() == width);
	REQUIRE(mymap.get_height() == height);
}

TEST_CASE("hidden_map_on_new_map", "[map_test]") {
	constexpr auto width = 4;
	constexpr auto height = 6;

	minesweeper::map mymap(width, height);
	const auto& internal_map = mymap.get_internal_map();
	for (const auto& row : internal_map) {
		for (const auto& el : row) {
			REQUIRE(not el.is_revealed);
		}
	}
}
