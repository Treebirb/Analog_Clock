#include "app.hpp"

#include <iostream>

App::App(int w, int h) : width{ w }, height{ h }, clock{ SDL_FPoint{ width / 2.f, height / 2.f } }
{
    if (SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_SHOWN, &window, &renderer) != 0)
    {
        std::cerr << "ERROR: " << SDL_GetError() << "\n";
        running = false;
    }
    else
    {
        SDL_SetWindowTitle(window, "Analog Clock");
        running = true;
    }
}

void App::Run()
{
    while (running)
    {
        Input();
        Update();
        Draw();
    }
}

void App::Update()
{
    clock.Update();
}

void App::Input()
{
    if (SDL_PollEvent(&e) != 0)
    {
        if (e.type ==  SDL_QUIT)
            running = false;
        if (e.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
            running = false;
    }
}

void App::Draw()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    clock.Draw(renderer);
    SDL_RenderPresent(renderer);
}

App::~App()
{
    SDL_DestroyWindow(window);
}