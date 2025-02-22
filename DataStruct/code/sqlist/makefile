# 定义编译器和编译选项
CC = gcc
CFLAGS = -Wall -I.  # -I. 表示包含当前目录的头文件

# 定义目标文件和可执行文件
TARGETS = sqlistTest.exe unionlistTest.exe
OBJS_SQLIST = main.o sqlist.o
OBJS_UNIONLIST = unionlist.o sqlist.o

# 默认目标：编译所有可执行文件
all: $(TARGETS)

# 生成 sqlistTest.exe
sqlistTest.exe: $(OBJS_SQLIST)
	$(CC) $(CFLAGS) -o sqlistTest.exe $(OBJS_SQLIST)

# 生成 unionlistTest.exe
unionlistTest.exe: $(OBJS_UNIONLIST)
	$(CC) $(CFLAGS) -o unionlistTest.exe $(OBJS_UNIONLIST)

# 编译 main.c
main.o: main.c sqlist.h
	$(CC) $(CFLAGS) -c main.c

# 编译 sqlist.c
sqlist.o: sqlist.c sqlist.h
	$(CC) $(CFLAGS) -c sqlist.c

# 编译 unionlist.c
unionlist.o: unionlist.c sqlist.h
	$(CC) $(CFLAGS) -c unionlist.c

# 清理生成的文件
clean:
	del /f $(OBJS_SQLIST) $(OBJS_UNIONLIST) $(TARGETS)