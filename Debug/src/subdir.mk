################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Date.cpp \
../src/ErrorClass.cpp \
../src/SMUser.cpp \
../src/SMUserPost.cpp \
../src/ShahidAsad_Ch17Project_FinalProject.cpp 

CPP_DEPS += \
./src/Date.d \
./src/ErrorClass.d \
./src/SMUser.d \
./src/SMUserPost.d \
./src/ShahidAsad_Ch17Project_FinalProject.d 

OBJS += \
./src/Date.o \
./src/ErrorClass.o \
./src/SMUser.o \
./src/SMUserPost.o \
./src/ShahidAsad_Ch17Project_FinalProject.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/Date.d ./src/Date.o ./src/ErrorClass.d ./src/ErrorClass.o ./src/SMUser.d ./src/SMUser.o ./src/SMUserPost.d ./src/SMUserPost.o ./src/ShahidAsad_Ch17Project_FinalProject.d ./src/ShahidAsad_Ch17Project_FinalProject.o

.PHONY: clean-src

