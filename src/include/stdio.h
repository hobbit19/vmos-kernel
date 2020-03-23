//STDIO library
//Last modified: VMOS 1.0.4.2
//Made by VMGP

#include "vmos/system.h"
#include "vmos/util.h"
#include "vmos/screen.h"
#include "vmos/kb.h"
#include "vmos/string.h"
#include "vmos/isr.h"
#include "vmos/idt.h"
#include "vmos/serial.h"
#include "vmos/cmos.h"
#include "vmos/pit.h"

void printf(string text) {
    print(text);
}

int gets() {
    return readStr();
}