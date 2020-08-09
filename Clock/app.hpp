#pragma once

#include <SDL.h>
#include "clock.hpp"

class App
{
    int width, height;
    bool running;

    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Event e;

    Clock clock;

    void Update(), Input(), Draw();

public:
    App() : App{ 640, 480 } {}
    App(int w, int h);
    ~App();
    void Run();
};