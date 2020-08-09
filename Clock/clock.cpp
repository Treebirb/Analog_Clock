#include "clock.hpp"

Clock::Clock(SDL_FPoint c) : Center{ c }
{
    float theta = 0.f;
    for (auto &p : Dial)
    {
        p = SDL_FPoint{ 120.f * SDL_cosf(theta), 120.f * SDL_sinf(theta) };
        p.x += Center.x;
        p.y += Center.y;
        theta += (2.f * M_PI) / (float)Dial.size();
    }
    Sec[0] = c;
    Min[0] = c;
    Hour[0] = c;
    // starting time
    std::time_t now = std::time(nullptr);
    int sec = std::localtime(&now)->tm_sec;
    Sec[1] = SDL_FPoint{ 110.f*SDL_cosf(sec * M_PI/30.f - M_PI / 2), 110.f*SDL_sinf(sec * M_PI/30.f - M_PI / 2) };
    Sec[1].x += Center.x;
    Sec[1].y += Center.y;

    int min = std::localtime(&now)->tm_min;
    Min[1] = SDL_FPoint{ 80.f*SDL_cosf(min * M_PI/30.f  - M_PI / 2), 80.f*SDL_sinf(min * M_PI/30.f  - M_PI / 2) };
    Min[1].x += Center.x;
    Min[1].y += Center.y;

    int hr = std::localtime(&now)->tm_hour % 12;
    Hour[1] = SDL_FPoint{ 60.f*SDL_cosf(hr * M_PI/6.f  - M_PI / 2), 60.f*SDL_sinf(hr * M_PI/6.f - M_PI / 2) };
    Hour[1].x += Center.x;
    Hour[1].y += Center.y;

}

void Clock::Update()
{
    std::time_t now = std::time(nullptr);
    int sec = std::localtime(&now)->tm_sec;
    Sec[1] = SDL_FPoint{ 110.f*SDL_cosf(sec * M_PI/30.f - M_PI / 2), 110.f*SDL_sinf(sec * M_PI/30.f - M_PI / 2) };
    Sec[1].x += Center.x;
    Sec[1].y += Center.y;

    int min = std::localtime(&now)->tm_min;
    Min[1] = SDL_FPoint{ 80.f*SDL_cosf(min * M_PI/30.f  - M_PI / 2), 80.f*SDL_sinf(min * M_PI/30.f  - M_PI / 2) };
    Min[1].x += Center.x;
    Min[1].y += Center.y;

    int hr = std::localtime(&now)->tm_hour % 12;
    Hour[1] = SDL_FPoint{ 60.f*SDL_cosf(hr * M_PI/6.f  - M_PI / 2), 60.f*SDL_sinf(hr * M_PI/6.f - M_PI / 2) };
    Hour[1].x += Center.x;
    Hour[1].y += Center.y;
}

void Clock::Draw(SDL_Renderer* renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderDrawLinesF(renderer, Dial.data(), Dial.size());
    SDL_RenderDrawLineF(renderer, Dial.back().x, Dial.back().y, Dial.front().x, Dial.front().y);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderDrawLinesF(renderer, Sec.data(), Sec.size());

    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderDrawLinesF(renderer, Min.data(), Min.size());

    SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
    SDL_RenderDrawLinesF(renderer, Hour.data(), Hour.size());

}