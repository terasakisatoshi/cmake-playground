#include <random>

#include "jlcxx/jlcxx.hpp"
#include "fern.hpp"



JLCXX_MODULE define_julia_module_fern(jlcxx::Module & mod){
  mod.add_type<BarnsleyCategoricalDistribution>("BarnsleyCategoricalDistribution")
    .constructor<>();
  mod.set_override_module(jl_base_module);
  mod.method("rand", [](BarnsleyCategoricalDistribution &d){
    std::random_device seed_gen;
    std::mt19937       engine(seed_gen());
    return d.rand(engine);
  });
  mod.unset_override_module();
}