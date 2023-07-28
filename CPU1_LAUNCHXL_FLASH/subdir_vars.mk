################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Add inputs and outputs from these tool invocations to the build variables 
CMD_SRCS += \
../28003x_generic_flash_lnk.cmd 

SYSCFG_SRCS += \
../c2000.syscfg 

LIB_SRCS += \
D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/driverlib/f28003x/driverlib/ccs/Debug/driverlib.lib \
../rts2800_fpu32_eabi.lib \
../rts2800_fpu32_fast_supplement_eabi.lib \
../rts2800_fpu64_eabi.lib \
../rts2800_ml_eabi.lib 

C_SRCS += \
../PID_Controller.c \
./syscfg/board.c \
./syscfg/c2000ware_libraries.c \
../pfc_hal.c \
../spll_pfc_main.c \
../spll_sogi.c 

GEN_FILES += \
./syscfg/board.c \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt \
./syscfg/c2000ware_libraries.c 

GEN_MISC_DIRS += \
./syscfg/ 

C_DEPS += \
./PID_Controller.d \
./syscfg/board.d \
./syscfg/c2000ware_libraries.d \
./pfc_hal.d \
./spll_pfc_main.d \
./spll_sogi.d 

GEN_OPTS += \
./syscfg/board.opt \
./syscfg/c2000ware_libraries.opt 

OBJS += \
./PID_Controller.obj \
./syscfg/board.obj \
./syscfg/c2000ware_libraries.obj \
./pfc_hal.obj \
./spll_pfc_main.obj \
./spll_sogi.obj 

GEN_MISC_FILES += \
./syscfg/board.h \
./syscfg/board.cmd.genlibs \
./syscfg/pinmux.csv \
./syscfg/epwm.dot \
./syscfg/adc.dot \
./syscfg/c2000ware_libraries.cmd.genlibs \
./syscfg/c2000ware_libraries.h \
./syscfg/clocktree.h 

GEN_MISC_DIRS__QUOTED += \
"syscfg\" 

OBJS__QUOTED += \
"PID_Controller.obj" \
"syscfg\board.obj" \
"syscfg\c2000ware_libraries.obj" \
"pfc_hal.obj" \
"spll_pfc_main.obj" \
"spll_sogi.obj" 

GEN_MISC_FILES__QUOTED += \
"syscfg\board.h" \
"syscfg\board.cmd.genlibs" \
"syscfg\pinmux.csv" \
"syscfg\epwm.dot" \
"syscfg\adc.dot" \
"syscfg\c2000ware_libraries.cmd.genlibs" \
"syscfg\c2000ware_libraries.h" \
"syscfg\clocktree.h" 

C_DEPS__QUOTED += \
"PID_Controller.d" \
"syscfg\board.d" \
"syscfg\c2000ware_libraries.d" \
"pfc_hal.d" \
"spll_pfc_main.d" \
"spll_sogi.d" 

GEN_FILES__QUOTED += \
"syscfg\board.c" \
"syscfg\board.opt" \
"syscfg\c2000ware_libraries.opt" \
"syscfg\c2000ware_libraries.c" 

C_SRCS__QUOTED += \
"../PID_Controller.c" \
"./syscfg/board.c" \
"./syscfg/c2000ware_libraries.c" \
"../pfc_hal.c" \
"../spll_pfc_main.c" \
"../spll_sogi.c" 

SYSCFG_SRCS__QUOTED += \
"../c2000.syscfg" 


