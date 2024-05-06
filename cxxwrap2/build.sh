# Detect operating system
OS_TYPE=$(uname -s)

# Set shared library extension based on OS
if [[ $OS_TYPE == "Linux" ]]; then
  SHARED_LIB_EXT=".so"
elif [[ $OS_TYPE == "Darwin" ]]; then
  SHARED_LIB_EXT=".dylib"
else
  echo "Unsupported operating system: $OS_TYPE"
  exit 1
fi

# Get Julia installation paths
JULIA_PREFIX=`julia --project -e 'joinpath(Sys.BINDIR, "..") |> abspath |> print'`
CXXWRAP_PREFIX=`julia --project -e 'using CxxWrap; CxxWrap.prefix_path() |> print'`
cmake -S . -B ./build -DCMAKE_BUILD_TYPE=Release -DJulia_PREFIX=$JULIA_PREFIX -DCMAKE_PREFIX_PATH=$CXXWRAP_PREFIX
cmake --build ./build --config Release -j `nproc`

# Build shared library with appropriate extension
#g++ -fPIC -shared -std=c++17 \
#  -I${CXXWRAP_PREFIX}/include/ \
#  -L${CXXWRAP_PREFIX}/lib/ \
#  -I${JULIA_PREFIX}/include/julia \
#  -L${JULIA_PREFIX}/lib \
#  -ljulia -lcxxwrap_julia hello.cpp -o libhello${SHARED_LIB_EXT}
