//Keyboard driver
//Last modified: VMOS 1.0.4.2
//Made by VMGP

#ifndef KB_H
#define KB_H
#include "screen.h"
#include "system.h"
#include "types.h"

string readStr()
{
    char buff;
    string buffstr;
	int shift = 0;
    uint8 i = 0;
    uint8 reading = 1;
    while(reading)
    {
        if(inportb(0x64) & 0x1)                 
        {
            switch(inportb(0x60))
            {
        //case 1:
				//print(lastcmd);
                //i = strlength(lastcmd);
				//buffstr = lastcmd;
                //break;
        case 2:
                putchar('1');
                buffstr[i] = '1';
                i++;
                break;
        case 3:
                putchar('2');
                buffstr[i] = '2';
                i++;
                break;
        case 4:
                putchar('3');
                buffstr[i] = '3';
                i++;
                break;
        case 5:
                putchar('4');
                buffstr[i] = '4';
                i++;
                break;
        case 6:
                putchar('5');
                buffstr[i] = '5';
                i++;
                break;
        case 7:
                putchar('6');
                buffstr[i] = '6';
                i++;
                break;
        case 8:
                putchar('7');
                buffstr[i] = '7';
                i++;
                break;
        case 9:
                putchar('8');
                buffstr[i] = '8';
                i++;
                break;
        case 10:
                putchar('9');
                buffstr[i] = '9';
                i++;
                break;
        case 11:
                putchar('0');
                buffstr[i] = '0';
                i++;
                break;
        case 12:
                putchar('-');
                buffstr[i] = '-';
                i++;
                break;
        case 13:
                putchar('=');
                buffstr[i] = '=';
                i++;
                break;
        case 14:
				if (i > 0) {
					putchar('\b');
					i--;
					buffstr[i] = 0;
				}
				break;
        case 15:
                putchar((char)240);          //Tab button
                buffstr[i] = (char)240;
                i++;
                break;
        case 16:
				if(shift == 0){
					putchar('q');
					buffstr[i] = 'q';
					i++;
				}
                if(shift == 1){
					putchar('Q');
                    buffstr[i] = 'Q';
					i++;
				}
                break;
        case 17:
                if(shift == 0){
					putchar('w');
					buffstr[i] = 'w';
					i++;
				}
                if(shift == 1){
					putchar('W');
                    buffstr[i] = 'W';
					i++;
				}
                break;
        case 18:
                if(shift == 0){
					putchar('e');
					buffstr[i] = 'e';
					i++;
				}
                if(shift == 1){
					putchar('E');
                    buffstr[i] = 'E';
					i++;
				}
                break;
        case 19:
                if(shift == 0){
					putchar('r');
					buffstr[i] = 'r';
					i++;
				}
                if(shift == 1){
					putchar('R');
                    buffstr[i] = 'R';
					i++;
				}
                break;
        case 20:
                if(shift == 0){
					putchar('t');
					buffstr[i] = 't';
					i++;
				}
                if(shift == 1){
					putchar('T');
                    buffstr[i] = 'T';
					i++;
				}
                break;
        case 21:
                if(shift == 0){
					putchar('y');
					buffstr[i] = 'y';
					i++;
				}
                if(shift == 1){
					putchar('Y');
                    buffstr[i] = 'Y';
					i++;
				}
                break;
        case 22:
                if(shift == 0){
					putchar('u');
					buffstr[i] = 'u';
					i++;
				}
                if(shift == 1){
					putchar('U');
                    buffstr[i] = 'U';
					i++;
				}
                break;
        case 23:
                if(shift == 0){
					putchar('i');
					buffstr[i] = 'i';
					i++;
				}
                if(shift == 1){
					putchar('I');
                    buffstr[i] = 'I';
					i++;
				}
                break;
        case 24:
                if(shift == 0){
					putchar('o');
					buffstr[i] = 'o';
					i++;
				}
                if(shift == 1){
					putchar('O');
                    buffstr[i] = 'O';
					i++;
				}
                
                break;
        case 25:
                if(shift == 0){
					putchar('p');
					buffstr[i] = 'p';
					i++;
				}
                if(shift == 1){
					putchar('P');
                    buffstr[i] = 'P';
					i++;
				}
                break;
        case 26:
                if(shift == 0){
					putchar('[');
					buffstr[i] = '[';
					i++;
				}
                if(shift == 1){
					putchar('{');
			        buffstr[i] = '{';
					i++;
				}
                break;
        case 27:
                if(shift == 0){
					putchar(']');
					buffstr[i] = ']';
					i++;
				}
                if(shift == 1){
					putchar('}');
			        buffstr[i] = '}';
					i++;
				}
                break;
        case 28:
				// putchar('\n');
				// buffstr[i] = '\n';
				buffstr[i] = '\0';
                i++;
				reading = 0;
                break;
      /*  case 29:
                putchar('q');           Left Control
                buffstr[i] = 'q';
                i++;
                break;*/
        case 30:
                if(shift == 0){
					putchar('a');
					buffstr[i] = 'a';
					i++;
				}
                if(shift == 1){
					putchar('A');
                    buffstr[i] = 'A';
					i++;
				}
                break;
        case 31:
                if(shift == 0){
					putchar('s');
					buffstr[i] = 's';
					i++;
				}
                if(shift == 1){
					putchar('S');
                    buffstr[i] = 'S';
					i++;
				}
                break;
        case 32:
                if(shift == 0){
					putchar('d');
					buffstr[i] = 'd';
					i++;
				}
                if(shift == 1){
					putchar('D');
                    buffstr[i] = 'D';
					i++;
				}
                break;
        case 33:
                if(shift == 0){
					putchar('f');
					buffstr[i] = 'f';
					i++;
				}
                if(shift == 1){
					putchar('F');
                    buffstr[i] = 'F';
					i++;
				}
                break;
        case 34:
                if(shift == 0){
					putchar('g');
					buffstr[i] = 'g';
					i++;
				}
                if(shift == 1){
					putchar('G');
                    buffstr[i] = 'G';
					i++;
				}
                break;
        case 35:
                if(shift == 0){
					putchar('h');
					buffstr[i] = 'h';
					i++;
				}
                if(shift == 1){
					putchar('H');
                    buffstr[i] = 'H';
					i++;
				}
                break;
        case 36:
                if(shift == 0){
					putchar('j');
					buffstr[i] = 'j';
					i++;
				}
                if(shift == 1){
					putchar('J');
                    buffstr[i] = 'J';
					i++;
				}
                break;
        case 37:
                if(shift == 0){
					putchar('k');
					buffstr[i] = 'k';
					i++;
				}
                if(shift == 1){
					putchar('K');
                    buffstr[i] = 'K';
					i++;
				}
                break;
        case 38:
                if(shift == 0){
					putchar('l');
					buffstr[i] = 'l';
					i++;
				}
                if(shift == 1){
					putchar('L');
                    buffstr[i] = 'L';
					i++;
				}
                break;
        case 39:
                putchar(';');
                buffstr[i] = ';';
                i++;
                break;
        case 40:
                putchar((char)96);               //   Single quote (')
                buffstr[i] = (char)96;
                i++;
                break;
        case 41:
                putchar((char)96);               // Back tick (`)
                buffstr[i] = (char)96;
                i++;
                break;
        case 42:
				print_serial("0x03 ", 0);
		        if(shift == 0){
					shift = 1;
					break;
				}
                if(shift == 1){
					shift = 0;
					break;
				}
        /*case 43:                                 \ (< for somekeyboards)   
                putchar((char)92);
                buffstr[i] = 'q';
                i++;
                break;*/
        case 44:
                if(shift == 0){
					putchar('z');
					buffstr[i] = 'z';
					i++;
				}
                if(shift == 1){
					putchar('Z');
                    buffstr[i] = 'Z';
					i++;
				}
                break;
        case 45:
                if(shift == 0){
					putchar('x');
					buffstr[i] = 'x';
					i++;
				}
                if(shift == 1){
					putchar('X');
                    buffstr[i] = 'X';
					i++;
				}
                break;
        case 46:
                if(shift == 0){
					putchar('c');
					buffstr[i] = 'c';
					i++;
				}
                if(shift == 1){
					putchar('C');
                    buffstr[i] = 'C';
					i++;
				}
                break;
        case 47:
                if(shift == 0){
					putchar('v');
					buffstr[i] = 'v';
					i++;
				}
                if(shift == 1){
					putchar('V');
                    buffstr[i] = 'V';
					i++;
				}
                break;                
        case 48:
                if(shift == 0){
					putchar('b');
					buffstr[i] = 'b';
					i++;
				}
                if(shift == 1){
					putchar('B');
                    buffstr[i] = 'B';
					i++;
				}
                break;               
        case 49:
                if(shift == 0){
					putchar('n');
					buffstr[i] = 'n';
					i++;
				}
                if(shift == 1){
					putchar('N');
                    buffstr[i] = 'N';
					i++;
				}
                break;                
        case 50:
                if(shift == 0){
					putchar('m');
					buffstr[i] = 'm';
					i++;
				}
                if(shift == 1){
					putchar('M');
                    buffstr[i] = 'M';
					i++;
				}
                break;               
        case 51:
                putchar(',');
                buffstr[i] = ',';
                i++;
                break;                
        case 52:
                if(shift == 0){
					putchar('.');
					buffstr[i] = '.';
					i++;
				}
                if(shift == 1){
					putchar('>');
                    buffstr[i] = '>';
					i++;
				}
                break;            
        case 53:
                putchar('/');
                buffstr[i] = '/';
                i++;
                break;            
        case 54:
                if(shift == 0){
					putchar('.');
					buffstr[i] = '.';
					i++;
				}
                if(shift == 1){
					putchar('>');
                    buffstr[i] = '>';
					i++;
				}
                break;            
        case 55:
                if(shift == 0){
					putchar('/');
					buffstr[i] = '/';
					i++;
				}
                if(shift == 1){
					putchar('?');
                    buffstr[i] = '?';
					i++;
				}
                break;            
      /*case 56:
                putchar(' ');           Right shift
                buffstr[i] = ' ';
                i++;
                break;*/           
        case 57:
                putchar(' ');
                buffstr[i] = ' ';
                i++;
                break;
            }
        }
    }
    buffstr[i] = 0;                   
    return buffstr;
}
#endif
