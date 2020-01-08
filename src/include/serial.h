//Serial controller
//Last modified: VMOS 1.0.4.1
//Made by VMGP

#ifndef SERIAL_H
#define SERIAL_H

#include "system.h"

#define PORT 0x3f8   //COM1 

int debug = 1; 
 
//Initialization
void init_serial() {
   outportb(PORT + 1, 0x00);    // Disable all interrupts
   outportb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
   outportb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
   outportb(PORT + 1, 0x00);    //                  (hi byte)
   outportb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
   outportb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
   outportb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
   print_serial("VMOS_SerialDriver_1.0.4.1 ", 0);
}

//Reading
int serial_received() {
   return inportb(PORT + 5) & 1;
}
 
char read_serial() {
   while (serial_received() == 0);
 
   return inportb(PORT);
}

//Writing
int is_transmit_empty() {
   return inportb(PORT + 5) & 0x20;
}
 
void write_serial(char a) {
	if(debug == 1) {
		while (is_transmit_empty() == 0);
		
		outportb(PORT,a);
	}
}

void print_serial(string ch, int newline)
{
    while(*ch != 0) {
		write_serial(*ch);
		ch++;
	}
	if (newline == 1) {
		serial_newline();
	}
}

void debug_f(string ch)
{
    print_serial(ch, 0);
}

void ss_serial() {
	if (debug == 1) {
		print("Debugging was stopped by the user on port COM1");
		debug = 0;
	} else if (debug == 0) {
		print("Debugging was started by the user on port COM1");
		debug = 1;
	}
}

void serial_newline() {
	outportb(PORT + 1, 0x00);    // Disable all interrupts
	outportb(PORT + 3, 0x80);    // Enable DLAB (set baud rate divisor)
	outportb(PORT + 0, 0x03);    // Set divisor to 3 (lo byte) 38400 baud
	outportb(PORT + 1, 0x00);    //                  (hi byte)
	outportb(PORT + 3, 0x03);    // 8 bits, no parity, one stop bit
	outportb(PORT + 2, 0xC7);    // Enable FIFO, clear them, with 14-byte threshold
	outportb(PORT + 4, 0x0B);    // IRQs enabled, RTS/DSR set
}

#endif
