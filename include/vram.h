#ifndef VRAM_H
#define VRAM_H

#include "RAM_BASE.h"


class VRAM : public RAM_BASE
{
    public:
        VRAM();
        ~VRAM();

    protected:

    const unsigned char *m_raw_mem // Const so it emulates real SRAM
};

#endif // VRAM_H
