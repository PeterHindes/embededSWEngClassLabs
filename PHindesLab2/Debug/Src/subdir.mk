################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ApplicationCode.c \
../Src/GPIO_Driver.c \
../Src/LED_Driver.c \
../Src/Scheduler.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ApplicationCode.o \
./Src/GPIO_Driver.o \
./Src/LED_Driver.o \
./Src/Scheduler.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ApplicationCode.d \
./Src/GPIO_Driver.d \
./Src/LED_Driver.d \
./Src/Scheduler.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ApplicationCode.cyclo ./Src/ApplicationCode.d ./Src/ApplicationCode.o ./Src/ApplicationCode.su ./Src/GPIO_Driver.cyclo ./Src/GPIO_Driver.d ./Src/GPIO_Driver.o ./Src/GPIO_Driver.su ./Src/LED_Driver.cyclo ./Src/LED_Driver.d ./Src/LED_Driver.o ./Src/LED_Driver.su ./Src/Scheduler.cyclo ./Src/Scheduler.d ./Src/Scheduler.o ./Src/Scheduler.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

