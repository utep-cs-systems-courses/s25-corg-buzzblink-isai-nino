OBJS    = main.o buzzer.o switches.o led.o
CPU     = msp430g2553
CFLAGS  = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLAGS = -L/opt/ti/msp430_gcc/include

# switch the compiler

CC      = msp430-elf-gcc
AS      = msp430-elf-as

all: toy.elf

# additional rules for files
toy.elf: ${OBJS} p2_interrupt_handler.o libTimer.a
	${CC} ${CFLAGS} -o $@ $^ 

load: toy.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf *~

buzzer.c: buzzer.h
switches.c: switches.h
led.c: led.h
