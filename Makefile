CC = g++

TARGET = asm65
OBJ = asm65.o tokenize.o
FLAG = -Wall

$(TARGET): $(OBJ) Makefile
	$(CC) $(FLAG) -o $(TARGET) $(OBJ)

%.o: %.cpp Makefile
	$(CC) $*.cpp -c -o $*.OBJ

clean:
	del $(OBJ)