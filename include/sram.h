#ifndef SRAM_H
#define SRAM_H

#include "RAM_BASE.h"



/* Classe �mulant de la sram , a d�faut de pouvoir y acceder  directement , la lecture est optimis� , ainsi que la place en m�moire , mais il est TRES long d'y ecrire
    utilisations pratiques : les dialogues des personnages dans une zone dans un RPG , on load le tout au d�but , et pas de lag �trange quand on trigger un �vent :p*/


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
