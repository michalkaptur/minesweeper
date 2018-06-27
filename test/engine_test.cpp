#include <catch.hpp>
#include <engine/engine.h>
#include <cstdint>

namespace {
    const std::uint8_t width = 2;
    const std::uint8_t length = 4;
}

TEST_CASE("default_new_game", "[engine_test]")
{
    saper::engine e;
    e.new_game();
}

TEST_CASE("new_game_with_specified_size", "[engine_test]")
{
    saper::engine e;
    e.new_game(width, length);
    auto map = e.get_current_map();
    REQUIRE(map.size() == width);
    for(auto row : map)
    {
        REQUIRE(row.size() == length);
    }
}

TEST_CASE("hidden_map_on_new_game", "[engine_test]")
{
    saper::engine e;
    e.new_game(width, length);
    auto map = e.get_current_map();
    REQUIRE(map.size() == width);
    for(auto row : map)
    {
        for(auto el : row) {
            REQUIRE(not el.is_revealed);
        }
    }
}

TEST_CASE("action_reveals_element", "[engine_test]")
{
    saper::engine e;
    e.new_game(width, length);
    std::uint8_t x=1, y=2;
    e.action(x,y);
    auto map = e.get_current_map();
    REQUIRE(map[x][y].is_revealed);
}

TEST_CASE("action_throws_on_range_violation", "[engine_test]")
{
    saper::engine e;
    e.new_game(width, length);
    std::uint8_t max_x=width-1, max_y=length-1;
    REQUIRE_NOTHROW(e.action(max_x,max_y));
    REQUIRE_THROWS_AS(e.action(max_x+1,max_y), std::out_of_range);
    REQUIRE_THROWS_AS(e.action(max_x,max_y+1), std::out_of_range);
    REQUIRE_THROWS_AS(e.action(max_x+10,max_y+1), std::out_of_range);
}

//TODO: action without game started, action on forbidden position

