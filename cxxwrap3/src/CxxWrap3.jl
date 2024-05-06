# Load the module and generate the functions
module CxxWrap3
using Libdl: dlext

using CxxWrap
@wrapmodule(() -> joinpath("./build", "libhello.$(dlext)"))

function __init__()
    @initcxx
end
end