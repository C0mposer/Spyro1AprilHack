MODDIR := $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
TARGET = mod

SRCS = asm/hook.s asm/gamestate_fairy_fix.s src/main.c src/main_updates.c 
CPPFLAGS = -DBUILD=94228
LDSYMS = -T$(MODDIR)../../symbols/symbols.txt -T$(MODDIR)../../symbols/funcs.txt 
USE_FUNCTION_SECTIONS ?= true
DISABLE_FUNCTION_REORDER ?= false
USE_PSYQ ?= false
OVERLAYSECTION ?= .asmhooks .asmgamestate_fairy_fixs .srcmainc 
OVR_START_ADDR = 0x8001d718
OVERLAYSCRIPT = overlay.ld
BUILDDIR = $(MODDIR)output/
SRCINCLUDEDIR = $(MODDIR)src/
GAMEINCLUDEDIR = $(MODDIR)../../include/
EXTRA_CC_FLAGS = -Os -g

include ../../../common.mk
