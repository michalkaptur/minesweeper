#include <gtest/gtest.h>

#include <engine/engine.h>


class engine_test : public testing::Test
{
public:
    saper::engine e;
    const std::uint8_t width = 2;
    const std::uint8_t length = 4;
};

TEST_F(engine_test, default_new_game)
{
    e.new_game();
}

TEST_F(engine_test, new_game_with_specified_size)
{
    e.new_game(width, length);
    auto map = e.get_current_map();
    EXPECT_EQ(map.size(), width);
    for(auto row : map)
    {
        EXPECT_EQ(row.size(), length);
    }
}

TEST_F(engine_test, hidden_map_on_new_game)
{
    e.new_game(width, length);
    auto map = e.get_current_map();
    EXPECT_EQ(map.size(), width);
    for(auto row : map)
    {
        for(auto el : row) {
            EXPECT_FALSE(el.is_revealed);
        }
    }
}
