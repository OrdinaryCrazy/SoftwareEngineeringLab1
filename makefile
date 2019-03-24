
CXX = g++

TARGET = Wordlist
LIBS = 	defaultCase.h\
		specifiedHeadOrTail.h\
		specifiedWordNumbers.h

$(TARGET): 	main.cpp\
			$(LIBS)	
	@ $(CXX) $< -o $@ -std=c++11 --static

all: $(TARGET)

clean:
	@ rm $(TARGET)

