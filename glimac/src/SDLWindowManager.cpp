#include "SDLWindowManager.hpp"


#include <iostream>
#include <stdexcept>

namespace glimac {

SDLWindowManager::SDLWindowManager(uint32_t width, uint32_t height, const char* title) {
    if(0 != SDL_Init(SDL_INIT_VIDEO)) {
        std::cerr << SDL_GetError() << std::endl;
        throw std::runtime_error("Error loading SDL");
        return;
    }

#ifdef __APPLE__
    //antialiasing
    if (SDL_GL_SetAttribute( SDL_GL_MULTISAMPLEBUFFERS, 1 ) == -1)
        std::cerr << "impossible d'initialiser SDL_GL_MULTISAMPLEBUFFERS à 1" ;
    else{
        if (SDL_GL_SetAttribute( SDL_GL_MULTISAMPLESAMPLES, 6 ) == -1)
            std::cerr << "impossible d'initialiser SDL_GL_MULTISAMPLESAMPLES sur 6 buffers";
        else
            std::cout << "anti aliasing démarré" << std::endl;
    }

    std::cout << "window created" << std::endl;
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    m_pWindow = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
    if(!m_pWindow) {
        std::cerr << SDL_GetError() << std::endl;
        return;
    }
    m_Context = SDL_GL_CreateContext(m_pWindow);
    std::cerr << SDL_GetError() << std::endl;
    std::cout << "window created2" << std::endl;
#else
    if(!SDL_SetVideoMode(width, height, 32, SDL_OPENGL)) {
        std::cerr << SDL_GetError() << std::endl;
        return;
    }
    SDL_WM_SetCaption(title, nullptr);

    //SDL_ShowCursor(SDL_DISABLE);
    //SDL_WM_GrabInput(SDL_GRAB_ON);

#endif
}

SDLWindowManager::~SDLWindowManager() {
    SDL_Quit();
}

bool SDLWindowManager::pollEvent(SDL_Event& e) {
    return SDL_PollEvent(&e);
}

#ifdef __APPLE__
bool SDLWindowManager::isKeyPressed(SDL_Keycode key) const {
    return SDL_GetKeyboardState(nullptr)[SDL_GetScancodeFromKey(key)];
}
#else
bool SDLWindowManager::isKeyPressed(SDLKey key) const {
    return SDL_GetKeyState(nullptr)[key];
}
#endif

// button can SDL_BUTTON_LEFT, SDL_BUTTON_RIGHT and SDL_BUTTON_MIDDLE
bool SDLWindowManager::isMouseButtonPressed(uint32_t button) const {
    return SDL_GetMouseState(nullptr, nullptr) & SDL_BUTTON(button);
}

glm::ivec2 SDLWindowManager::getMousePosition() const {
    glm::ivec2 mousePos;
    SDL_GetMouseState(&mousePos.x, &mousePos.y);
    return mousePos;
}

void SDLWindowManager::swapBuffers(){
#ifdef __APPLE__
    SDL_GL_SwapWindow(m_pWindow);
#else
    SDL_GL_SwapBuffers();
#endif
}

float SDLWindowManager::getTime() const {
    return 0.001f * SDL_GetTicks();
}

}
