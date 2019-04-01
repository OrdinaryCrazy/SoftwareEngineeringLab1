
CXX = g++

TARGET = Wordlist
LIBS = 	Core/CoreImplement.h\
		Core/exception.h\

$(TARGET): main.cpp\
		Core/CoreImplement.cpp\
			$(LIBS)	
	@ $(CXX) $< -o $@ -std=c++11 --static

all: $(TARGET)

clean:
	@ rm $(TARGET)

