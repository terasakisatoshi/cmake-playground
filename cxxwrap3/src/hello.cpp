#include <string>

#include "jlcxx/jlcxx.hpp"

std::string greet(std::string msg)
{
   return msg;
}

JLCXX_MODULE define_julia_module(jlcxx::Module& mod)
{
  mod.method("greet", &greet);
}
