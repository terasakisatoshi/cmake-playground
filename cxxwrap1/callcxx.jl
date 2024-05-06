# Load the module and generate the functions
module CppHello
  using CxxWrap
  @wrapmodule(()->joinpath(".","libhello.so"))

  function __init__()
    @initcxx
  end
end

# Call greet and show the result
@show CppHello.greet()
