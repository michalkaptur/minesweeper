#include "../engine/engine.h"
#include "../engine/map.h"

#include <iostream>

void draw_map(const minesweeper::map& m) {
	const auto& internal_map =
	    m.get_vectors(minesweeper::map::dimension::rows);
	for (const auto& row : internal_map) {
		for (const auto& el : row) {
			auto symbol = el.is_revealed ? '0' : 'O';
			std::cout << symbol << " ";
		}
		std::cout << std::endl;
	}
}

void print_separator() {
	std::cout << '\n';
}

int main() {
	minesweeper::engine eng;
	eng.new_game(5, 4);
	eng.action(1, 2);
	draw_map(eng.get_current_map());
	print_separator();
	eng.action(1, 1);
	draw_map(eng.get_current_map());
}
