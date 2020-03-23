//ISR Interrupt Handler
//Last modified: VMOS 1.0.4.2
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
#include "timer.h"

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

void irq0() {
    outportb(0x20, 0x20);
    print_serial("0x05_0 ", 0);
    timer_callback();
}

void irq1() {
    outportb(0x20, 0x20);
    print_serial("0x05_1 ", 0);
}

void irq2() {
    outportb(0x20, 0x20);
    print_serial("0x05_2 ", 0);
}

void irq3() {
    outportb(0x20, 0x20);
    print_serial("0x05_3 ", 0);
}

void irq4() {
    outportb(0x20, 0x20);
    print_serial("0x05_4 ", 0);
}

void irq5() {
    outportb(0x20, 0x20);
    print_serial("0x05_5 ", 0);
}

void irq6() {
    outportb(0x20, 0x20);
    print_serial("0x05_6 ", 0);
}

void irq7() {
    outportb(0x20, 0x20);
    print_serial("0x05_7 ", 0);
}

void irq8() {
    outportb(0xA0, 0x20);
    outportb(0x20, 0x20);
    print_serial("0x05_8 ", 0);
}

void irq9() {
    outportb(0xA0, 0x20);
    outportb(0x20, 0x20);
    print_serial("0x05_9 ", 0);
}

void irq10() {
    outportb(0xA0, 0x20);
    outportb(0x20, 0x20);
    print_serial("0x05_10 ", 0);
}

void irq11() {
    outportb(0xA0, 0x20);
    outportb(0x20, 0x20);
    print_serial("0x05_11 ", 0);
}

void irq12() {
    outportb(0xA0, 0x20);
    outportb(0x20, 0x20);
    print_serial("0x05_12 ", 0);
}

void irq13() {
    outportb(0xA0, 0x20);
    outportb(0x20, 0x20);
    print_serial("0x05_13 ", 0);
}

void irq14() {
    outportb(0xA0, 0x20);
    outportb(0x20, 0x20);
    print_serial("0x05_14 ", 0);
}

void irq15() {
    outportb(0xA0, 0x20);
    outportb(0x20, 0x20);
    print_serial("0x05_15 ", 0);
}

void isr_install() {
	print("Installing ");

    set_idt_gate(0, (uint32)isr0);
	
    set_idt_gate(1, (uint32)isr1);
	
    set_idt_gate(2, (uint32)isr2);
	
    set_idt_gate(3, (uint32)isr3);
	
    set_idt_gate(4, (uint32)isr4);
	
    set_idt_gate(5, (uint32)isr5);
	
    set_idt_gate(6, (uint32)isr6);
	
    set_idt_gate(7, (uint32)isr7);
	
    set_idt_gate(8, (uint32)isr8);
	
    set_idt_gate(9, (uint32)isr9);
	
    set_idt_gate(10, (uint32)isr10);
	
    set_idt_gate(11, (uint32)isr11);
	 
    set_idt_gate(12, (uint32)isr12);
	
    set_idt_gate(13, (uint32)isr13);
	
    set_idt_gate(14, (uint32)isr14);
	
    set_idt_gate(15, (uint32)isr15);
	
    set_idt_gate(16, (uint32)isr16);
	
    set_idt_gate(17, (uint32)isr17);
	
    set_idt_gate(18, (uint32)isr18);
	
    set_idt_gate(19, (uint32)isr19);
	
    set_idt_gate(20, (uint32)isr20);
	
    set_idt_gate(21, (uint32)isr21);
	
    set_idt_gate(22, (uint32)isr22);
	
    set_idt_gate(23, (uint32)isr23);
	
    set_idt_gate(24, (uint32)isr24);
	
    set_idt_gate(25, (uint32)isr25);
	
    set_idt_gate(26, (uint32)isr26);
	
    set_idt_gate(27, (uint32)isr27);
	
    set_idt_gate(28, (uint32)isr28);
	
    set_idt_gate(29, (uint32)isr29);
	
    set_idt_gate(30, (uint32)isr30);
	
    set_idt_gate(31, (uint32)isr31);

    outportb(0x20, 0x11);
    outportb(0xA0, 0x11);
    outportb(0x21, 0x20);
    outportb(0xA1, 0x28);
    outportb(0x21, 0x04);
    outportb(0xA1, 0x02);
    outportb(0x21, 0x01);
    outportb(0xA1, 0x01);
    outportb(0x21, 0x0);
    outportb(0xA1, 0x0); 

    set_idt_gate(32, (uint32)irq0);
    set_idt_gate(33, (uint32)irq1);
    set_idt_gate(34, (uint32)irq2);
    set_idt_gate(35, (uint32)irq3);
    set_idt_gate(36, (uint32)irq4);
    set_idt_gate(37, (uint32)irq5);
    set_idt_gate(38, (uint32)irq6);
    set_idt_gate(39, (uint32)irq7);
    set_idt_gate(40, (uint32)irq8);
    set_idt_gate(41, (uint32)irq9);
    set_idt_gate(42, (uint32)irq10);
    set_idt_gate(43, (uint32)irq11);
    set_idt_gate(44, (uint32)irq12);
    set_idt_gate(45, (uint32)irq13);
    set_idt_gate(46, (uint32)irq14);
    set_idt_gate(47, (uint32)irq15);

    set_idt();
}

void irq_install() {
    asm volatile("sti");
    inittimer(50); //Initialize timer
}

#endif
