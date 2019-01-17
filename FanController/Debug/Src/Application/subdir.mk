################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Src/Application/Application.cpp 

OBJS += \
./Src/Application/Application.o 

CPP_DEPS += \
./Src/Application/Application.d 


# Each subdirectory must supply rules for building sources it contributes
Src/Application/%.o: ../Src/Application/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: MCU G++ Compiler'
	@echo $(PWD)
	arm-none-eabi-g++ -mcpu=cortex-m3 -mthumb -mfloat-abi=soft -std=c++1y '-D__weak=__attribute__((weak))' '-D__packed=__attribute__((__packed__))' -DUSE_HAL_DRIVER -DSTM32F103xB -I"C:/Project/Datalogger/FanController/Inc" -I"C:/Project/Datalogger/FanController/Src" -I"C:/Project/Datalogger/FanController/Drivers/STM32F1xx_HAL_Driver/Inc" -I"C:/Project/Datalogger/FanController/Drivers/STM32F1xx_HAL_Driver/Inc/Legacy" -I"C:/Project/Datalogger/FanController/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"C:/Project/Datalogger/FanController/Drivers/CMSIS/Include"  -Og -g3 -Wall -fmessage-length=0 -ffunction-sections -c -fno-exceptions -fno-rtti -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


