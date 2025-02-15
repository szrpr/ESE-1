include sources.mk
PLATFORM ?= HOST
ifeq ($(PLATFORM),MSP432)
	LINKER_FILE = ../msp432p401r.lds
	SOURCES = $(SOURCES_COMMON) $(SOURCES_MSP432)
	INCLUDES = $(INCLUDES_COMMON) $(INCLUDES_MSP432)
	SIZE =
	CPU = cortex-m4
	ARCH = armv7e-m
	SPECS = nosys.specs
	CC = arm-none-eabi-gcc
	LD = arm-none-eabi-ld
	CPPFLAGS = -DMSP432 \
		   $(INCLUDES)
	CFLAGS = -Wall \
		 -Werror \
		 -g \
		 -O0 \
		 -std=c99 \
		 -mcpu=$(CPU) \
		 -march=$(ARCH) \
		 -mthumb \
		 -mfloat-abi=hard \
		 -mfpu=fpv4-sp-d16 \
		 --specs=$(SPECS) 
	LDFLAGS = -T$(LINKER_FILE) \
		  -Wl,-Map=c1m2.map 
else ifeq ($(PLATFORM),HOST)
	SOURCES = $(SOURCES_COMMON)
	INCLUDES = $(INCLUDES_COMMON)
	SIZE = size
	CC = gcc
	CPPFLAGS = -DHOST \
		   $(INCLUDES)
	CFLAGS = -Wall \
		 -Werror \
		 -g \
		 -O0 \
		 -std=c99 
	LDFLAGS = -Wl,-Map=c1m2.map
else
	$(error Unkown platform $(PLATFORM))
endif

#This flag (-mgeneral-regs-only) is only used in the 
#interrupts_msp432p401r_gcc.c file because this file contains
#the hardware interrupt service routines and accesses
#the MSP432 specific registers. 
#However, the other source files contain generic 
#C code and do not need this flag.

interrupts_msp432p401r_gcc.o: interrupts_msp432p401r_gcc.c
	$(CC) $(CPPFLAGS) $(CFLAGS) \
		-mgeneral-regs-only -c \
		interrupts_msp432p401r_gcc.c -o \
		interrupts_msp432p401r_gcc.o
%.i: %.c
	$(CC) $(CPPFLAGS) -E $< -o $@
%.asm: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -S $< -o $@
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

.PHONY: compile-all
compile-all: $(SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
.PHONY: build
OBJECTS = $(SOURCES:.c=.o)
build: $(OBJECTS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o c1m2 $(OBJECTS)
%.o: %.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
DEPENDS = $(SOURCES:.c=.d)
%.d:%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -M $< > $@
-include $(DEPENDS)

.PHONY: clean
clean:
	rm -f  *.o *.i *.asm *.out *.map *.d c1m2
