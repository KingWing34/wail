#include <cstdio>
#include <miko.h>
extern struct map map;
extern struct map_entity *map_center;
extern struct entity_op entity_op[entity_op_size];
static void action_move(struct map_entity_action_data *data){

}

static struct map_entity_action actions[] = {
	{
		.name = "move",
		.call = &action_move
	}
};

static struct texture textures[] = {
	{
		.name = "box",
		.type = "gif"
	},{
		.name = "box",
		.type = "gif"
	},{
		.name = "box",
		.type = "gif"
	},{
		.name = "box",
		.type = "gif"
	},{
		.name = "box",
		.type = "gif"
	},{
		.name = "box",
		.type = "gif"
	},{
		.name = "box",
		.type = "gif"
	},{
		.name = "box",
		.type = "gif"
	},{
		.name = "box",
		.type = "gif"
	},
	{
		.name = NULL
	}
};

struct button {
	struct map_entity borders[9];
	struct animation animations[9];
};

static void on_fps12(struct entity_op_data *data){
	struct map_entity *entity = data->entity;
	entity->animation->pos++;
}

static void on_fps30(struct entity_op_data *data){

}

static void draw(struct entity_op_data *data){
	struct map_entity *entity = (struct map_entity *) data->entity;
	struct button *button = (struct button *) entity->data;
	struct map_entity *cmp = button->borders;
	struct texture *texture = textures;

	double x = entity->position->x;
	double y = entity->position->y;

	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 1;
	map_entity_draw(cmp);
	cmp++;
	texture++;
	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 2;
	map_entity_draw(cmp);
	cmp++;
	texture++;
	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 3;
	map_entity_draw(cmp);
	cmp++;
	texture++;
	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 4;
	map_entity_draw(cmp);
	cmp++;
	texture++;
	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 5;
	map_entity_draw(cmp);
	cmp++;
	texture++;
	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 6;
	map_entity_draw(cmp);
	cmp++;
	texture++;
	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 7;
	map_entity_draw(cmp);
	cmp++;
	texture++;
	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 8;
	map_entity_draw(cmp);
	cmp++;
	texture++;
	cmp->animation->texture = texture;
	cmp->graphics = data->graphics;
	cmp->position->x = x;
	cmp->position->y = y + 32 * 9;
	map_entity_draw(cmp);
	cmp++;
	texture++;

	//printf("%.2f %.2f\n", x, y);
}

static void on_tick(struct entity_op_data *data){
	struct map_entity *entity = data->entity;
	SDL_Renderer *renderer = data->graphics->renderer;

	entity->position->x = map_center->position->x;
	entity->position->y = map_center->position->y;

	entity->animation->texture = &textures[0];
	entity->graphics->renderer = data->graphics->renderer;

	map_entity_draw(entity);
	draw(data);
}

static void on_init(struct entity_op_data *data){
	SDL_Renderer *renderer = data->graphics->renderer;
	load_textures(textures, renderer);

	entity_new(&map, 3002);
}

static void on_new(struct entity_op_data *data){
	struct map_entity *entity = data->entity;
	entity->directionX = 1;
	entity->directionY = 1;
	entity->animation->pos = 0;

	entity->position->x = 0;
	entity->position->y = 0;

	struct button *user = (struct button *) malloc(sizeof(struct button));

	entity->custom = 1;
	entity->data = (void *) user;

	for(int i = 0; i < 9; i++){
		user->borders[i].animation = &user->animations[i];
		user->animations[i].pos = 0;
		user->borders[i].custom = 1;
	}
}

void op_button(){
	entity_op[(unsigned int) 3002] = (struct entity_op) {
		.on_tick = &on_tick,
		.on_init = &on_init,
		.on_new = &on_new,

		.on_fps12 = &on_fps12,
		.on_fps24 = NULL,
		.on_fps30 = &on_fps30
	};

	/*
	entity_op[(unsigned int) 3003] = (struct entity_op) {
		.on_tick = NULL,
		.on_init = NULL,
		.on_new = NULL,

		.on_fps12 = NULL,
		.on_fps24 = NULL,
		.on_fps30 = NULL
	};*/
}
