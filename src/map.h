#ifndef MAP_H
#define MAP_H
#include <miko.h>

size_t map_width = 4096;
size_t map_height = 4096;

struct map_position {
	unsigned float x;
	unsigned float y;
	unsigned float z;
};

void map_position_move(
	unsigned float dx,
	unsigned float dy,
	unsigned float dz
){

}

#endif
