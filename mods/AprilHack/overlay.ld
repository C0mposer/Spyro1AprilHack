__heap_base = __ovr_end;

__ovr_start = 0x8001d718;

SECTIONS {
    OVERLAY __ovr_start : SUBALIGN(4)
    {
        .asmhooks
        {
            . = . + 0x16720;
            KEEP(asm/hook.o(.text*))
            KEEP(asm/hook.o(.rodata*))
            KEEP(asm/hook.o(.sdata*))
            KEEP(asm/hook.o(.data*))
            KEEP(asm/hook.o(.sbss*))
            KEEP(asm/hook.o(.bss*))
            KEEP(asm/hook.o(.ctors))
            
            . = ALIGN(4);
            __ovr_end = .;
        }
        .asmgamestate_fairy_fixs
        {
            . = . + 0xf5b0;
            KEEP(asm/gamestate_fairy_fix.o(.text*))
            KEEP(asm/gamestate_fairy_fix.o(.rodata*))
            KEEP(asm/gamestate_fairy_fix.o(.sdata*))
            KEEP(asm/gamestate_fairy_fix.o(.data*))
            KEEP(asm/gamestate_fairy_fix.o(.sbss*))
            KEEP(asm/gamestate_fairy_fix.o(.bss*))
            KEEP(asm/gamestate_fairy_fix.o(.ctors))
            
            . = ALIGN(4);
            __ovr_end = .;
        }
        .srcmainc
        {
            KEEP(src/main.o(.text*))
            KEEP(src/main_updates.o(.text*))
            KEEP(src/main.o(.rodata*))
            KEEP(src/main_updates.o(.rodata*))
            KEEP(src/main.o(.sdata*))
            KEEP(src/main_updates.o(.sdata*))
            KEEP(src/main.o(.data*))
            KEEP(src/main_updates.o(.data*))
            KEEP(src/main.o(.sbss*))
            KEEP(src/main_updates.o(.sbss*))
            KEEP(src/main.o(.bss*))
            KEEP(src/main_updates.o(.bss*))
            KEEP(src/main.o(.ctors))
            KEEP(src/main_updates.o(.ctors))
            
            . = ALIGN(4);
            __ovr_end = .;
        }
    }
}
