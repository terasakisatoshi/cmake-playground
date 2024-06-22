# cmake-playground

My CMake/C++/CxxWrap playground

## hello

- CMake + GoogleTest

## cxxwrap1

- Building Julia interface for hello world application without using CMake

## cxxwrap2

- Same as cxxwrap1 except using CMake

## cxxwrap3

- Same as cxxwrap2 except cxxwrap3 organizes a directory structure.

## cxxwrap4

- This example shows passing Julia arrays and processing something in the C++ side, and returning results as an instance of the Julia array. Storing files in `./deps` allows us to build C++ code using `Pkg.build()`.

## affine (cxxwrap5)

- This example shows the wrapping of `Eigen::Matrix2d` and `Eigen::Vector2d`. Of course there is room for improvement. For those interested in more complicated examples using Eigen, check out [barche/cxxwrap-juliacon2020](https://github.com/barche/cxxwrap-juliacon2020/tree/master/eigen/sample-solution/jleigen)

## cxxwrap6

- This example shows how to pass/get arrays to/from C++ functions from Julia. Our example genenalizes [Working with arrays] section in CxxWrap.jl

## barnsley_fern

- Small C++ project having Julia interface by CxxWrap.jl
