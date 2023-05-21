################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/at24.c \
../Core/Src/ili9488.c \
../Core/Src/ir_remote.c \
../Core/Src/lighting.c \
../Core/Src/main.c \
../Core/Src/rgb_hsv.c \
../Core/Src/stm32f4xx_hal_msp.c \
../Core/Src/stm32f4xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32f4xx.c \
../Core/Src/ws2812.c \
../Core/Src/xpt2046.c 

OBJS += \
./Core/Src/at24.o \
./Core/Src/ili9488.o \
./Core/Src/ir_remote.o \
./Core/Src/lighting.o \
./Core/Src/main.o \
./Core/Src/rgb_hsv.o \
./Core/Src/stm32f4xx_hal_msp.o \
./Core/Src/stm32f4xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32f4xx.o \
./Core/Src/ws2812.o \
./Core/Src/xpt2046.o 

C_DEPS += \
./Core/Src/at24.d \
./Core/Src/ili9488.d \
./Core/Src/ir_remote.d \
./Core/Src/lighting.d \
./Core/Src/main.d \
./Core/Src/rgb_hsv.d \
./Core/Src/stm32f4xx_hal_msp.d \
./Core/Src/stm32f4xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32f4xx.d \
./Core/Src/ws2812.d \
./Core/Src/xpt2046.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F401xC -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/at24.cyclo ./Core/Src/at24.d ./Core/Src/at24.o ./Core/Src/at24.su ./Core/Src/ili9488.cyclo ./Core/Src/ili9488.d ./Core/Src/ili9488.o ./Core/Src/ili9488.su ./Core/Src/ir_remote.cyclo ./Core/Src/ir_remote.d ./Core/Src/ir_remote.o ./Core/Src/ir_remote.su ./Core/Src/lighting.cyclo ./Core/Src/lighting.d ./Core/Src/lighting.o ./Core/Src/lighting.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/rgb_hsv.cyclo ./Core/Src/rgb_hsv.d ./Core/Src/rgb_hsv.o ./Core/Src/rgb_hsv.su ./Core/Src/stm32f4xx_hal_msp.cyclo ./Core/Src/stm32f4xx_hal_msp.d ./Core/Src/stm32f4xx_hal_msp.o ./Core/Src/stm32f4xx_hal_msp.su ./Core/Src/stm32f4xx_it.cyclo ./Core/Src/stm32f4xx_it.d ./Core/Src/stm32f4xx_it.o ./Core/Src/stm32f4xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32f4xx.cyclo ./Core/Src/system_stm32f4xx.d ./Core/Src/system_stm32f4xx.o ./Core/Src/system_stm32f4xx.su ./Core/Src/ws2812.cyclo ./Core/Src/ws2812.d ./Core/Src/ws2812.o ./Core/Src/ws2812.su ./Core/Src/xpt2046.cyclo ./Core/Src/xpt2046.d ./Core/Src/xpt2046.o ./Core/Src/xpt2046.su

.PHONY: clean-Core-2f-Src

