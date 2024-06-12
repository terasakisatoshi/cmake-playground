#include <string>
#include "jlcxx/jlcxx.hpp"
#include "jlcxx/stl.hpp"
#include "jlcxx/array.hpp"
#include <Eigen/Dense>
auto twice(jlcxx::ArrayRef<double, 1> v){
    static Eigen::VectorXd x;
    x.resize(v.size());
    for (int i = 0; i < v.size(); i++){
      x[i] = v[i];
    }
    x = 2 * x;
    return jlcxx::make_julia_array(x.data(), x.size());
}

JLCXX_MODULE define_julia_module(jlcxx::Module &mod) {
  mod.method("twice", twice);
}
