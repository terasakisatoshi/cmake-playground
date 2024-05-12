#include "jlcxx/jlcxx.hpp"
#include "affine.hpp"

struct World
{
  World(const std::string& message = "default hello") : msg(message){}
  World(jlcxx::cxxint_t) : msg("NumberedWorld") {}
  void set(const std::string& msg) { this->msg = msg; }
  const std::string& greet() const { return msg; }
  std::string msg;
  ~World() { std::cout << "Destroying World with message " << msg << std::endl; }
};

std::string greet(std::string msg)
{
   return msg;
}

JLCXX_MODULE define_julia_module_affine(jlcxx::Module & mod){
  mod.add_type<Affine>("Affine")
    .constructor<double, double, double, double, double, double>()
    .method("transform", &Affine::transform);
  mod.add_type<World>("World")
    .constructor<const std::string&>();
  mod.method("greet", &greet);
}
