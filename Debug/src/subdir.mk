################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AND1.cpp \
../src/ArrayMultiplier.cpp \
../src/CPA.cpp \
../src/CSA.cpp \
../src/FullAdder.cpp \
../src/sc_main.cpp 

CPP_DEPS += \
./src/AND1.d \
./src/ArrayMultiplier.d \
./src/CPA.d \
./src/CSA.d \
./src/FullAdder.d \
./src/sc_main.d 

OBJS += \
./src/AND1.o \
./src/ArrayMultiplier.o \
./src/CPA.o \
./src/CSA.o \
./src/FullAdder.o \
./src/sc_main.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -I"C:\cygwin64\sysclibs\include" -O0 -g3 -Wall -c -fmessage-length=0 -std=c++14 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/AND1.d ./src/AND1.o ./src/ArrayMultiplier.d ./src/ArrayMultiplier.o ./src/CPA.d ./src/CPA.o ./src/CSA.d ./src/CSA.o ./src/FullAdder.d ./src/FullAdder.o ./src/sc_main.d ./src/sc_main.o

.PHONY: clean-src

