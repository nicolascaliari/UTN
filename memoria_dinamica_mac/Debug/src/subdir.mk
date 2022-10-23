################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/Cliente.c \
../src/memoria_dinamica_mac.c \
../src/utn.c 

C_DEPS += \
./src/Cliente.d \
./src/memoria_dinamica_mac.d \
./src/utn.d 

OBJS += \
./src/Cliente.o \
./src/memoria_dinamica_mac.o \
./src/utn.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Cliente.d ./src/Cliente.o ./src/memoria_dinamica_mac.d ./src/memoria_dinamica_mac.o ./src/utn.d ./src/utn.o

.PHONY: clean-src

