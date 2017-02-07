/*
 * Gonna learn me some hello world stuffs
 */

#include <SDL.h>
#include <cstdio>

typedef struct {
	SDL_Window* window;
	SDL_Surface* screen;
	SDL_Surface* image;
} sdl_state_t;

int init(sdl_state_t* state);
int init_resources(sdl_state_t* state);
void exit_nicely(sdl_state_t* state);

int main(int argc, char* argv[])
{
	sdl_state_t current_game = {};
	sdl_state_t* state = &current_game;
	
	if (init(state) | init_resources(state))
	{
		exit_nicely(state);
		return -1;
	}

	SDL_BlitSurface(state->image, nullptr, state->screen, nullptr);
	SDL_UpdateWindowSurface(state->window);

	SDL_Delay(5000);

	exit_nicely(state);
	return 0;
}

int init(sdl_state_t* state)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL didn't initialize. SDL_GetError(): %s\n", SDL_GetError());
		return -1;
	}

	/* This creates a 640 by 480 window, with no defined position */
	state->window = SDL_CreateWindow(
		"SDL helloworld",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, SDL_WINDOW_BORDERLESS);
	if (state->window == nullptr)
	{
		printf("SDL Window failed to create.\n");
		return -2;
	}

	return 0;
}

int init_resources(sdl_state_t* state)
{
	const char* image_file = "media/splash.bmp";

	state->image = SDL_LoadBMP(image_file);
	if (state->image == nullptr)
	{
		printf("Failed to load image file '%s'.\n", image_file);
		return -1;
	}

	state->screen = SDL_GetWindowSurface(state->window);

	return 0;
}


void exit_nicely(sdl_state_t* state)
{
	if (state->image != nullptr)
		SDL_FreeSurface(state->image);
	if (state->window != nullptr)
		SDL_DestroyWindow(state->window);
	SDL_Quit();
}
