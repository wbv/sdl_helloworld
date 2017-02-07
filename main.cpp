/*
 * Gonna learn me some hello world stuffs
 */

#include <SDL.h>
#include <cstdio>

void exit_nicely(SDL_Window* window);

int main(int argc, char* argv[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL didn't initialize. SDL_GetError(): %s\n", SDL_GetError());
		exit_nicely(window);
		return -1;
	}

	/* This creates a 640 by 480 window, with no defined position */
	window = SDL_CreateWindow(
		"SDL helloworld",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		640, 480, SDL_WINDOW_BORDERLESS);
	if (window == NULL)
	{
		printf("SDL Window failed to create.\n");
		exit_nicely(window);
		return -2;
	}
		

	screen = SDL_GetWindowSurface(window);
	// fill the screen with white (RGB: 255, 255, 255)
	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));
	SDL_UpdateWindowSurface(window);

	printf("Hello, World.\n");
	SDL_Delay(2000);

	SDL_Quit();
	return 0;
}

void exit_nicely(SDL_Window* window)
{
	SDL_Quit();
	SDL_DestroyWindow(window);
}