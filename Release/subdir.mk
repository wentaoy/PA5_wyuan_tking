################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Customer.cpp \
../CustomerArrival.cpp \
../CustomerEvent.cpp \
../Event.cpp \
../EventQueue.cpp \
../Teller.cpp \
../TellerQueue.cpp \
../qSim.cpp 

O_SRCS += \
../qSim.o 

OBJS += \
./Customer.o \
./CustomerArrival.o \
./CustomerEvent.o \
./Event.o \
./EventQueue.o \
./Teller.o \
./TellerQueue.o \
./qSim.o 

CPP_DEPS += \
./Customer.d \
./CustomerArrival.d \
./CustomerEvent.d \
./Event.d \
./EventQueue.d \
./Teller.d \
./TellerQueue.d \
./qSim.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


