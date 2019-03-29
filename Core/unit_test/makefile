
CXX = g++

TARGET = unit_test
LIBS = 	../defaultCase.h\
		../specifiedHeadOrTail.h\
		../specifiedWordNumbers.h
		
$(TARGET): 	test.cpp\
			../CoreImplement.cpp\
			$(LIBS)	
	@ $(CXX) -fno-rtti test.cpp ../CoreImplement.cpp -o unit_test -std=c++11 --static

all: $(TARGET)

clean:
	@ rm $(TARGET)

