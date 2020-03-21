# VMOS

### Introduction

This is a small operating system written in C and Assembly.

New small update:
- Crash messages are now displayed in the COM1 port
- Fixed some GUI things

### Compiling and making an iso image

For compiling and making the disk image you need to work on Linux and make sure that you have these packages installed: `nasm`, `gcc`, `grub-mkrescue`

Compiling the OS (execute these commands IN LINUX):
```nasm -f elf32 src/kernel.asm -o o/kasm.o
gcc -m32 -c src/kernel.c -o o/kc.o -ffreestanding
ld -m elf_i386 -T link.ld -o kernel1.bin o/kasm.o o/kc.o
```

And for making a disk image:
```- rm vmos/bin/kernel1.bin
- cp kernel1.bin vmos/bin/kernel1.bin
- grub-mkrescue -o main.iso vmos
```
