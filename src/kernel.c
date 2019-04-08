#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/system.h"
#include "include/util.h"
//#include "include/idt.h"

kmain()
{
	   //print("kernel.kmain: Starting isr_install...\n");
	   //isr_install();
	   int cc;
	   int la;
	   cc = 1;
	   la = 0;
	   string ch;
       clearScreen();
       print("kernel.kmain: Starting operating system...\n");
	   newline();
	   print("");
	   newline();
	   print("Tip: If a command does not work try removing the last character. ");
	   newline();
	   print("Example: osver - osve ");
	   newline();
	   if(cc == 1){
		    while (1)
            {
			    if(la == 0) {
                    print("\nVMOS> ");
                    ch = readStr();
                    if(strEql(ch, "osver"))
                    {
						print("\nVMOS 1.0.0 build 68\n");
                    }
					else if(strEql(ch, "cls"))
                    {
                        clearScreen();
                    }
				    else if(strEql(ch, "crash"))
                    {
						clearScreen();
                        break;
                    }
					else if(strEql(ch, "edit"))
                    {
						clearScreen();
                        la = 1;
                    }
                    else
                    {
                        print("\nThis command does not exist!\n");
                    }
                    print("\n"); 
                }
                else if(la == 1)
				{
					print("\n"); 
					string edit = readStr();
					print("\n"); 
					la = 0;
                }				
            }
	   }
       
        
}
