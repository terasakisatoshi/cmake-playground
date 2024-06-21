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
rm Manifest.toml
julia --project -e 'using Pkg; Pkg.instantiate()'
JL=`julia --project -e 'joinpath(Sys.BINDIR, "..") |> abspath |> print'`
PREFIX=`julia --project -e 'using CxxWrap; CxxWrap.prefix_path() |> print'`

# Build shared library with appropriate extension
g++ -fPIC -shared -std=c++17 \
  -I${PREFIX}/include/ \
  -L${PREFIX}/lib/ \
  -I${JL}/include/julia \
  -L${JL}/lib \
  -ljulia -lcxxwrap_julia hello.cpp -o libhello${SHARED_LIB_EXT}
