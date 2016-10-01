#include "vram_bank_handle.h"

vram_bank_Handle::vram_bank_Handle()
{
    std::cout << "VRAM_BANK_HANDLE ini\n";
    m_SramBanks = new SRAM[10]{SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0),
                               SRAM(SNESPLUS_BANK_SIZES , 0xF0)};
    std::cout << "VRAM_HANDLE ini finished\n\n";
    //ctor
}

vram_bank_Handle::~vram_bank_Handle()
{
  std::cout << "\nentering VRAM_BANK_HANDLE destruction process :\n";
  delete[] m_SramBanks;  //dtor
  std::cout << "VRAM_BANK_HANDLE cleaned out\n";
}


SDL_Texture* vram_bank_Handle::loadBanktoVRAM(uint8 id, SDL_Renderer* rendFor, SDL_Palette *pal)
{
    SDL_Surface *srf = nullptr;
    if(id > 9 )
        {
            std::cout << "ERROR : invalid SRAM bank ID\n\0";
            return nullptr;
        }
    if(rendFor == nullptr)
        {
            std::cout << "ERROR : error loading sram bank number : " << id << " \nCause : parameter rendFor's null => prevent from a SIGSEGV \n\0";
            return nullptr;
        }
    if(pal == nullptr)
        {
            const int ByteperPixel = 3;
            int nbPx = m_SramBanks[id].getFormat()/3;
            int cotePx = sqrt(nbPx);
            int coteOctet = cotePx * ByteperPixel;
            std::cout << "NbPx :" << nbPx << "\ncotePx : " << cotePx << "\nCoteOctet : " << coteOctet<< "\n";
            srf = SDL_CreateRGBSurfaceFrom(static_cast<void*>(m_SramBanks[id].accesRAW()), cotePx, cotePx, 24,
                                           coteOctet, 0, 0, 0, 0);
        }
    else
        {
            srf = SDL_CreateRGBSurfaceFrom(m_SramBanks[id].accesRAW(), sqrt(m_SramBanks[id].getFormat()), sqrt(m_SramBanks[id].getFormat()), 4,
                                           sqrt(m_SramBanks[id].getFormat()), 0, 0, 0, 0);
            srf->format->palette = pal;
        }
    SDL_Texture *tex = SDL_CreateTextureFromSurface(rendFor, srf);
    SDL_FreeSurface(srf);

    return tex;
}

void vram_bank_Handle::loadFiletoSRAMbank(const char &filen, uint8 id)
{
    std::FILE *file = std::fopen(&filen, "r");
    unsigned char *chr = new unsigned char[SNESPLUS_BANK_SIZES];
    if(file == nullptr)
        {
            std::cout << "Invalid file : " << file << " \n\0";
            std::exit(4);
        }
    unsigned int i = 0;
    while(std::feof(file) == 0)
        {
            chr[i] = static_cast<unsigned char>(std::fgetc(file));
        }

    m_SramBanks[id].multSet(0, chr, SNESPLUS_BANK_SIZES);
}













