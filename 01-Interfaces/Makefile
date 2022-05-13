# Variables
CC			= gcc
CFLAGS	= -Wall -Wextra -std=c18


all: TablasDeConversion

TablasDeConversion: TablasDeConversion.o Conversion.o
	$(CC) Conversion.o TablasDeConversion.o -o TablasDeConversion

TablasDeConversion.o: TablasDeConversion.c Conversion.h
	$(CC) $(CFLAGS) -c TablasDeConversion.c 

Conversion.o: Conversion.c Conversion.h
	$(CC) $(CFLAGS) -c Conversion.c

test: ConversionTest

ConversionTest: Conversion.o ConversionTest.o
	$(CC) Conversion.o ConversionTest.o -o ConversionTest

ConversionTest.o: ConversionTest.c Conversion.h
	$(CC) -c ConversionTest.c

clean:
	rm -f TablasDeConversion
	rm -f ConversionTest
	rm -f Conversion.o
	rm -f TablasDeConversion.o
	rm -f ConversionTest.o
