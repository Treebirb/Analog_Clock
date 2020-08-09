add_library(Clock app.cpp clock.cpp)
target_link_libraries(Clock ${SDL_LIBRARY} -static-libstdc++ -static-libgcc -mwindows)