#include <stdio.h>
#include <SDL/SDL.h>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#endif

extern "C"

int main(int argc, char const *argv[])
{
    printf("hello, wordl!\n"); 
    
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Surface *screen = SDL_SetVideoMode(256, 256, 32, SDL_SWSURFACE);
    
    #ifdef TEST_SDL_LOCK_OPTS 
    EM_ASM("SDL.defaults.copyOnLock = false; SDL.defaults.discardOnLock = true; SDL.defaults.opaqueFrontBuffer = false;");
    #endif
    
    if (SDL_MUSTLOCK(screen)) SDL_LockSurface(screen);
    for (int i = 0; i < 256; i++)
    {
        for (int j = 0; j < 256; j++)
        {
            #ifdef TEST_SDL_LOCK_OPTS
            int alpha = 255;
            #else
            int alpha = (i+j) % 255;
            #endif        
            *((Uint32*)screen->pixels + i*256 + j) = SDL_MapRGBA(screen->format, i, j, 255-i, alpha);
        }
    }
    if (SDL_MUSTLOCK(screen)) SDL_UnlockSurface(screen);
    
    SDL_Flip(screen);
    
    printf("you should see a smoothly-colored square - no sharp lines but the square borders!\n");
    printf("and here is some text that should be HTML-friendly: amp: |&| double-quote: |\"| quote: |'| less-than, greater-than, html-like tags: |<cheez></cheez>|\nanother line.\n");
    
    SDL_Quit();

    return 0;
}
