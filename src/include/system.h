//System Operations Script
//Last modified: VMOS 1.0.4.1
//Made by VMGP

#ifndef SYSTEM_H
#define SYSTEM_H

#include "types.h"

uint8 inportb(uint16 _port)
{
	uint8 rv;
	__asm__ __volatile__ ("inb %1, %0" : "=a" (rv) : "dN" (_port));
	return rv;
}

uint16 inportw(uint16 p_port)
{
    uint16 l_ret;
    __asm__ __volatile__ ("inw %1, %0" : "=a" (l_ret) : "dN" (p_port));
    return l_ret;
}

uint32 inportl(uint16 p_port)
{
    uint32 l_ret;
    __asm__ __volatile__ ("inl %1, %0" : "=a" (l_ret) : "dN" (p_port));
    return l_ret;
}

void outportb(uint16 _port, uint8 _data)
{
	__asm__ __volatile__ ("outb %1, %0" : : "dN" (_port), "a" (_data));
}

void outportw (uint16 p_port,uint16 p_data)
{
    __asm__ __volatile__ ("outw %1, %0" : : "dN" (p_port), "a" (p_data));
}

void outportl (uint16 p_port,uint32 p_data)
{
    __asm__ __volatile__ ("outl %1, %0" : : "dN" (p_port), "a" (p_data));
}

void reboot() {
	print_serial("0x04 ", 0);
	uint8 good = 0x02;
	while (good & 0x02) {
		good = inportb(0x64);
	}
	outportb(0x64, 0xFE);
	halt();
}

void halt() {
	asm("hlt");
}

void crash() {
	halt();
}

uint16 getmem() {
	uint16 total;
    uint8 lowmem, highmem;
 
    outportb(0x70, 0x30);
    lowmem = inportb(0x71);
    outportb(0x70, 0x31);
    highmem = inportb(0x71);
 
    total = lowmem | highmem << 8;
    return total;
}


#endif
