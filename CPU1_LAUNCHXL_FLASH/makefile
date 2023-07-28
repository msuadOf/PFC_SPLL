################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS

GEN_OPTS__FLAG := --cmd_file="syscfg/board.opt" --cmd_file="syscfg/c2000ware_libraries.opt" 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./PID_Controller.obj" \
"./syscfg/board.obj" \
"./syscfg/c2000ware_libraries.obj" \
"./pfc_hal.obj" \
"./spll_pfc_main.obj" \
"./spll_sogi.obj" \
"./bsp/bsp_debugSCI.obj" \
"./bsp/launchxl_sci_io_driverlib.obj" \
"./device/device.obj" \
"./device/f28003x_codestartbranch.obj" \
"../28003x_generic_flash_lnk.cmd" \
"D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/driverlib/f28003x/driverlib/ccs/Debug/driverlib.lib" \
"../rts2800_fpu32_eabi.lib" \
"../rts2800_fpu32_fast_supplement_eabi.lib" \
"../rts2800_fpu64_eabi.lib" \
"../rts2800_ml_eabi.lib" \
$(GEN_CMDS__FLAG) \
-lc2000ware_libraries.cmd.genlibs \
-llibc.a \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include bsp/subdir_vars.mk
-include device/subdir_vars.mk
-include subdir_rules.mk
-include bsp/subdir_rules.mk
-include device/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
my_driverlib_SPLL_PFC_2023_7_27_1.out \

EXE_OUTPUTS__QUOTED += \
"my_driverlib_SPLL_PFC_2023_7_27_1.out" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "my_driverlib_SPLL_PFC_2023_7_27_1.out"

# Tool invocations
my_driverlib_SPLL_PFC_2023_7_27_1.out: $(OBJS) $(CMD_SRCS) $(LIB_SRCS) $(GEN_CMDS)
	@echo 'Building target: "$@"'
	@echo 'Invoking: C2000 Linker'
	"D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --idiv_support=idiv0 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O4 --opt_for_speed=4 --fp_mode=relaxed --advice:performance=all --define=DEBUG --define=_FLASH --define=_LAUNCHXL_F280039C --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi -z -m"my_driverlib_SPLL_PFC_2023_7_27_1.map" --heap_size=0x100 --stack_size=0x200 --warn_sections -i"E:/TI/C2000/F280039C_LaunchPad/workplace_lab" -i"D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/lib" -i"D:/Program/ti/ccs1220/C2000Ware_4_03_00_00" -i"E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/syscfg" -i"D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --reread_libs --define=_FLASH --diag_wrap=off --display_error_number --xml_link_info="my_driverlib_SPLL_PFC_2023_7_27_1_linkInfo.xml" --entry_point=code_start --rom_model -o "my_driverlib_SPLL_PFC_2023_7_27_1.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '
	@$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(GEN_MISC_FILES__QUOTED)$(GEN_FILES__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "PID_Controller.obj" "syscfg\board.obj" "syscfg\c2000ware_libraries.obj" "pfc_hal.obj" "spll_pfc_main.obj" "spll_sogi.obj" "bsp\bsp_debugSCI.obj" "bsp\launchxl_sci_io_driverlib.obj" "device\device.obj" "device\f28003x_codestartbranch.obj" 
	-$(RM) "PID_Controller.d" "syscfg\board.d" "syscfg\c2000ware_libraries.d" "pfc_hal.d" "spll_pfc_main.d" "spll_sogi.d" "bsp\bsp_debugSCI.d" "bsp\launchxl_sci_io_driverlib.d" "device\device.d" 
	-$(RM) "device\f28003x_codestartbranch.d" 
	-$(RMDIR) $(GEN_MISC_DIRS__QUOTED)
	-@echo 'Finished clean'
	-@echo ' '

post-build:
	-if 0 == 1  mkdir "E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/simulation"
	-if 0 == 1  C:/TDM-GCC-64/bin/g++  -c -DCLB_SIM -ID:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc-2.3.3/src -ID:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/include/type3 -IE:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1 -IC:/TDM-GCC-64/bin/include -Og -g -gdwarf-3 -gstrict-dwarf -Wall -MMD -MP -MFE:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/simulation/clb_sim.d -MTE:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/simulation/clb_sim.o -IE:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/syscfg   -fno-threadsafe-statics  -oE:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/simulation/clb_sim.o E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/syscfg/clb_sim.cpp
	-if 0 == 1  C:/TDM-GCC-64/bin/g++ -DCLB_SIM -Og -g -gdwarf-3 -gstrict-dwarf -Wall -Wl,-Map,E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/simulation/simulation_output.map -LD:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc-2.3.3/build/src -oE:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/simulation/simulation_output.exe E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/simulation/clb_sim.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_FSM_SC_model.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_HLC_SC_model.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_LUT4_SC_model.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_OutputLUT_SC_model.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_counter_SC_model.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_counter_top_SC_model.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_FSM_top_SC_model.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_LUT4_top_SC_model.o D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/systemc/src/type3/CLB_OutputLUT_top_SC_model.o  -Wl,--start-group -lsystemc -Wl,--end-group
	-if 0 == 1  "./simulation/simulation_output.exe"
	-if 0 == 1  D:/Program/ti/ccs1220/ccs/tools/node/node.exe "D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/dot_file_libraries/clbDotUtility.js"  "D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/utilities/clb_tool/clb_syscfg/" "E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/syscfg" "E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/syscfg/clb.dot"
	-if 0 == 1  mkdir "E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/diagrams"
	-if 0 == 1  D:/Program/ti/ccs1220/ccs/tools/node/node.exe "D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/driverlib/.meta/generate_diagrams.js" "D:/Program/ti/ccs1220/C2000Ware_4_03_00_00" "E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/diagrams" "E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_LAUNCHXL_FLASH/syscfg"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

