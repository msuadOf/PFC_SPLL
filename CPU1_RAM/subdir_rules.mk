################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
build-730853167: ../c2000.syscfg
	@echo 'Building file: "$<"'
	@echo 'Invoking: SysConfig'
	"D:/Program/ti/sysconfig_1.16.2/sysconfig_cli.bat" -s "D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/.metadata/sdk.json" -d "F28003x" --script "E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/c2000.syscfg" -o "syscfg" --package 100PZ --part F28003x_100PZ --compiler ccs
	@echo 'Finished building: "$<"'
	@echo ' '

syscfg/board.c: build-730853167 ../c2000.syscfg
syscfg/board.h: build-730853167
syscfg/board.cmd.genlibs: build-730853167
syscfg/board.opt: build-730853167
syscfg/pinmux.csv: build-730853167
syscfg/epwm.dot: build-730853167
syscfg/adc.dot: build-730853167
syscfg/c2000ware_libraries.cmd.genlibs: build-730853167
syscfg/c2000ware_libraries.opt: build-730853167
syscfg/c2000ware_libraries.c: build-730853167
syscfg/c2000ware_libraries.h: build-730853167
syscfg/clocktree.h: build-730853167
syscfg/: build-730853167

syscfg/%.obj: ./syscfg/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --idiv_support=idiv0 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O2 --opt_for_speed=3 --fp_mode=relaxed --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1" --include_path="D:/Program/ti/ccs1220/C2000Ware_4_03_00_00" --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/device" --include_path="D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/driverlib/f28003x/driverlib" --include_path="D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="syscfg/$(basename $(<F)).d_raw" --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_RAM/syscfg" --obj_directory="syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --idiv_support=idiv0 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O2 --opt_for_speed=3 --fp_mode=relaxed --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1" --include_path="D:/Program/ti/ccs1220/C2000Ware_4_03_00_00" --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/device" --include_path="D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/driverlib/f28003x/driverlib" --include_path="D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_RAM/syscfg" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


