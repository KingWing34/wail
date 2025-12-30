static int counter = 0;
static void on_tick(struct entity_op_data *data){
	counter++;
	SDL_Renderer *renderer = data->graphics->renderer;

	SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderPoint(renderer, 0 + counter, 300);
	SDL_RenderPresent(renderer);

	printf("%i\r", counter);
	fflush(stdout);
}

static void on_init(struct entity_op_data *data){
	printf("INITIALIZED\n");
}

static void on_new(struct entity_op_data *data){
	printf("%i CREATED\n", data->entity->type);
}

void op_biome_forest(){
	printf("EXISTS\n");

	entity_op[(unsigned int) 10] = (struct entity_op) {
		.on_tick = &on_tick,
		.on_init = &on_init,
		.on_new = &on_new
	};
}
