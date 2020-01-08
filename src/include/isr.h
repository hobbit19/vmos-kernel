//ISR Interrupt Handler
//Last modified: VMOS 1.0.4.1
//Made by VMGP

#ifndef ISR_H
#define ISR_H

#include "types.h"
#include "isr.h"
#include "idt.h"
#include "screen.h"
#include "serial.h"
#include "util.h"
#include "system.h"

string exception_messages[32] = {
    "(0x00) Division By Zero ",
    "(0x01) Reserved ",
    "(0x02) Non Maskable Interrupt ",
    "(0x03) Breakpoint ",
    "(0x04) Into Detected Overflow ",
    "(0x05) Out of Bounds ",
    "(0x06) Invalid Opcode ",
    "(0x07) No Coprocessor ",

    "(0x08) Double Fault ",
    "(0x09) Coprocessor Segment Overrun ",
    "(0x0A) Bad TSS ",
    "(0x0B) Segment Not Present ",
    "(0x0C) Stack Fault ",
    "(0x0D) General Protection Fault ",
    "(0x0E) Page Fault ",
    "(0x0F) Unknown Interrupt ",

    "(0x10) Coprocessor Fault ",
    "(0x11) Alignment Check ",
    "(0x12) Machine Check ",
    "(0x13) SIMD Floating-Point Exception ",
    "(0x14) Reserved ",
    "(0x15) Reserved ",
    "(0x16) Reserved ",
    "(0x17) Reserved ",

    "(0x18) Reserved ",
    "(0x19) Reserved ",
    "(0x1A) Reserved ",
    "(0x1B) Reserved ",
    "(0x1C) Reserved ",
    "(0x1D) Reserved ",
    "(0x1E) Reserved ",
    "(0x1F) Reserved "
};

/*Handlers*/
void isr0()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[0], 0);
	print_serial("]", 0);
    crash();
}
void isr1()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[1], 0);
	print_serial("]", 0);
    crash();
}
void isr2()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[2], 0);
	print_serial("]", 0);
    crash();
}
void isr3()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[3], 0);
	print_serial("]", 0);
    crash();
}
void isr4()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[4], 0);
	print_serial("]", 0);
    crash();
}
void isr5()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[5], 0);
	print_serial("]", 0);
    crash();
}
void isr6()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[6], 0);
	print_serial("]", 0);
    crash();
}
void isr7()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[7], 0);
	print_serial("]", 0);
    crash();
}
void isr8()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[8], 0);
	print_serial("]", 0);
    crash();
}
void isr9()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[9], 0);
	print_serial("]", 0);
    crash();
}
void isr10()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[10], 0);
	print_serial("]", 0);
    crash();
}
void isr11()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[11], 0);
	print_serial("]", 0);
    crash();
}
void isr12()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[12], 0);
	print_serial("]", 0);
    crash();
}
void isr13()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[13], 0);
	print_serial("]", 0);
    crash();
}
void isr14()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[14], 0);
	print_serial("]", 0);
    crash();
}
void isr15()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[15], 0);
	print_serial("]", 0);
    crash();
}
void isr16()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[16], 0);
	print_serial("]", 0);
    crash();
}
void isr17()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[17], 0);
	print_serial("]", 0);
    crash();
}
void isr18()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[18], 0);
	print_serial("]", 0);
    crash();
}
void isr19()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[19], 0);
	print_serial("]", 0);
    crash();
}
void isr20()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[20], 0);
	print_serial("]", 0);
    crash();
}

void isr21()
{
print_serial("[Crash: ", 0);
    print_serial(exception_messages[21], 0);
	print_serial("]", 0);
    crash();
}
void isr22()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[22], 0);
	print_serial("]", 0);
    crash();
}
void isr23()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[23], 0);
	print_serial("]", 0);
    crash();
}
void isr24()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[24], 0);
	print_serial("]", 0);
    crash();
}
void isr25()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[25], 0);
	print_serial("]", 0);
    crash();
}
void isr26()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[26], 0);
	print_serial("]", 0);
    crash();
}
void isr27()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[27], 0);
	print_serial("]", 0);
    crash();
}

void isr28()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[28], 0);
	print_serial("]", 0);
    crash();
}
void isr29()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[29], 0);
	print_serial("]", 0);
    crash();
}
void isr30()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[30], 0);
	print_serial("]", 0);
    crash();
}
void isr31()
{
	print_serial("[Crash: ", 0);
    print_serial(exception_messages[31], 0);
	print_serial("]", 0);
    crash();
}

void isr_install() {
	newline();
    print("Debug: Setting IDT gate 19... "); 
    set_idt_gate(0, (uint32)isr0);
	newline();
    print("Debug: Setting IDT gate 1... "); 
    set_idt_gate(1, (uint32)isr1);
	newline();
    print("Debug: Setting IDT gate 2... "); 
    set_idt_gate(2, (uint32)isr2);
	newline();
    print("Debug: Setting IDT gate 3... "); 
    set_idt_gate(3, (uint32)isr3);
	newline();
    print("Debug: Setting IDT gate 4... "); 
    set_idt_gate(4, (uint32)isr4);
	newline();
    print("Debug: Setting IDT gate 5... "); 
    set_idt_gate(5, (uint32)isr5);
	newline();
    print("Debug: Setting IDT gate 6... "); 
    set_idt_gate(6, (uint32)isr6);
	newline();
    print("Debug: Setting IDT gate 7... "); 
    set_idt_gate(7, (uint32)isr7);
	newline();
    print("Debug: Setting IDT gate 8... "); 
    set_idt_gate(8, (uint32)isr8);
	newline();
    print("Debug: Setting IDT gate 9... "); 
    set_idt_gate(9, (uint32)isr9);
	newline();
    print("Debug: Setting IDT gate 10... "); 
    set_idt_gate(10, (uint32)isr10);
	newline();
    print("Debug: Setting IDT gate 11... "); 
    set_idt_gate(11, (uint32)isr11);
	newline();
    print("Debug: Setting IDT gate 12... "); 
    set_idt_gate(12, (uint32)isr12);
	newline();
    print("Debug: Setting IDT gate 13... "); 
    set_idt_gate(13, (uint32)isr13);
	newline();
    print("Debug: Setting IDT gate 14... "); 
    set_idt_gate(14, (uint32)isr14);
	newline();
    print("Debug: Setting IDT gate 15... "); 
    set_idt_gate(15, (uint32)isr15);
	newline();
    print("Debug: Setting IDT gate 16... "); 
    set_idt_gate(16, (uint32)isr16);
	newline();
    print("Debug: Setting IDT gate 17... "); 
    set_idt_gate(17, (uint32)isr17);
	newline();
    print("Debug: Setting IDT gate 18... "); 
    set_idt_gate(18, (uint32)isr18);
	newline();
    print("Debug: Setting IDT gate 19... "); 
    set_idt_gate(19, (uint32)isr19);
	newline();
    print("Debug: Setting IDT gate 20... "); 
    set_idt_gate(20, (uint32)isr20);
	newline();
    print("Debug: Setting IDT gate 21... "); 
    set_idt_gate(21, (uint32)isr21);
	newline();
    print("Debug: Setting IDT gate 22... "); 
    set_idt_gate(22, (uint32)isr22);
	newline();
    print("Debug: Setting IDT gate 23... "); 
    set_idt_gate(23, (uint32)isr23);
	newline();
    print("Debug: Setting IDT gate 24... "); 
    set_idt_gate(24, (uint32)isr24);
	newline();
    print("Debug: Setting IDT gate 25... "); 
    set_idt_gate(25, (uint32)isr25);
	newline();
    print("Debug: Setting IDT gate 26... "); 
    set_idt_gate(26, (uint32)isr26);
	newline();
    print("Debug: Setting IDT gate 27... "); 
    set_idt_gate(27, (uint32)isr27);
	newline();
    print("Debug: Setting IDT gate 28... "); 
    set_idt_gate(28, (uint32)isr28);
	newline();
    print("Debug: Setting IDT gate 29... "); 
    set_idt_gate(29, (uint32)isr29);
	newline();
    print("Debug: Setting IDT gate 30... "); 
    set_idt_gate(30, (uint32)isr30);
	newline();
    print("Debug: Setting IDT gate 31... "); 
    set_idt_gate(31, (uint32)isr31);
}


/*End Handlers*/



/* To print the message which defines every exception */

#endif
