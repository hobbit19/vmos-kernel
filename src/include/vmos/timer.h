//Timer Controller
//Last modified: VMOS 1.0.4.2
//Made by VMGP

#ifndef TIMER_H
#define TIMER_H

#include "system.h"
#include "isr.h"
#include "idt.h"
#include "types.h"

uint32 tick = 0;

static void timer_callback() {
    tick++;
    print_serial("Timer callback ", 0);
}

void inittimer(uint32 freq) {
    uint32 divisor = 1193180 / freq;
    uint8 low  = (uint8) (divisor & 0xFF);
    uint8 high = (uint8) ((divisor >> 8) & 0xFF);

    outportb(0x43, 0x36); /* Command port */
    outportb(0x40, low);
    outportb(0x40, high);
}

#endif