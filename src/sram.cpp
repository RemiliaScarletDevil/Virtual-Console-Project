#include "sram.h"


SRAM::SRAM(const uint64 a_format, unsigned char a_filler) : RAM_BASE::RAM_BASE(a_format)
{
    std::cout << "SRAM(uint64,uchar) execution\n";
    unsigned char* temp = new uint8[a_format];
    for(uint64 i = 0; i < a_format; i++)
    {
        temp[i] = a_filler;
    }
    m_memory = temp;

}

SRAM::~SRAM()
{
        std::cout << " ~SRAM() execution\n";
        delete[] m_memory; //dtor
}

uint8 SRAM::accesAt(const offset& a_offset)
{
    if((m_format-1) < a_offset)
    {
        handleOOB();
        return 0x00;
    }
    return m_memory[a_offset];
}

void SRAM::setAt(const offset& a_offset, const uint8 a_data)
{
    unsigned char *temp = nullptr;
    temp = CpyRAW(temp);

    temp[a_offset] = a_data;

    delete[] m_memory;
    m_memory = temp;
}

void SRAM::multSet(const offset& a_offset_begin, const uint8* a_data, const uint32& a_nbOffset)
{
    unsigned char *freeze = CpyRAW(freeze);

    for(unsigned int i = a_offset_begin; i < a_nbOffset+a_offset_begin; ++i)
        {
            freeze[i] = a_data[i - a_offset_begin];
        }
    delete[] m_memory;

    m_memory = freeze;

}

unsigned char *SRAM::accesRAW()
{
    unsigned char *retVal = CpyRAW(retVal);


    return retVal;
}

uint64 SRAM::getFormat()
{
    return m_format;
}

void SRAM::handleOOB()
{
    std::cerr << "OOB of SRAM ! check for information with your ROM dev\n\0";
    std::_Exit(EXIT_FAILURE);
}


inline unsigned char *SRAM::CpyRAW(unsigned char* CpyTo)
{
    CpyTo = new unsigned char[m_format];

    for(uint32 i = 0; i < m_format; ++i)
        {
            CpyTo[i] = m_memory[i];
        }
    return CpyTo;
}




















