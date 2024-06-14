#include "jlcxx/array.hpp"
#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"
#include <Eigen/Dense>
#include <iostream>

auto print_address(jlcxx::ArrayRef<double, 1> jlx) {
  std::cout << jlx.data() << std::endl;
  static jlcxx::ArrayRef<double, 1> y = jlcxx::make_julia_array(jlx.data(), jlx.size());
  auto x = jlcxx::make_julia_array(jlx.data(), jlx.size());
  std::cout << x.data() << std::endl;
  // do something with x and pass results to y
  for (size_t i = 0; i < jlx.size(); i++) {
    y[i] = 2*x[i];
  }
  std::cout << y.data() << std::endl;
  return y;
}

auto twice(jlcxx::ArrayRef<double, 1> jlx) {
  static Eigen::VectorXd y;
  auto x = Eigen::Map<Eigen::VectorXd>(jlx.data(), jlx.size());
  // do something with x and pass results to y
  y = 2 * x;
  return jlcxx::make_julia_array(y.data(), y.size());
}

void inplace_twice(jlcxx::ArrayRef<double, 1> jlx) {
  for (size_t i = 0; i < jlx.size(); i++) {
    jlx[i] = 2 * jlx[i];
  }
}

auto triple(jlcxx::ArrayRef<double, 1> v) {
  static Eigen::VectorXd y;
  auto x = Eigen::Map<Eigen::VectorXd>(v.data(), v.size());
  // Do something
  y = 2 * x + x;
  return jlcxx::make_julia_array(y.data(), y.size());
}

auto inplace_triple(jlcxx::ArrayRef<double, 1> jlx) {
  auto x = Eigen::Map<Eigen::VectorXd>(jlx.data(), jlx.size());
  x = 3 * x;
  for (size_t i = 0; i < jlx.size(); i++) {
    jlx[i] = x[i];
  }
}

JLCXX_MODULE define_julia_module(jlcxx::Module &mod) {
  mod.method("print_address", &print_address);
  mod.method("twice", &twice);
  mod.method("twice!", &inplace_twice);

  mod.method("triple", &triple);
  mod.method("triple!", &inplace_triple);
}
