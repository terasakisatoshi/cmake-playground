/*
This jl_affine.cpp is based on https://github.com/barche/EigenCpp.jl/blob/master/deps/src/eigen_wrapper/wrap_eigen.cpp

The EigenCpp.jl package is licensed under the MIT "Expat" License:

> Copyright (c) 2015: Bart Janssens.
>
> Permission is hereby granted, free of charge, to any person obtaining
> a copy of this software and associated documentation files (the
> "Software"), to deal in the Software without restriction, including
> without limitation the rights to use, copy, modify, merge, publish,
> distribute, sublicense, and/or sell copies of the Software, and to
> permit persons to whom the Software is furnished to do so, subject to
> the following conditions:
>
> The above copyright notice and this permission notice shall be
> included in all copies or substantial portions of the Software.
>
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
> EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
> MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
> IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
> CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
> TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
> SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#include <Eigen/Dense>
#include <type_traits>
#include <string>

#include "jlcxx/jlcxx.hpp"
#include "affine.hpp"

namespace jlcxx
{
  // Match the Eigen Matrix type, skipping the default parameters
  template<typename ScalarT, int Rows, int Cols>
  struct BuildParameterList<Eigen::Matrix<ScalarT, Rows, Cols>>
  {
    // We set the parameterlist to int64_t, to avoid having to wrap all parameters in Int32() in Julia
    typedef ParameterList<ScalarT, std::integral_constant<int64_t, Rows>, std::integral_constant<int64_t, Cols>> type;
  };
}

JLCXX_MODULE define_julia_module(jlcxx::Module &mod){
  // Add some fixed-size matrices
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>, jlcxx::TypeVar<2>, jlcxx::TypeVar<3>>>("EigenMatrix")
    .apply<Eigen::Matrix<double, 2, 2>, Eigen::Matrix<double, 2, 1>>([&mod](auto wrapped)
  {
    typedef typename decltype(wrapped)::type WrappedT;
    typedef typename WrappedT::Scalar ScalarT;
    typedef jlcxx::remove_const_ref<decltype(std::declval<WrappedT>()+std::declval<WrappedT>())> SumT;

    mod.add_type<SumT>("Sum_" + std::string(typeid(SumT).name()));

    mod.method("setConstant", [](WrappedT& eigen_mat, const ScalarT val)
    {
      eigen_mat.setConstant(val);
    });

	mod.set_override_module(jl_base_module);
    mod.method("print", [](const WrappedT& eigen_mat)
    {
      std::cout << eigen_mat << std::endl;
    });

    mod.method("println", [](const WrappedT& eigen_mat)
    {
      std::cout << eigen_mat << std::endl;
    });

    mod.method("convert", [](jlcxx::SingletonType<jlcxx::ArrayRef<ScalarT, 2>>, WrappedT& eigen_mat)
    {
      return jlcxx::ArrayRef<ScalarT, 2>(eigen_mat.data(), eigen_mat.rows(), eigen_mat.cols());
    });

    mod.method("getindex", [](const WrappedT& eigen_mat, const int64_t row, const int64_t col)
    {
      return eigen_mat(row-1,col-1);
    });

    mod.method("setindex!", [](WrappedT& eigen_mat, const ScalarT val, const int64_t row, const int64_t col)
    {
      eigen_mat(row-1,col-1) = val;
    });

    mod.method("+", [](const WrappedT& mat1, const WrappedT& mat2)
    {
      return jlcxx::create<SumT>(mat1 + mat2);
    });

    mod.method("convert", [](jlcxx::SingletonType<WrappedT>, const SumT& sum)
    {
      return jlcxx::create<WrappedT>(sum);
    });

    mod.method("==", [](const WrappedT& eigen_mat, const jlcxx::ArrayRef<ScalarT, WrappedT::ColsAtCompileTime==1?1:2>& julia_mat)
    {
      return eigen_mat == Eigen::Map<const WrappedT>(julia_mat.data());
    });
    mod.unset_override_module();
  });

  // Mat-vec product for (2x2)*(2x1)
  typedef jlcxx::remove_const_ref<decltype(std::declval<Eigen::Matrix<double, 2, 2>>()*std::declval<Eigen::Matrix<double, 2, 1>>())> ProductT;
  mod.add_type<ProductT>("Product_" + std::string(typeid(ProductT).name()));

  mod.set_override_module(jl_base_module);
  mod.method("*", [](const Eigen::Matrix<double, 2, 2>& mat, const Eigen::Matrix<double, 2, 1>& vec)
  {
    return jlcxx::create<Eigen::Matrix<double, 2, 1>>(mat * vec);
  });

  mod.method("+", [](const Eigen::Matrix<double, 2, 1>& a, Eigen::Matrix<double, 2, 1>& b)
  {
    return jlcxx::create<Eigen::Matrix<double, 2, 1>>(a+b);
  });
  mod.unset_override_module();

  mod.add_type<Affine>("Affine").constructor<Eigen::Matrix<double, 2, 2>, Eigen::Matrix<double,2,1>>();
  mod.method("getW", [](const Affine& aff){return aff.W;});
  mod.method("getb", [](const Affine& aff){return aff.b;});
}
