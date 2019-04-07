#ifndef UTIL_H
#define UTIL_H

#include "types.h"
#include "system.h"
#include "string.h"


bool ReceivedIRQ = false;

enum FloppyRegisters
{
   STATUS_REGISTER_A                = 0x3F0, // read-only
   STATUS_REGISTER_B                = 0x3F1, // read-only
   DIGITAL_OUTPUT_REGISTER          = 0x3F2,
   TAPE_DRIVE_REGISTER              = 0x3F3,
   MAIN_STATUS_REGISTER             = 0x3F4, // read-only
   DATARATE_SELECT_REGISTER         = 0x3F4, // write-only
   DATA_FIFO                        = 0x3F5,
   DIGITAL_INPUT_REGISTER           = 0x3F7, // read-only
   CONFIGURATION_CONTROL_REGISTER   = 0x3F7  // write-only
};

void lba_2_chs(uint32_t lba, uint16_t* cyl, uint16_t* head, uint16_t* sector)
{
    *cyl    = lba / (2 * FLOPPY_144_SECTORS_PER_TRACK);
    *head   = ((lba % (2 * FLOPPY_144_SECTORS_PER_TRACK)) / FLOPPY_144_SECTORS_PER_TRACK);
    *sector = ((lba % (2 * FLOPPY_144_SECTORS_PER_TRACK)) % FLOPPY_144_SECTORS_PER_TRACK + 1);
}

// This function gets called when an IRQ6 is generated.
void FloppyHandler()
{
   ReceivedIRQ = true;
}
 
// Waits for an IRQ to be issued.
void WaitForIRQ()
{
   ReceivedIRQ = false;
   while(!ReceivedIRQ) ;
}

void ResetFloppy()
{
    ReceivedIRQ = false; 	// This will prevent the FDC from being faster than us!
 
    // Enter, then exit reset mode.
    outb(Controller.DOR,0x00);
    outb(Controller.DOR,0x0C);
 
    while(!ReceivedIRQ) ;	// Wait for the IRQ handler to run
 
    // sense interrupt -- 4 of them typically required after a reset
    for (i = 4 ; i > 0 ; --i);
    {
       send_command(SENSE_INTERRUPT);
       read_data_byte();
       read_data_byte();
    }
 
    outb(controller.CCR,0x00);	// 500Kbps -- for 1.44M floppy
 
    // configure the drive
    send_command(SPECIFY);
    outportb(Controller.FIFO, steprate_headunload);
    outportb(Controller.FIFO, headload_ndma);
}