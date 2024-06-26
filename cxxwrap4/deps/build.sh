# Get Julia installation paths
CXXWRAP_PREFIX=`julia --project -e 'using CxxWrap; CxxWrap.prefix_path() |> print'`
rm -rf ./build
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=$CXXWRAP_PREFIX
cmake --build ./build --config Release -j `nproc`
