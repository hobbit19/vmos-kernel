#ifndef ISR_H
#define ISR_H

#include "types.h"
#include "isr.h"
#include "idt.h"
#include "screen.h"
#include "util.h"
#include "system.h"

string exception_messages[32] = {
    "(0x01) Division By Zero ",
    "(0x02) Debug ",
    "(0x03) Non Maskable Interrupt ",
    "(0x04) Breakpoint ",
    "(0x05) Into Detected Overflow ",
    "(0x06) Out of Bounds ",
    "(0x07) Invalid Opcode ",
    "(0x08) No Coprocessor ",

    "(0x09) Double Fault ",
    "(0x0A) Coprocessor Segment Overrun ",
    "(0x0B) Bad TSS ",
    "(0x0C) Segment Not Present ",
    "(0x0D) Stack Fault ",
    "(0x0E) General Protection Fault ",
    "(0x0F) Page Fault ",
    "(0x10) Unknown Interrupt ",

    "(0x11) Coprocessor Fault ",
    "(0x12) Alignment Check ",
    "(0x13) Machine Check ",
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
    "(0x1F) Reserved ",
    "(0x20) Reserved "
};

/*Handlers*/
void isr0()
{
	newline();
    print(exception_messages[0]);
    crash();
}
void isr1()
{
	newline();
    print(exception_messages[1]);    
    crash();
}
void isr2()
{
	newline();
    print(exception_messages[2]);    
    crash();
}
void isr3()
{
	newline();
    print(exception_messages[3]);    
    crash();
}
void isr4()
{
	newline();
    print(exception_messages[4]);    
    crash();
}
void isr5()
{
	newline();
    print(exception_messages[5]);    
    crash();
}
void isr6()
{
	newline();
    print(exception_messages[6]);    
    crash();
}
void isr7()
{
	newline();
    print(exception_messages[7]);    
    crash();
}
void isr8()
{
	newline();
    print(exception_messages[8]);    
    crash();
}
void isr9()
{
	newline();
    print(exception_messages[9]);    
    crash();
}
void isr10()
{
	newline();
    print(exception_messages[10]);    
    crash();
}
void isr11()
{
	newline();
    print(exception_messages[11]);    
    crash();
}
void isr12()
{
	newline();
    print(exception_messages[12]);    
    crash();
}
void isr13()
{
	newline();
    print(exception_messages[13]);    
    crash();
}
void isr14()
{
	newline();
    print(exception_messages[14]);    
    crash();
}
void isr15()
{
	newline();
    print(exception_messages[15]);    
    crash();
}
void isr16()
{
	newline();
    print(exception_messages[16]);    
    crash();
}
void isr17()
{
	newline();
    print(exception_messages[17]);    
    crash();
}
void isr18()
{
	newline();
    print(exception_messages[18]);    
    crash();
}
void isr19()
{
	newline();
    print(exception_messages[19]);    
    crash();
}
void isr20()
{
	newline();
    print(exception_messages[20]);    
    crash();
}
void isr21()
{
	newline();
    print(exception_messages[21]);    
    crash();
}
void isr22()
{
	newline();
    print(exception_messages[22]);    
    crash();
}
void isr23()
{
	newline();
    print(exception_messages[23]);    
    crash();
}
void isr24()
{
	newline();
    print(exception_messages[24]);    
    crash();
}
void isr25()
{
	newline();
    print(exception_messages[25]);    
    crash();
}
void isr26()
{
	newline();
    print(exception_messages[26]);    
    crash();
}
void isr27()
{
	newline();
    print(exception_messages[27]);    
    crash();
}
void isr28()
{
	newline();
    print(exception_messages[28]);    
    crash();
}
void isr29()
{
	newline();
    print(exception_messages[29]);    
    crash();
}
void isr30()
{
	newline();
    print(exception_messages[30]);    
    crash();
}
void isr31()
{
	newline();
    print(exception_messages[31]);    
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

    set_idt(); // Load with ASM
}


/*End Handlers*/



/* To print the message which defines every exception */

#endif
