#include <SDL2/SDL.h>

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);  // inicializar SDL

    SDL_Window* window = SDL_CreateWindow("Mi ventana", 100, 100, 640, 480, SDL_WINDOW_SHOWN);  // crear una ventana
    if (window == NULL) {  // manejo de errores
        printf("Error al crear la ventana: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Delay(3000);  // esperar 3 segundos
    SDL_DestroyWindow(window);  // destruir la ventana
    SDL_Quit();  // cerrar SDL
    return 0;
}