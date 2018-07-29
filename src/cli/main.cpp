#include "../engine/engine.h"
#include "../engine/map.h"

#include <iostream>

void draw_map(const minesweeper::map& m) {
    auto internal_map = m.get_internal_map();
	for (const auto& row : internal_map) {
		for (const auto& el : row) {
			auto symbol = el.is_revealed ? '0' : 'O';
			std::cout << symbol << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	minesweeper::engine eng;
	eng.new_game(5, 4);
	eng.action(1, 2);
	draw_map(eng.get_current_map());
}
