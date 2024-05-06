JL=`julia -e 'joinpath(Sys.BINDIR, "..") |> abspath |> print'`
PREFIX=`julia -e 'using CxxWrap; CxxWrap.prefix_path() |> print'`

g++ -fPIC -shared -std=c++17 \
  -I${PREFIX}/include/ \
  -L${PREFIX}/lib/ \
  -I${JL}/include/julia \
  -L${JL}/lib \
  hello.cpp -o libhello.so
