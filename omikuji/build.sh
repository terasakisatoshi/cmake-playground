rm -rf build ${PWD}/goma
cmake -S . -B ./build
cmake --build ./build --config=Release
cmake --install ./build --prefix=${PWD}/goma
