#pragma once

#include <cstdint>
#include <tuple>
#include <vector>
#include <memory>

#include "map_element.h"

namespace saper {

class engine {
public:
    using size_t = std::uint8_t;
    using position = std::pair<size_t, size_t>;
    using map_t = std::vector<std::vector<map_element>>;

    void new_game(size_t width=10, size_t length=10);
    void action(position p);
    map_t& get_current_map();

private:
    void reset_map(engine::size_t width, engine::size_t height);
    std::unique_ptr<map_t> map;
};

}
