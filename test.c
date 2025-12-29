#include <stdlib.h>
#include <miko.h>

struct map_entity entity_type_fox = {
	.type = 2
};

int main(int argc, char **argv){
	struct map map;
	map_new(&map);

	for(int i = 0; i < 32; i++){
		map_entities_add(&map, &entity_type_fox);
	}

	map_entities_unset(&map, 12);

	for(int i = 0; i < map_entities_len(&map); i++){
		printf("%i) %i\n", i, map.entities[i].type);
	}

	printf("  === DEFRAG ===\n");
	map_entities_defrag(&map);

	for(int i = 0; i < map_entities_len(&map); i++){
		printf("%i) %i\n", i, map.entities[i].type);
	}

	return 0;
}
