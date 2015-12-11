#pragma once

#include <cstdint>

#ifdef __APPLE__
    #include <SDL2/SDL.h>
#else
    #include <SDL/SDL.h>
#endif

#include "glm.hpp"

namespace glimac {

class SDLWindowManager {
#ifdef __APPLE__
    SDL_Window* m_pWindow;
	SDL_GLContext m_Context;
#endif
public:
    SDLWindowManager(uint32_t width, uint32_t height, const char* title);

    ~SDLWindowManager();

    bool pollEvent(SDL_Event& e);

#ifdef __APPLE__
    bool isKeyPressed(SDL_Keycode key) const;
#else
    bool isKeyPressed(SDLKey key) const;
#endif

    // button can SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT and SDL_BUTTON_MIDDLE
    bool isMouseButtonPressed(uint32_t button) const;

    glm::ivec2 getMousePosition() const;

    void swapBuffers();

    // Return the time in seconds
    float getTime() const;
};

}
