//PIT controller
//Last modified: VMOS 1.0.4
//Made by VMGP

#ifndef SERIAL_H
#define SERIAL_H

#include "system.h"
#include "util.h"
#include "screen.h"
#include "kb.h"
#include "string.h"
#include "isr.h"
#include "idt.h"
#include "serial.h"
#include "cmos.h"

int timer_ticks = 0;

void PIT_irq() {
	timer_ticks++; //Incrmements ticks value
}

void timer_phase(int hz)
{
    int divisor = 1193180 / hz;
    outportb(0x43, 0x36);
    outportb(0x40, divisor & 0xFF);
    outportb(0x40, divisor >> 8);
}

int get_ticks() {
	return timer_ticks; //Returns how many ticks have passed
}

void PIT_setup() {
	timer_phase(100);
	set_idt_gate(32, (uint32)PIT_irq); //Install IRQ
}

#endif