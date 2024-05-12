#include <random>

#include "jlcxx/jlcxx.hpp"
#include "fern.hpp"



JLCXX_MODULE define_julia_module_fern(jlcxx::Module & mod){
  mod.add_type<BarnsleyCategoricalDistribution>("BarnsleyCategoricalDistribution")
    .constructor<>()
    .constructor<std::uint32_t>();
  mod.set_override_module(jl_base_module);
  mod.method("rand", [](BarnsleyCategoricalDistribution &d){
    return d.rand();
  });
  mod.unset_override_module();
}