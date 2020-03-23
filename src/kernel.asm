bits    32
section         .text
    align   4
    dd      0x1BADB002
    dd      0x00
    dd      - (0x1BADB002+0x00)   
global start
extern kmain

global_descriptor_table:
    dw gdt_end - gdt_start - 1	; GDT size
    dd gdt_start		        ; GDT start

gdt_start:

null_descr:
    dw 0x0000			; Limit
    dw 0x0000			; Base (low 16 bits)
    db 0x00			    ; Base (mid 8 bits)
    db 00000000b		; Access
    db 00000000b		; Granularity
    db 0x00			    ; Base (high 8 bits)

unreal_code:
    dw 0xffff			; Limit
    dw 0x0000			; Base (low 16 bits)
    db 0x00			    ; Base (mid 8 bits)
    db 10011010b		; Access
    db 10001111b		; Granularity
    db 0x00			    ; Base (high 8 bits)

unreal_data:
    dw 0xffff			; Limit
    dw 0x0000			; Base (low 16 bits)
    db 0x00			    ; Base (mid 8 bits)
    db 10010010b		; Access
    db 10001111b		; Granularity
    db 0x00			    ; Base (high 8 bits)

gdt_end:



start:
	jmp enter_unreal

; Load the global desctriptor table
; then we will unload pm, without unloading this guy,
; so we'll be in "unreal" mode.

enter_unreal:
    cli

    lgdt [global_descriptor_table]

    ; Enter protected mode
    mov eax, cr0
    or eax, 00000001b
    mov cr0, eax

    mov eax, cr0
    and eax, 11111110b
    mov cr0, eax

    mov ax, 0x1000
    mov ss, ax
    mov sp, 0xfff0

    ; Now we are officially in unreal mode, so we can reenable interrupts and continue in the main file
    sti

    mov ax, 0x2000
    mov es, ax
    mov ax, 0x04
    xor bx, bx
    mov cx, 0x40

    jmp lk
	
lk:
	cli
	call kmain
	hlt
