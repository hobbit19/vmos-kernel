//Screen Controller
//Last modified: VMOS 1.0.4.2
//Made by VMGP

#ifndef SCREEN_H
#define SCREEN_H

#define DEPRECATED_ATTRIBUTE     __attribute__((deprecated))

#include "types.h"
#include "system.h"
#include "string.h"
int cursorX = 0, cursorY = 0;
const uint8 sw = 80,sh = 25,sd = 2; 
string vidmem=(string)0xb8000;
void clearLine(uint8 from,uint8 to)
{
        uint16 i = sw * from * sd;
        for(i;i<(sw*to*sd);i++)
        {
                vidmem[i] = 0x0;
        }
}
void updateCursor()
{
    unsigned temp;

    temp = cursorY * sw + cursorX;                                                      // Position = (y * width) +  x

    outportb(0x3D4, 14);                                                                // CRT Control Register: Select Cursor Location
    outportb(0x3D5, temp >> 8);                                                         // Send the high byte across the bus
    outportb(0x3D4, 15);                                                                // CRT Control Register: Select Send Low byte
    outportb(0x3D5, temp);                                                              // Send the Low byte of the cursor location
}
void clearScreen()
{
        clearLine(0,sh-1);
        cursorX = 0;
        cursorY = 0;
        updateCursor();
}

void scrollUp(uint8 lineNumber)
{
        uint16 i = 0;
        clearLine(0,lineNumber-1);                                            //updated
        for (i;i<sw*(sh-1)*2;i++)
        {
                vidmem[i] = vidmem[i+sw*2*lineNumber];
        }
        clearLine(sh-1-lineNumber,sh-1);
        if((cursorY - lineNumber) < 0 ) 
        {
                cursorY = 0;
                cursorX = 0;
        } 
        else 
        {
                cursorY -= lineNumber;
        }
        updateCursor();
}

void newline() {
        putchar('\n');
}


void newLineCheck()
{
        if(cursorY >=sh-1)
        {
                scrollUp(1);
        }
}

void putchar(char c)
{    
    switch(c)
    {
        case (0x08):
                if(cursorX > 0) 
                {
	                cursorX--;									
                        vidmem[(cursorY * sw + cursorX)*sd]=0x00;	                              
	        }
	        break;
       /* case (0x09):
                cursorX = (cursorX + 8) & ~(8 - 1); 
                break;*/
        case ('\r'):
                cursorX = 0;
                break;
        case ('\n'):
                cursorX = 0;
                cursorY++;
                break;
        default:
                vidmem [((cursorY * sw + cursorX))*sd] = c;
                vidmem [((cursorY * sw + cursorX))*sd+1] = 0x0F;
                cursorX++; 
                break;
	
    }
    if(cursorX >= sw)                                                                   
    {
        cursorX = 0;                                                                
        cursorY++;                                                                    
    }
    updateCursor();
    newLineCheck();
}

void print(string ch)
{
        while(*ch != 0) {
		putchar(*ch);
		ch++;
	}
}

void println(string ch)
{
	newline();
        while(*ch != 0) {
		putchar(*ch);
		ch++;
	}
}

void textmode() {
	//Not done yet
}

void videomode() {
	clearScreen();
	
	const uint8 w[7] = { 0x5F, 0x4F, 0x50, 0x82, 0x54, 0x80, 0x28 };   // width = 320
	const uint8 h[8] = { 0xBF, 0x1F, 0x41, 0x9C, 0x8E, 0x8F, 0x96, 0xB9 }; // height = 200
	const uint8 w_regs[7] = { 0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x13 };
	const uint8 h_regs[8] = { 0x6, 0x7, 0x9, 0x10, 0x11, 0x12, 0x15, 0x16 };
	int i;

	outportb(0x3C2, 0x63); // mode switch
	outportw(0x3D4, 0x0E11); // enable registers


	for (i = 0; i < 7; i++)
		outportw(0x3D4, (short)((w[i]<<8)+w_regs[i]));
	for (i = 0; i < 8; i++)
		outportw(0x3D4, (short)((h[i]<<8)+h_regs[i]));
		outportw(0x3D4, 0x0008);
		outportw(0x3D4, 0x4014);
		outportw(0x3D4, 0xA317);
		outportw(0x3C4, 0x0E04);


	outportw(0x3C4, 0x0101);
	outportw(0x3C4, 0x0F02); // enable writing to all planes


	outportw(0x3CE, 0x4005); // 256color mode
	outportw(0x3CE, 0x0506); // graph mode & A000-AFFF
 
	inportb(0x3da);
	outportb(0x3C0, 0x30); 
	outportb(0x3C0, 0x41);
	outportb(0x3C0, 0x33);
	outportb(0x3C0, 0x00);


	for (i = 0; i < 16; i++)
	{
		outportb(0x3C0, sizeof(uint8));
		outportb(0x3C0, sizeof(uint8));
	}
	outportb(0x3C0, 0x20); // enable video
}

void gui_DrawPixel(unsigned x, unsigned y, unsigned c)
{
	uint8 *vga = (uint8*)0xA0000;
	int offset = y * 320 + x;
	vga[offset] = c;
}


void gui_SetBackground(uint8 color)
{
	int w, h;
	for (w = 0; w < 320; w++)
	{
	for (h = 0; h < 200; h++)
		gui_DrawPixel(w, h, color);
	}  
}

void VgaTest() {
	gui_SetBackground(0);
	gui_DrawPixel(12, 12, 15);
	gui_DrawPixel(13, 12, 1);
	gui_DrawPixel(14, 12, 2);
	gui_DrawPixel(15, 12, 3);
	gui_DrawPixel(16, 12, 4);
	gui_DrawPixel(17, 12, 5);
}

#endif
