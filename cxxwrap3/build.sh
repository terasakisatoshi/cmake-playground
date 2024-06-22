# Get Julia installation paths
julia --project -e 'using Pkg; Pkg.instantiate()'
CXXWRAP_PREFIX=`julia --project -e 'using CxxWrap; CxxWrap.prefix_path() |> print'`
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=$CXXWRAP_PREFIX
cmake --build ./build --config Release -j `nproc`

