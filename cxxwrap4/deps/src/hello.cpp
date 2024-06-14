#include "jlcxx/array.hpp"
#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"
#include <Eigen/Dense>
#include <string>

auto twice(jlcxx::ArrayRef<double, 1> jlx) {
  static Eigen::VectorXd y;
  auto x = Eigen::Map<Eigen::VectorXd>(&jlx[0], jlx.size());
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
  auto x = Eigen::Map<Eigen::VectorXd>(&v[0], v.size());
  // Do something
  y = 2 * x + x;
  return jlcxx::make_julia_array(y.data(), y.size());
}

auto inplace_triple(jlcxx::ArrayRef<double, 1> jlx) {
  auto x = Eigen::Map<Eigen::VectorXd>(&jlx[0], jlx.size());
  x = 3 * x;
  for (size_t i = 0; i < jlx.size(); i++) {
    jlx[i] = x[i];
  }
}

JLCXX_MODULE define_julia_module(jlcxx::Module &mod) {
  mod.method("twice", &twice);
  mod.method("twice!", &inplace_twice);

  mod.method("triple", &triple);
  mod.method("triple!", &inplace_triple);
}
