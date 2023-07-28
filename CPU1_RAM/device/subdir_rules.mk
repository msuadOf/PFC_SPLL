################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
device/%.obj: ../device/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --idiv_support=idiv0 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O2 --opt_for_speed=3 --fp_mode=relaxed --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1" --include_path="D:/Program/ti/ccs1220/C2000Ware_4_03_00_00" --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/device" --include_path="D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/driverlib/f28003x/driverlib" --include_path="D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="device/$(basename $(<F)).d_raw" --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_RAM/syscfg" --obj_directory="device" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

device/%.obj: ../device/%.asm $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: C2000 Compiler'
	"D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/bin/cl2000" -v28 -ml -mt --cla_support=cla2 --float_support=fpu32 --idiv_support=idiv0 --isr_save_vcu_regs=on --tmu_support=tmu0 --vcu_support=vcu0 -O2 --opt_for_speed=3 --fp_mode=relaxed --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1" --include_path="D:/Program/ti/ccs1220/C2000Ware_4_03_00_00" --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/device" --include_path="D:/Program/ti/ccs1220/C2000Ware_4_03_00_00/driverlib/f28003x/driverlib" --include_path="D:/Program/ti/ccs1220/ccs/tools/compiler/ti-cgt-c2000_22.6.0.LTS/include" --define=DEBUG --define=RAM --diag_suppress=10063 --diag_warning=225 --diag_wrap=off --display_error_number --gen_func_subsections=on --abi=eabi --preproc_with_compile --preproc_dependency="device/$(basename $(<F)).d_raw" --include_path="E:/TI/C2000/F280039C_LaunchPad/workplace_lab/my_driverlib_SPLL_PFC_2023_7_27_1/CPU1_RAM/syscfg" --obj_directory="device" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


