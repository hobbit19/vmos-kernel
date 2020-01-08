//Keyboard driver
//Last modified: VMOS 1.0.4.1
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
                printch('1');
                buffstr[i] = '1';
                i++;
                break;
        case 3:
                printch('2');
                buffstr[i] = '2';
                i++;
                break;
        case 4:
                printch('3');
                buffstr[i] = '3';
                i++;
                break;
        case 5:
                printch('4');
                buffstr[i] = '4';
                i++;
                break;
        case 6:
                printch('5');
                buffstr[i] = '5';
                i++;
                break;
        case 7:
                printch('6');
                buffstr[i] = '6';
                i++;
                break;
        case 8:
                printch('7');
                buffstr[i] = '7';
                i++;
                break;
        case 9:
                printch('8');
                buffstr[i] = '8';
                i++;
                break;
        case 10:
                printch('9');
                buffstr[i] = '9';
                i++;
                break;
        case 11:
                printch('0');
                buffstr[i] = '0';
                i++;
                break;
        case 12:
                printch('-');
                buffstr[i] = '-';
                i++;
                break;
        case 13:
                printch('=');
                buffstr[i] = '=';
                i++;
                break;
        case 14:
				if (i > 0) {
					printch('\b');
					i--;
					buffstr[i] = 0;
				}
				break;
        case 15:
                printch((char)240);          //Tab button
                buffstr[i] = (char)240;
                i++;
                break;
        case 16:
				if(shift == 0){
					printch('q');
					buffstr[i] = 'q';
					i++;
				}
                if(shift == 1){
					printch('Q');
                    buffstr[i] = 'Q';
					i++;
				}
                break;
        case 17:
                if(shift == 0){
					printch('w');
					buffstr[i] = 'w';
					i++;
				}
                if(shift == 1){
					printch('W');
                    buffstr[i] = 'W';
					i++;
				}
                break;
        case 18:
                if(shift == 0){
					printch('e');
					buffstr[i] = 'e';
					i++;
				}
                if(shift == 1){
					printch('E');
                    buffstr[i] = 'E';
					i++;
				}
                break;
        case 19:
                if(shift == 0){
					printch('r');
					buffstr[i] = 'r';
					i++;
				}
                if(shift == 1){
					printch('R');
                    buffstr[i] = 'R';
					i++;
				}
                break;
        case 20:
                if(shift == 0){
					printch('t');
					buffstr[i] = 't';
					i++;
				}
                if(shift == 1){
					printch('T');
                    buffstr[i] = 'T';
					i++;
				}
                break;
        case 21:
                if(shift == 0){
					printch('y');
					buffstr[i] = 'y';
					i++;
				}
                if(shift == 1){
					printch('Y');
                    buffstr[i] = 'Y';
					i++;
				}
                break;
        case 22:
                if(shift == 0){
					printch('u');
					buffstr[i] = 'u';
					i++;
				}
                if(shift == 1){
					printch('U');
                    buffstr[i] = 'U';
					i++;
				}
                break;
        case 23:
                if(shift == 0){
					printch('i');
					buffstr[i] = 'i';
					i++;
				}
                if(shift == 1){
					printch('I');
                    buffstr[i] = 'I';
					i++;
				}
                break;
        case 24:
                if(shift == 0){
					printch('o');
					buffstr[i] = 'o';
					i++;
				}
                if(shift == 1){
					printch('O');
                    buffstr[i] = 'O';
					i++;
				}
                
                break;
        case 25:
                if(shift == 0){
					printch('p');
					buffstr[i] = 'p';
					i++;
				}
                if(shift == 1){
					printch('P');
                    buffstr[i] = 'P';
					i++;
				}
                break;
        case 26:
                if(shift == 0){
					printch('[');
					buffstr[i] = '[';
					i++;
				}
                if(shift == 1){
					printch('{');
			        buffstr[i] = '{';
					i++;
				}
                break;
        case 27:
                if(shift == 0){
					printch(']');
					buffstr[i] = ']';
					i++;
				}
                if(shift == 1){
					printch('}');
			        buffstr[i] = '}';
					i++;
				}
                break;
        case 28:
				// printch('\n');
				// buffstr[i] = '\n';
				buffstr[i] = '\0';
			    print_serial("0x02 ", 0);
                i++;
				reading = 0;
                break;
      /*  case 29:
                printch('q');           Left Control
                buffstr[i] = 'q';
                i++;
                break;*/
        case 30:
                if(shift == 0){
					printch('a');
					buffstr[i] = 'a';
					i++;
				}
                if(shift == 1){
					printch('A');
                    buffstr[i] = 'A';
					i++;
				}
                break;
        case 31:
                if(shift == 0){
					printch('s');
					buffstr[i] = 's';
					i++;
				}
                if(shift == 1){
					printch('S');
                    buffstr[i] = 'S';
					i++;
				}
                break;
        case 32:
                if(shift == 0){
					printch('d');
					buffstr[i] = 'd';
					i++;
				}
                if(shift == 1){
					printch('D');
                    buffstr[i] = 'D';
					i++;
				}
                break;
        case 33:
                if(shift == 0){
					printch('f');
					buffstr[i] = 'f';
					i++;
				}
                if(shift == 1){
					printch('F');
                    buffstr[i] = 'F';
					i++;
				}
                break;
        case 34:
                if(shift == 0){
					printch('g');
					buffstr[i] = 'g';
					i++;
				}
                if(shift == 1){
					printch('G');
                    buffstr[i] = 'G';
					i++;
				}
                break;
        case 35:
                if(shift == 0){
					printch('h');
					buffstr[i] = 'h';
					i++;
				}
                if(shift == 1){
					printch('H');
                    buffstr[i] = 'H';
					i++;
				}
                break;
        case 36:
                if(shift == 0){
					printch('j');
					buffstr[i] = 'j';
					i++;
				}
                if(shift == 1){
					printch('J');
                    buffstr[i] = 'J';
					i++;
				}
                break;
        case 37:
                if(shift == 0){
					printch('k');
					buffstr[i] = 'k';
					i++;
				}
                if(shift == 1){
					printch('K');
                    buffstr[i] = 'K';
					i++;
				}
                break;
        case 38:
                if(shift == 0){
					printch('l');
					buffstr[i] = 'l';
					i++;
				}
                if(shift == 1){
					printch('L');
                    buffstr[i] = 'L';
					i++;
				}
                break;
        case 39:
                printch(';');
                buffstr[i] = ';';
                i++;
                break;
        case 40:
                printch((char)96);               //   Single quote (')
                buffstr[i] = (char)96;
                i++;
                break;
        case 41:
                printch((char)96);               // Back tick (`)
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
                printch((char)92);
                buffstr[i] = 'q';
                i++;
                break;*/
        case 44:
                if(shift == 0){
					printch('z');
					buffstr[i] = 'z';
					i++;
				}
                if(shift == 1){
					printch('Z');
                    buffstr[i] = 'Z';
					i++;
				}
                break;
        case 45:
                if(shift == 0){
					printch('x');
					buffstr[i] = 'x';
					i++;
				}
                if(shift == 1){
					printch('X');
                    buffstr[i] = 'X';
					i++;
				}
                break;
        case 46:
                if(shift == 0){
					printch('c');
					buffstr[i] = 'c';
					i++;
				}
                if(shift == 1){
					printch('C');
                    buffstr[i] = 'C';
					i++;
				}
                break;
        case 47:
                if(shift == 0){
					printch('v');
					buffstr[i] = 'v';
					i++;
				}
                if(shift == 1){
					printch('V');
                    buffstr[i] = 'V';
					i++;
				}
                break;                
        case 48:
                if(shift == 0){
					printch('b');
					buffstr[i] = 'b';
					i++;
				}
                if(shift == 1){
					printch('B');
                    buffstr[i] = 'B';
					i++;
				}
                break;               
        case 49:
                if(shift == 0){
					printch('n');
					buffstr[i] = 'n';
					i++;
				}
                if(shift == 1){
					printch('N');
                    buffstr[i] = 'N';
					i++;
				}
                break;                
        case 50:
                if(shift == 0){
					printch('m');
					buffstr[i] = 'm';
					i++;
				}
                if(shift == 1){
					printch('M');
                    buffstr[i] = 'M';
					i++;
				}
                break;               
        case 51:
                printch(',');
                buffstr[i] = ',';
                i++;
                break;                
        case 52:
                if(shift == 0){
					printch('.');
					buffstr[i] = '.';
					i++;
				}
                if(shift == 1){
					printch('>');
                    buffstr[i] = '>';
					i++;
				}
                break;            
        case 53:
                printch('/');
                buffstr[i] = '/';
                i++;
                break;            
        case 54:
                if(shift == 0){
					printch('.');
					buffstr[i] = '.';
					i++;
				}
                if(shift == 1){
					printch('>');
                    buffstr[i] = '>';
					i++;
				}
                break;            
        case 55:
                if(shift == 0){
					printch('/');
					buffstr[i] = '/';
					i++;
				}
                if(shift == 1){
					printch('?');
                    buffstr[i] = '?';
					i++;
				}
                break;            
      /*case 56:
                printch(' ');           Right shift
                buffstr[i] = ' ';
                i++;
                break;*/           
        case 57:
                printch(' ');
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
