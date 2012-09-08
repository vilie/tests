CXXFLAGS = -Wall -Os -std=c++11
FILES = hello tests_0x
all: $(FILES)
clean:
	rm -rf $(FILES)
