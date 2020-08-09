#pragma once

#include <SDL.h>
#include <array>
#include <ctime>

class Clock
{
    SDL_FPoint Center;
    std::array<SDL_FPoint, 36> Dial;
    std::array<SDL_FPoint, 2> Sec, Min, Hour;

public:
    Clock(SDL_FPoint c);
    void Update();
    void Draw(SDL_Renderer* renderer);
}; 