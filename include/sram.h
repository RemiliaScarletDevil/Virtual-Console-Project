#ifndef SRAM_H
#define SRAM_H

#include "RAM_BASE.h"



/* Classe émulant de la sram , a défaut de pouvoir y acceder  directement , la lecture est optimisé , ainsi que la place en mémoire , mais il est TRES long d'y ecrire
    utilisations pratiques : les dialogues des personnages dans une zone dans un RPG , on load le tout au début , et pas de lag étrange quand on trigger un évent :p*/


class SRAM : public RAM_BASE
{
    public:
        SRAM() = delete;
        SRAM(const uint64 a_format, unsigned char a_filler);
        virtual ~SRAM();

        uint8 accesAt(const offset& a_offset) override;
        uint64 getFormat();

        unsigned char *accesRAW();
        void setAt(const offset& a_offset, const uint8 a_data) override;
        void multSet(const offset& a_offset_begin, const uint8* a_data, const uint32& a_nbOffset = 0) override;

    protected:
        void handleOOB();
        inline unsigned char * CpyRAW(unsigned char *CpyTo); //pass nullptr ptr

    unsigned const char* m_memory;
    unsigned long m_pointer;

};

#endif // SRAM_H
