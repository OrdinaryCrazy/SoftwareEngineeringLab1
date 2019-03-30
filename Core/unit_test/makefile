
CXX = g++

TARGET = unit_test
LIBS = 	../defaultCase.h\
		../specifiedHeadOrTail.h\
		../specifiedWordNumbers.h
		
$(TARGET): 	test.cpp\
			../CoreImplement.cpp\
			$(LIBS)	
	@ $(CXX) -fno-rtti test.cpp ../CoreImplement.cpp -o unit_test -std=c++11 --static --coverage -lgcov
	@ ./unit_test ~"Time Exceed B"
	@ gcov CoreImplement  >> gcov.line
	@ lcov -b ./ -d ./ --gcov-tool /usr/bin/gcov -c -o CoreImplement.info >> lcov.line
	@ genhtml -o gcovdir/ CoreImplement.info >> genhtml.line
	@ google-chrome ./gcovdir/index.html >> chrome.line


all: $(TARGET)

clean:
	@ rm $(TARGET)
	@ find ./ -name '*.gcno' -exec rm {} \;
	@ find ./ -name '*.info' -exec rm {} \;
	@ find ./ -name '*.gcov' -exec rm {} \;
	@ find ./ -name '*.gcda' -exec rm {} \;
	@ find ./ -name '*.line' -exec rm {} \;
	@ rm -r ./gcovdir
	@ rm solution.txt

