#include "engine.h"

namespace saper {

void engine::new_game(engine::size_t width, engine::size_t height)
{
    map = blank_map(width, height);
}

void engine::action(engine::position p)
{

}

engine::map_t engine::get_current_map()
{
   return map;
}

engine::map_t engine::blank_map(engine::size_t width, engine::size_t height)
{
    map_t map_;
    for (uint x=0; x<width; x++)
    {
        for(uint y=0; y<height; y++)
        {
            map_[x][y] = map_element();
        }
    }
    return map_;
}

}
