#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/system.h"
#include "include/util.h"

kmain()
{
	   int cc;
	   int la;
	   cc = 1;
	   la = 0;
	   string ch = (string) malloc(200);
       clearScreen();
       print("kernel.kernel.kmain: Starting operating system...\n");
	   print("\nkernel.kernel.kmain: Please wait...\n");
	   print("\n \n");
	   print("\n \n");
	   print("\nTip: If a command does not work try removing the last character.\n");
	   print("\nExample: osver - osve\n");
	   print("\n \n");
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
					else if(strEql(ch, "color"))
                    {
                        print("\n00 - Black\n");
						print("\n01 - Blue\n");
						print("\n02 - Green\n");
						print("\n03 - Cyan\n");
						print("\n04 - Red\n");
						print("\n05 - Magenta\n");
						print("\n06 - Brown\n");
						print("\n07 - Grey\n");
						print("\n08 - Dark grey\n");
						print("\n09 - Bright blue\n");
						print("\n0A - Bright green\n");
						print("\n0B - Bright cyan\n");
						print("\n0C - Pink\n");
						print("\n0D - Bright magenta\n");
						print("\n0E - Yellow\n");
						print("\n0F - White\n");
						print("\n\n");
						print("\n\n");
						print("\nColor: \n");
						ctc(readStr());
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
					else if(strEql(ch, "rfputil"))
                    {
						print("\n\n");
						string port;
						port = readStr();
						print("\n\n");
						print(inportb(port));
                    }
					else if(strEql(ch, "stputil"))
                    {
						print("\n\n");
						string port;
						port = readStr();
						string data;
						data = readStr();
						print("\n\n");
						outportb(port, data);
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
