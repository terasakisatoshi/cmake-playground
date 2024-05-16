.PHONY: all run build test
all: build

build: *.cpp
	# cmake -S . -B ./build
	# cmake --build ./build
	bash build.sh

test: build
	ctest --test-dir ./build
