################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Customer.cpp \
../CustomerArrival.cpp \
../CustomerComplete.cpp \
../CustomerEvent.cpp \
../Event.cpp \
../EventQueue.cpp \
../Teller.cpp \
../TellerEvent.cpp \
../TellerQueue.cpp \
../TellerQueueVec.cpp \
../qSim.cpp 

O_SRCS += \
../qSim.o 

OBJS += \
./Customer.o \
./CustomerArrival.o \
./CustomerComplete.o \
./CustomerEvent.o \
./Event.o \
./EventQueue.o \
./Teller.o \
./TellerEvent.o \
./TellerQueue.o \
./TellerQueueVec.o \
./qSim.o 

CPP_DEPS += \
./Customer.d \
./CustomerArrival.d \
./CustomerComplete.d \
./CustomerEvent.d \
./Event.d \
./EventQueue.d \
./Teller.d \
./TellerEvent.d \
./TellerQueue.d \
./TellerQueueVec.d \
./qSim.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


