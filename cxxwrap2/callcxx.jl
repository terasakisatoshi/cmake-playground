using Test

# Load the module and generate the functions
module CppHello
using Libdl: dlext

using CxxWrap
@wrapmodule(() -> joinpath("./build", "libhello.$(dlext)"))

function __init__()
    @initcxx
end
end

@testset "greet" begin
    # Call greet and show the result
    @test CppHello.greet("Hello World") == "Hello World"
end
