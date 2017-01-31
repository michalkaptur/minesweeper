#include "../engine/engine.h"

#include <iostream>

void draw_map(const saper::engine::map_t& map)
{
    for(auto row : map)
    {
        for(auto el : row)
        {
            std::cout<<"O ";
        }
        std::cout<<std::endl;
    }

}

int main()
{
    saper::engine eng;
    eng.new_game(5,5);
    draw_map(eng.get_current_map());
}
