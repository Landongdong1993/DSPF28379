################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
F2837xD_CodeStartBranch.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/source/F2837xD_CodeStartBranch.asm $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_CodeStartBranch.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_DefaultISR.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/source/F2837xD_DefaultISR.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_DefaultISR.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_EPwm.obj: ../F2837xD_EPwm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_EPwm.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_GlobalVariableDefs.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/source/F2837xD_GlobalVariableDefs.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_GlobalVariableDefs.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_Gpio.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/source/F2837xD_Gpio.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_Gpio.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_Ipc.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/source/F2837xD_Ipc.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_Ipc.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_Ipc_Driver_Util.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/source/F2837xD_Ipc_Driver_Util.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_Ipc_Driver_Util.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_PieCtrl.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/source/F2837xD_PieCtrl.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_PieCtrl.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_PieVect.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/source/F2837xD_PieVect.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_PieVect.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

F2837xD_SysCtrl.obj: C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/source/F2837xD_SysCtrl.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="F2837xD_SysCtrl.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

acpu1.obj: ../acpu1.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="acpu1.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

inital.obj: ../inital.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="inital.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

svpwm.obj: ../svpwm.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/bin/cl2000" -v28 -ml -mt --vcu_support=vcu2 --cla_support=cla1 --float_support=fpu32 --tmu_support=tmu0 --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-c2000_15.12.1.LTS/include" --include_path="C:/ti/controlSUITE/libs/utilities/boot_rom/F2837x_revb/revb_rom_sources/F2837x_bootROM/cpu01-bootROM/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_common/include" --include_path="C:/ti/controlSUITE/device_support/F2837xD/v210/F2837xD_headers/include" --include_path="C:/ti/controlSUITE/libs/math/FPUfastRTS/V100/include" --include_path="C:/tidcs/c28/IQmath/v15a/include" --include_path="C:/tidcs/c28/solar/v1.2/float/include" --advice:performance=all -g --define=CPU1 --display_error_number --diag_warning=225 --preproc_with_compile --preproc_dependency="svpwm.d" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


