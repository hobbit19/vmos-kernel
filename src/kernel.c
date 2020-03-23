//Main kernel script
//Last modified: VMOS 1.0.4.2
//Made by VMGP

#include "include/vmos/system.h"
#include "include/vmos/util.h"
#include "include/vmos/screen.h"
#include "include/vmos/kb.h"
#include "include/vmos/string.h"
#include "include/vmos/isr.h"
#include "include/vmos/idt.h"
#include "include/vmos/serial.h"
#include "include/vmos/cmos.h"
#include "include/vmos/pit.h"

kmain()
{
	println("Project VMOS 1.0.4.2 ( PREVIEW ) - released under GPL v3.0 license");
	println("Made by VMGP (2016 - 2020)");
	newline();
	println("VMOS comes with NO WARRANTY");
	//Maybe 1.0.5 will come out (some time) - when I fix the IRQs and the a20 line crashing
	//By the way the a20 code is remove for moment
	//Also, yes this is a preview
	setup(); //Does system setup
	isr_install(); //Installs ISRs
	//irq_install(); //Installs IRQs
	//PIT_setup(); //Instlls PIT (Programmable Interval Timer)
	init_serial(); //Initializes COM1 port for debugging
	set_idt(); //Sets interrupts
	int running = 0; //Integer variable to keep the do while loop alive
	string testfinal; //String variable used to convert integers
	string cmdline; //String value for command line
	int test; //Integer varible for interrupt / crash testing
	int mode = 0; //Integer value for determining the mode that you are in (text mode / 320x200 video mode)
	int j = 0;
	newline();
	println("[DEBUG] Debugging was started by the system on port COM1");
	newline();
	println("Type ");
	putchar((char)34);
	print("help");
	putchar((char)34);
	print(" to show a list of commands!");
	newline();
	do {
		if (mode == 0) {
			print("\nVMOS> ");
			cmdline = readStr();
			newline();
			if(strEql(cmdline, "osver"))
			{
				putchar((char)176);
				putchar((char)177);
				putchar((char)178);
				print(" VMOS 1.0.4.2 ( PREVIEW ) ");
				putchar((char)178);
				putchar((char)177);
				putchar((char)176);
				newline();
			}
			else if(strEql(cmdline, "clear"))
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
				println("clear - Clears screen");
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
				print("Total memory allocated for the OS (bytes): ");
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
				newline();
				putchar((char)34);
				print(cmdline);
				putchar((char)34);
				print(" is not recognzed as an valid command");
			}
			
			newline();
		}
		else if (mode == 1) {
			
		}
	} while (running == 0);
}
