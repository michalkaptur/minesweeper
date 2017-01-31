#include "engine.h"

namespace saper {

void engine::new_game(engine::size_t width, engine::size_t height)
{
    reset_map(width, height);
}

void engine::reset_map(engine::size_t width, engine::size_t height)
{
    map = std::make_unique<engine::map_t>(width, std::vector<map_element>(height, map_element()));
}

void engine::action(size_t x, size_t y)
{
    (*map)[x][y].is_revealed = true;
}

engine::map_t &engine::get_current_map()
{
    return *map;
}

}
