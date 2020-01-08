//System utilities
//Last modified: VMOS 1.0.4.1
//Made by VMGP

#ifndef UTIL_H
#define UTIL_H

#include "types.h"

uint16 get_u16(uint8 *addr)
{
	return (*(addr + 1) << 8) + *addr;
}

uint32 get_u32(uint8 *addr)
{
	return (*(addr + 3) << 24) + (*(addr + 2) << 16) + (*(addr + 1) << 8) + *addr;
}

void memory_copy(char *source, char *dest, int nbytes) {
    int i;
    for (i = 0; i < nbytes; i++) {
        *(dest + i) = *(source + i);             //    dest[i] = source[i]
    }
}

void memory_set(uint8 *dest, uint8 val, uint32 len) {
    uint8 *temp = (uint8 *)dest;
    for ( ; len != 0; len--) *temp++ = val;
}

void * malloc (int size){
	char rv1[size];
	return &rv1;
}

void setup() {
	NMI_enable();
}

void NMI_enable() {
	outportb(0x70, inportb(0x70) & 0x7F);
}

void int_to_ascii(int n, char str[]) {          
    int i, sign;
    if ((sign = n) < 0) n = -n;
    i = 0;
    do {
        str[i++] = n % 10 + '0';         
    } while ((n /= 10) > 0);

    if (sign < 0) str[i++] = '-';
    str[i] = '\0';
}

string int_to_string(int32 n)
{
    if (n == 0)
    {
        return "0";
    }

    int32 acc = n;
    char c[32];
    int i = 0;
    while (acc > 0)
    {
        c[i] = '0' + acc%10;
        acc /= 10;
        i++;
    }
    c[i] = 0;


    char c2[32];
    c2[i--] = 0;
    int j = 0;
    while(i >= 0)
    {
        c2[i--] = c[j++];
    }
    return c2;
}
#endif
