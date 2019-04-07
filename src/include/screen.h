#ifndef SCREEN_H
#define SCREEN_H
#include "types.h"
#include "system.h"
#include "string.h"
int tc = 0x0F;
int cursorX = 0, cursorY = 0;
const uint8 sw = 80,sh = 25,sd = 2;                                                     //We define the screen width, height, and depth.
void clearLine(uint8 from,uint8 to)
{
        uint16 i = sw * from * sd;
        string vidmem=(string)0xb8000;
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
        string vidmem = (string)0xb8000;
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


void newLineCheck()
{
        if(cursorY >=sh-1)
        {
                scrollUp(1);
        }
}

void printch(char c)
{
    string vidmem = (string) 0xb8000;     
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
                vidmem [((cursorY * sw + cursorX))*sd+1] = tc;
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

void print (string ch)
{
        uint16 i = 0;
        uint8 length = strlength(ch)-1;
        for(i;i<length;i++)
        {
                printch(ch[i]);
        }
}

void ctc(string colors) {
	if (colors == "00") {
		tc = 0x00;
	}
	else if (colors == "01") {
		tc = 0x01;
	}
	else if (colors == "02") {
		tc = 0x02;
	}
	else if (colors == "03") {
		tc = 0x03;
	}
	else if (colors == "04") {
		tc = 0x04;
	}
	else if (colors == "05") {
		tc = 0x05;
	}
	else if (colors == "06") {
		tc = 0x06;
	}
	else if (colors == "07") {
		tc = 0x07;
	}
	else if (colors == "08") {
		tc = 0x08;
	}
	else if (colors == "09") {
		tc = 0x09;
	}
	else if (colors == "0A") {
		tc = 0x0A;
	}
	else if (colors == "0B") {
		tc = 0x0B;
	}
	else if (colors == "0C") {
		tc = 0x0C;
	}
	else if (colors == "0D") {
		tc = 0x0D;
	}
	else if (colors == "0E") {
		tc = 0x0E;
	}
	else if (colors == "0F") {
		tc = 0x0F;
	}
	clearScreen();
}

#endif
