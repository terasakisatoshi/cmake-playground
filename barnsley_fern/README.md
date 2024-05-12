# Usage

```console
$ rm -rf ./build out.csv && cmake -S . -B ./build && cmake --build ./build && ./build/bin/BarnsleyFern > out.csv
-- The C compiler identification is AppleClang 15.0.0.15000309
-- The CXX compiler identification is AppleClang 15.0.0.15000309
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.6s)
-- Generating done (0.0s)
-- Build files have been written to: ./fractal/barnsley_fern/build
[ 16%] Building CXX object src/CMakeFiles/fern.dir/fern.cpp.o
[ 33%] Linking CXX static library libfern.a
[ 33%] Built target fern
[ 50%] Building CXX object src/CMakeFiles/affine.dir/affine.cpp.o
[ 66%] Linking CXX static library libaffine.a
[ 66%] Built target affine
[ 83%] Building CXX object CMakeFiles/BarnsleyFern.dir/main.cpp.o
[100%] Linking CXX executable bin/BarnsleyFern
[100%] Built target BarnsleyFern
$ ls
out.csv
$ julia vis.jl
```
