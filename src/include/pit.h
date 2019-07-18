#ifndef SPEAKER_H
#define SPEAKER_H

#include "screen.h"
#include "kb.h"
#include "string.h"
#include "system.h"
#include "util.h"
#include "power.h"
#include "isr.h"
#include "idt.h"
#include "idt.h"
#include "ioapic.h"

struct TimerBlock {
    EXCHANGE e;
    uint32 CountDown;
} timerblocks[20];
 
void TimerIRQ(void) /* called from Assembly */
{
    uint8_t i;
 
    for (i = 0; i < 20; i++)
        if (timerblocks[i].CountDown > 0) {
            timerblocks[i].CountDown--;
            if (timerblocks[i].CountDown == 0)
                SendMessage(timerblocks[i].e, COUNTDOWN_DONE_MESSAGE);
        }
}
 
void Sleep(uint32 delay)
{
    struct TimerBlock *t;
 
    if ((t = findTimerBlock()) == nil)
        return;
    t->CountDown = delay;
    WaitForMessageFrom(t->e = getCrntExch());
}
#endif
