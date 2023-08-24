#pragma once

class GhostManager
{
	//The ghosts will switch between the scatter mode and the chase mode before permanently chasing Pacman.
	unsigned char current_wave;
	unsigned short wave_timer;
	std::array<Ghost, 4> ghosts;
public:
	GhostManager();

	void draw(bool i_flash, sf::RenderWindow& i_window, bool freeze);
	void reset(unsigned char i_level, const std::array<Position, 4>& i_ghost_positions);
	void update(unsigned char i_level, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map, Pacman& i_pacman);
	std::array<Ghost, 4>& getGhosts() {

		return ghosts;

	}
};