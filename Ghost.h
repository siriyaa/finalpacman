#pragma once
#include <chrono> 
class Ghost
{
	//It can be the scatter mode or the chase mode.
	bool movement_mode;
	
	bool use_door;
	bool hasCollided;

	//Current direction.
	unsigned char direction;
	//1,2,3
	unsigned char frightened_mode;
	//To make the ghost move more slowly, we'll move it after a certain number of frames. So we need a timer.
	unsigned char frightened_speed_timer;
	//0 - Red
	//1 - Pink
	//2 - Blue
	//3 - Orange
	unsigned char id;

	unsigned short animation_timer;

	//The ghost will go here when escaping .
	Position home;
	bool collisionHandled;
	
	Position home_exit;
	//Current position.
	Position position;
	//Current target.
	Position target;
public:
	Ghost(unsigned char i_id);

	bool pacman_collision(const Position& i_pacman_position);

	float get_target_distance(unsigned char i_direction);

	void draw(bool i_flash, sf::RenderWindow& i_window, bool freeeze);
	void reset(const Position& i_home, const Position& i_home_exit);
	void set_position(short i_x, short i_y);
	void switch_mode();
	void update(unsigned char i_level, std::array<std::array<Cell, MAP_HEIGHT>, MAP_WIDTH>& i_map, Ghost& i_ghost_0, Pacman& i_pacman);
	void update_target(unsigned char i_pacman_direction, const Position& i_ghost_0_position, const Position& i_pacman_position);
	void resetCollided();
	Position get_position();
};