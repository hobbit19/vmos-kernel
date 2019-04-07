cd J:/VMOS
nasm -f elf -o o/kasm.o src/kernel.asm
i586-elf-gcc -m32 -o o/kc.o -c src/kernel.c
i586-elf-ld -m elf_i386 -T link.ld -o kernel.bin o/kasm.o o/kc.o
qemu-system-i386 -kernel kernel.bin