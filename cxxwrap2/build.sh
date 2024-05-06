# Get Julia installation paths
JULIA_PREFIX=`julia --project -e 'joinpath(Sys.BINDIR, "..") |> abspath |> print'`
CXXWRAP_PREFIX=`julia --project -e 'using CxxWrap; CxxWrap.prefix_path() |> print'`
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release -DCMAKE_PREFIX_PATH=$CXXWRAP_PREFIX
cmake --build ./build --config Release -j `nproc`

