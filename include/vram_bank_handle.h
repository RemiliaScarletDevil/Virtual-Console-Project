#ifndef VRAM_BANK_HANDLE_H
#define VRAM_BANK_HANDLE_H

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <SDL2/SDL.h>
#include "sram.h"

#define SNESPLUS_BANK_SIZES 1825201

class vram_bank_Handle
{
    public:
        vram_bank_Handle();
        virtual ~vram_bank_Handle();

        SDL_Texture* loadBanktoVRAM(uint8 id, SDL_Renderer *rendFor, SDL_Palette *pal = nullptr);
        void loadFiletoSRAMbank(const char &file, uint8 id);
        void setSRAM(unsigned char id, const unsigned char *data, unsigned int bGin, unsigned int eGin);
    private:

    SRAM *m_SramBanks;
    bool m_isLoaded[10];

};

#endif // VRAM_BANK_HANDLE_H
