#******************************************************************************
# Copyright (C) 2025 by Sezer Kılıç - Coursera
#
# Redistribution, modification, or use of this software in source or binary
# forms is permitted as long as this copyright notice is retained. Users are 
# permitted to modify and use this project to learn about embedded software. 
# Sezer Kılıç is not liable for any misuse of this material. 
#*****************************************************************************

# Add your Source files to this variable
SOURCES_COMMON = ./main.c \
		 ./memory.c
SOURCES_MSP432 = ./startup_msp432p401r_gcc.c \
		 ./interrupts_msp432p401r_gcc.c \
		 ./system_msp432p401r.c

# Add your include paths to this variable
INCLUDES_COMMON = -I../include/common
INCLUDES_MSP432 = -I../include/CMSIS \
		  -I../include/msp432	

