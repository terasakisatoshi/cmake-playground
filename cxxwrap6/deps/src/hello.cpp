#include "jlcxx/array.hpp"
#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"
#include <Eigen/Dense>
#include <iostream>

void f(jlcxx::ArrayRef<double, 2> jlx) {
  size_t size0 = jl_array_dim(jlx.m_array, 0);
  size_t size1 = jl_array_dim(jlx.m_array, 1);

  std::cout << "[";
  for(size_t r = 0; r < size0; r++){
    for(size_t c = 0; c < size1; c++){
      std::cout << jlx[r + size0 * c];
      if (c == size1 - 1){
        if (r != size0 - 1){
          std::cout << "; ";
        }
      } else {
        std::cout << " ";
      }
    }
  }
   std::cout << "]";
   std::cout << std::endl;
}

auto print_address(jlcxx::ArrayRef<double, 2> jlx) {
  size_t size0 = jl_array_dim(jlx.m_array, 0);
  size_t size1 = jl_array_dim(jlx.m_array, 1);

  std::cout << jlx.data() << std::endl; // print memory address of x
  static Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> y;
  auto x = Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>>(jlx.data(), size0, size1);
  y = 2 * x;

  std::cout << y.data() << std::endl; // print memory address of y
  return jlcxx::make_julia_array(y.data(), size0, size1);
}

auto twice(jlcxx::ArrayRef<double, 2> jlx) {
  size_t size0 = jl_array_dim(jlx.m_array, 0);
  size_t size1 = jl_array_dim(jlx.m_array, 1);
  static Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> y;
  auto x = Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>>(jlx.data(), size0, size1);
  y = 2 * x;
  return jlcxx::make_julia_array(y.data(), size0, size1);
}

void inplace_twice(jlcxx::ArrayRef<double, 2> jlx) {
  for (size_t i = 0; i < jlx.size(); i++) {
    jlx[i] = 2 * jlx[i];
  }
}

auto triple(jlcxx::ArrayRef<double, 2> jlx) {
  size_t size0 = jl_array_dim(jlx.m_array, 0);
  size_t size1 = jl_array_dim(jlx.m_array, 1);
  static Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic> y;
  auto x = Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>>(jlx.data(), size0, size1);
  // Do something
  y = 2 * x + x;
  return jlcxx::make_julia_array(y.data(), size0, size1);
}

auto inplace_triple(jlcxx::ArrayRef<double, 2> jlx) {
  size_t size0 = jl_array_dim(jlx.m_array, 0);
  size_t size1 = jl_array_dim(jlx.m_array, 1);
  auto x = Eigen::Map<Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic>>(jlx.data(), size0, size1);
  x = 3 * x;
  for(size_t c = 0; c < size1; c++){
    for(size_t r = 0; r < size0; r++){
      auto i = r + size0 * c;
      jlx[i] = x(r, c);
    }
  }
}

JLCXX_MODULE define_julia_module(jlcxx::Module &mod) {
  mod.method("f", &f);
  mod.method("print_address", &print_address);
  mod.method("twice", &twice);
  mod.method("twice!", &inplace_twice);

  mod.method("triple", &triple);
  mod.method("triple!", &inplace_triple);
}
