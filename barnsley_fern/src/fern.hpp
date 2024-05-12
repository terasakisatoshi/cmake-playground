#ifndef BARNSLEY_CATEGORICAL_DISTRIBUTION_HPP
#define BARNSLEY_CATEGORICAL_DISTRIBUTION_HPP

#include <random> // std::mt19937, std::uniform_real_distribution
#include <cstdint>

class BarnsleyCategoricalDistribution {
public:
  BarnsleyCategoricalDistribution();
  BarnsleyCategoricalDistribution(std::uint32_t seed);
  int rand(std::mt19937 &rng);
  int rand();

private:
  int select_index(double u);
  std::uniform_real_distribution<> uniform;
  std::mt19937 rng;
  double p1 = 0.01;
  double p2 = 0.85;
  double p3 = 0.07;
  double p4 = 0.07;
};

#endif // BARNSLEY_CATEGORICAL_DISTRIBUTION_HPP