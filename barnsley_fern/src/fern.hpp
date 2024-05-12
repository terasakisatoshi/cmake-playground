#ifndef BARNSLEY_CATEGORICAL_DISTRIBUTION_HPP
#define BARNSLEY_CATEGORICAL_DISTRIBUTION_HPP

#include <random> // std::mt19937, std::uniform_real_distribution

class BarnsleyCategoricalDistribution {
public:
  BarnsleyCategoricalDistribution(std::uniform_real_distribution<> uniform);
  BarnsleyCategoricalDistribution();
  int rand(std::mt19937 &rng);

private:
  int select_index(double u);
  std::uniform_real_distribution<> uniform;
  double p1 = 0.01;
  double p2 = 0.85;
  double p3 = 0.07;
  double p4 = 0.07;
};

#endif // BARNSLEY_CATEGORICAL_DISTRIBUTION_HPP