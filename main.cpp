#include <SDL.h>
#include <iostream>
#include "app.hpp"

int main(int argc, char** argv)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "ERROR: " << SDL_GetError() << "\n";
        return -1;
    }
    else
    {
        App clock{};
        clock.Run();
    }

    SDL_Quit();
    return 0;
}