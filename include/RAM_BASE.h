#ifndef RAM_H
#define RAM_H

#include <iostream>
#include "globals.h"


typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
typedef unsigned long long int uint64;
typedef uint64 offset;


/*No checks of usable numbers in some function , SO YOU need to handle with care*/

class RAM_BASE
{
    public:
        RAM_BASE();
        RAM_BASE(const uint64 &a_typeAddr);
        virtual ~RAM_BASE();

        virtual uint8 accesAt(const offset &a_offset) = 0;
        virtual void setAt(const offset &a_offset , const uint8 a_data) = 0;
        virtual void multSet(const offset &a_offset_begin, const uint8 *a_data, const uint32 &a_nbOffset) = 0; // care, bad use of that function can create SIGSEGVs

    protected:

        uint64 m_format;
};

#endif // RAM_H
