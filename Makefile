# makefile

CC = g++
ENCODE = GBK # 编码方式，MS-DOS下使用GBK
CFLAG = -Wall -m64 -O2 -std=c++17 -fexec-charset=$(ENCODE)
INC = -I./h # 包含文件
OBJ = ./obj/
SRC = ./src/

all:clean obj init debug

obj:cities.o saveload.o

init:mapinit

debug:mapdebug

clean:cleanexe cleanobj

cleanexe:
	del /f *.exe

cleanobj:
	cd $(OBJ)
	del /f *.o
	cd ..

mapinit:
	$(CC) $(CFLAG) $(INC) ./initial/mapinit.cpp\
	 $(OBJ)cities.o $(OBJ)saveload.o -o mapinit.exe

mapdebug:
	$(CC) $(CFLAG) $(INC) ./debug/mapdebug.cpp\
	 $(OBJ)cities.o $(OBJ)saveload.o -o mapdebug.exe

cities.o:
	$(CC) $(CFLAG) -c $(INC) $(SRC)cities.cpp -o $(OBJ)cities.o

saveload.o:
	$(CC) $(CFLAG) -c $(INC) $(SRC)saveload.cpp -o $(OBJ)saveload.o