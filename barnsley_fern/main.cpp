#include <cstdint>  // for std::uint32_t
#include <iostream> // for std::cout, std::endl
#include <vector> // for std::vector

#include "affine.hpp"
#include "fern.hpp"


int main() {
  const std::uint32_t seed = 42;
  std::mt19937 rng(seed);

  const auto aff1 = Affine(0.0, 0.0, 0.0, 0.16, 0.0, 0.0);
  const auto aff2 = Affine(0.85, 0.04, -0.04, 0.85, 0.0, 1.6);
  const auto aff3 = Affine(0.2, -0.26, 0.23, 0.22, 0.0, 1.6);
  const auto aff4 = Affine(-0.15, 0.28, 0.26, 0.24, 0.0, 0.44);
  const std::vector<Affine> transforms{aff1, aff2, aff3, aff4};
  auto d = BarnsleyCategoricalDistribution();
  const int N = 100000;
  std::vector<double> xs, ys;
  xs.reserve(N);
  ys.reserve(N);

  double x = 0.0;
  double y = 0.0;
  int c = 0;
  for (int i =0 ; i < N; i++) {
    c = d.rand(rng);
    auto aff = transforms[c];
    aff.transform(x, y);
    xs.push_back(x);
    ys.push_back(y);
  }

  // header
  std::cout << "x,y" << std::endl;
  // contents
  for (int i = 0; i < xs.size(); i ++ ){
      auto x = xs[i];
      auto y = ys[i];
      std::cout << x << "," << y << std::endl;
  }
  return 0;
}
