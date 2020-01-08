//Main kernel script
//Last modified: VMOS 1.0.4.1
//Made by VMGP

#include "include/system.h"
#include "include/util.h"
#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/isr.h"
#include "include/idt.h"
#include "include/serial.h"
#include "include/cmos.h"
#include "include/pit.h"

kmain()
{
	init_serial(); //Initializes COM1 port for debugging
	setup(); //Does system setup
	isr_install(); //Installs ISR and exceptions
	PIT_setup(); //Instlls PIT (Programmable Interval Timer)
	set_idt(); //Sets interrupts
	clearScreen();
	newline();
	int running = 0; //Integer variable to keep the do while loop alive
	string testfinal; //String variable used to convert integers
	string cmdline; //String value for command line
	int test; //Integer varible for interrupt / crash testing
	int mode = 0; //Integer value for determining the mode that you are in (text mode / 320x200 video mode)
	int j = 0;
	newline();
	print("Debugging was started by the system on port COM1");
	newline();
	newline();
	print("VMOS 1.0.4");
	newline();
	print("Type ");
	printch((char)34);
	print("help");
	printch((char)34);
	print(" to show a list of commands!");
	newline();
	do {
		if (mode == 0) {
			print("\nVMOS> ");
			cmdline = readStr();
			newline();
			if(strEql(cmdline, "osver"))
			{
				printch((char)176);
				printch((char)177);
				printch((char)178);
				print(" VMOS 1.0.4.1 ");
				printch((char)178);
				printch((char)177);
				printch((char)176);
				newline();
			}
			else if(strEql(cmdline, "cls"))
			{
				clearScreen();
			}
			else if(strEql(cmdline, "reboot"))
			{
				reboot();
			}
			else if(strEql(cmdline, "help"))
			{
				println("osver - Operating System Information");
				println("cls - Clears screen");
				println("reboot - Reboots computer");
				println("help - Shows all commands");
				println("userinput - Prints user input");
				println("crash - Crashes the system using division by 0");
				println("debug - Starts / stops debugging on port COM1");
				println("timedate - Show time and date from the RTC chip");
			}
			else if(strEql(cmdline, "userinput"))
			{
				print(cmdline);
			}
			else if(strEql(cmdline, "crash"))
			{
				test = 5/0;
			}
			else if(strEql(cmdline, "debug"))
			{
				ss_serial();
			}
			else if(strEql(cmdline, "timedate"))
			{
				cmos_readtime();
			}
			else if(strEql(cmdline, "printmem"))
			{
				testfinal = "";
				int_to_ascii(getmem(), testfinal);
				print(testfinal);
			}
			else if(strEql(cmdline, "gui"))
			{
				videomode();
				VgaTest();
				mode = 1;
			}
			else
			{
				print_serial("0x01 ", 0);
				newline();
				printch((char)96);
				print(cmdline);
				printch((char)96);
				print(" is not recognzed as an valid command");
			}
			
			newline();
		}
		else if (mode == 1) {
			
		}
	} while (running == 0);
}
