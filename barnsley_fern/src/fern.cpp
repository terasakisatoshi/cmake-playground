#include <random> // for std::random_device, std::mt19937, std::uniform_real_distribution
#include <cstdint> // std::uint32_t
#include "fern.hpp"

BarnsleyCategoricalDistribution::BarnsleyCategoricalDistribution(){
  std::random_device seed_gen;
  std::mt19937 engine(seed_gen());
  rng = engine;
  uniform = std::uniform_real_distribution<>(0.0,1.0);
}

BarnsleyCategoricalDistribution::BarnsleyCategoricalDistribution(std::uint32_t seed) {
  std::mt19937 engine(seed);
  rng = engine;
  uniform = std::uniform_real_distribution<>(0.0,1.0);
}

int BarnsleyCategoricalDistribution::rand(std::mt19937 &rng_) {
    double u = uniform(rng_);
    return select_index(u);
  }

int BarnsleyCategoricalDistribution::rand() {
  double u = uniform(rng);
  return select_index(u);
}

int BarnsleyCategoricalDistribution::select_index(double u){
    if (0 <= u && u < p1) {
      return 0;
    }
    if (p1 <= u && u < p1 + p2){
        return 1;
    }
    if (p1 + p2  <= u && u < p1 + p2 + p3){
        return 2;
    }
    if (p1 + p2 + p3 <= u && u < 1){
        return 3;
    } else {
        return 3;
    }
  }

