################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/RemoteControlOpenwrt.c \
../src/gpio_ctrl.c \
../src/led_ctrl.c 

OBJS += \
./src/RemoteControlOpenwrt.o \
./src/gpio_ctrl.o \
./src/led_ctrl.o 

C_DEPS += \
./src/RemoteControlOpenwrt.d \
./src/gpio_ctrl.d \
./src/led_ctrl.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	mipsel-openwrt-linux-gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


