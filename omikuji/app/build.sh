rm -rf ./build
cmake -S . -B ./build -DCMAKE_PREFIX_PATH=../goma
cmake --build ./build
