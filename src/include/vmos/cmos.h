//CMOS and RTC Controller
//Last modified: VMOS 1.0.4.2
//Made by VMGP

#ifndef CMOS_H
#define CMOS_H

#include "types.h"
#include "system.h"
#include "util.h"

char time[];

uint8 get_RTC_register(int reg) {
	outportb(0x70, reg);
	return inportb(0x71);
}

int guipf() {
	outportb(0x70, 0x0A);
	return (inportb(0x71) & 0x80);
}

void cmos_readtime() {
	while(guipf());
	println("Second: ");
	int_to_ascii(get_RTC_register(0x00), time);
	print(time);
	println("Minute: ");
	int_to_ascii(get_RTC_register(0x02), time);
	print(time);
	println("Hour: ");
	int_to_ascii(get_RTC_register(0x04), time);
	print(time);
	println("WeekDay: ");
	int_to_ascii(get_RTC_register(0x06), time);
	print(time);
	println("MonthDay: ");
	int_to_ascii(get_RTC_register(0x07), time);
	print(time);
	println("Month: ");
	int_to_ascii(get_RTC_register(0x08), time);
	print(time);
	println("Year: ");
	int_to_ascii(get_RTC_register(0x09), time);
	print(time);
}

#endif