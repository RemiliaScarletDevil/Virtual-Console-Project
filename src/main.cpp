#include "..\include\vram_bank_handle.h"



int main(int argc,char *argv[])
{
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Renderer *render = nullptr;
    SDL_Window *win = nullptr;
    SDL_CreateWindowAndRenderer(100, 100, SDL_WINDOW_SHOWN , &win, &render);

    vram_bank_Handle handl;
    SDL_Texture *tex = handl.loadBanktoVRAM(0, render);
    if(tex == nullptr)
        {
            std::cout << "STFU , logic";
        }

    int hauteur = 0;
    int largeur = 0;

    SDL_QueryTexture(tex, nullptr, nullptr, &largeur, &hauteur);

    SDL_Rect dest = {0,0, largeur, hauteur};
    SDL_RenderCopy(render, tex, nullptr, &dest);
    SDL_RenderPresent(render);

    SDL_Delay(3000);
    return 0;
}
