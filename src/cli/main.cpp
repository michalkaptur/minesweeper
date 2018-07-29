#include "../engine/engine.h"

#include <iostream>

void draw_map(const minesweeper::engine::map_t& map) {
	for (auto row : map) {
		for (auto el : row) {
			char symbol{'O'};
			if (el.is_revealed)
				symbol = '0';
			std::cout << symbol << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	minesweeper::engine eng;
	eng.new_game(5, 5);
	eng.action(1, 2);
	draw_map(eng.get_current_map());
}
