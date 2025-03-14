################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/ApplicationCode.c \
../Src/Button_Driver.c \
../Src/GPIO_Driver.c \
../Src/InterruptControl.c \
../Src/LED_Driver.c \
../Src/STM32F429i.c \
../Src/Scheduler.c \
../Src/Timer_Driver.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/ApplicationCode.o \
./Src/Button_Driver.o \
./Src/GPIO_Driver.o \
./Src/InterruptControl.o \
./Src/LED_Driver.o \
./Src/STM32F429i.o \
./Src/Scheduler.o \
./Src/Timer_Driver.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/ApplicationCode.d \
./Src/Button_Driver.d \
./Src/GPIO_Driver.d \
./Src/InterruptControl.d \
./Src/LED_Driver.d \
./Src/STM32F429i.d \
./Src/Scheduler.d \
./Src/Timer_Driver.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su Src/%.cyclo: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/ApplicationCode.cyclo ./Src/ApplicationCode.d ./Src/ApplicationCode.o ./Src/ApplicationCode.su ./Src/Button_Driver.cyclo ./Src/Button_Driver.d ./Src/Button_Driver.o ./Src/Button_Driver.su ./Src/GPIO_Driver.cyclo ./Src/GPIO_Driver.d ./Src/GPIO_Driver.o ./Src/GPIO_Driver.su ./Src/InterruptControl.cyclo ./Src/InterruptControl.d ./Src/InterruptControl.o ./Src/InterruptControl.su ./Src/LED_Driver.cyclo ./Src/LED_Driver.d ./Src/LED_Driver.o ./Src/LED_Driver.su ./Src/STM32F429i.cyclo ./Src/STM32F429i.d ./Src/STM32F429i.o ./Src/STM32F429i.su ./Src/Scheduler.cyclo ./Src/Scheduler.d ./Src/Scheduler.o ./Src/Scheduler.su ./Src/Timer_Driver.cyclo ./Src/Timer_Driver.d ./Src/Timer_Driver.o ./Src/Timer_Driver.su ./Src/main.cyclo ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.cyclo ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.cyclo ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

