#include "core/Thread.hpp"
#include "core/Common.hpp"
#include <SDL2/SDL.h>

static int run(void* data)
{
	Thread* t = (Thread*)data;
	
	printf("Hai from thread\n");

	t->run_internal();

	return 0;
}

Thread::Thread()
{
	thread = SDL_CreateThread(run, "Game Thread", (void*)this);

	if(thread == NULL)
	{
		//@Error
		printf("Failed to create thread!\n");
		return;
	}
}

void Thread::join()
{
	running = false;
}