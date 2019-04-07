#include <engine/map.h>
#include <catch.hpp>

namespace {
constexpr auto width = 4;
constexpr auto height = 6;
}  // namespace

TEST_CASE("proper_width_and_height", "map_test") {
	minesweeper::map mymap(width, height);
	REQUIRE(mymap.get_width() == width);
	REQUIRE(mymap.get_height() == height);
}

TEST_CASE("hidden_map_by_default", "map_test") {
	minesweeper::map mymap(width, height);
	const auto& internal_map = mymap.get_vectors();
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
	REQUIRE(mymap.get_vectors().at(x).at(y).is_revealed);
}
TEST_CASE("valid_dimension_when_inverted_by_rows", "map_test") {
	minesweeper::map mymap(width, height);
	const auto& inverted =
	    mymap.get_vectors(minesweeper::map::dimension::rows);
	REQUIRE(inverted.size() == height);
	REQUIRE(inverted.at(0).size() == width);
}
TEST_CASE("same_elements_when_inverted_by_rows", "map_test") {
	minesweeper::map mymap(2, 3);
	mymap.set_revealed(1, 2);  // F
	const auto& map_by_rows =
	    mymap.get_vectors(minesweeper::map::dimension::rows);
	const auto& map_by_columns =
	    mymap.get_vectors(minesweeper::map::dimension::columns);
	/*
	 by columns          by rows
	 A B                 A C E
	 C D                 B D F
	 E F
	 */
	REQUIRE(map_by_columns[0][0] == map_by_rows[0][0]);  // A
	REQUIRE(map_by_columns[1][0] == map_by_rows[0][1]);  // B
	REQUIRE(map_by_columns[0][1] == map_by_rows[1][0]);  // C
	REQUIRE(map_by_columns[1][1] == map_by_rows[1][1]);  // D
	REQUIRE(map_by_columns[0][2] == map_by_rows[2][0]);  // E
	REQUIRE(map_by_columns[1][2] == map_by_rows[2][1]);  // F
}

TEST_CASE("put_sample_bomb", "map_test") {
	minesweeper::map mymap(2, 1);
    mymap.put_bomb(1,0);
    const auto& view = mymap.get_vectors(minesweeper::map::dimension::columns);
    REQUIRE(view[1][0].has_bomb);
    REQUIRE(view[0][0].has_bomb == false);
}
