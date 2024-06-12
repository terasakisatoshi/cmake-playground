# Load the module and generate the functions
module MyCxxWrap4
using Libdl: dlext

using CxxWrap
@wrapmodule(() -> joinpath(pkgdir(@__MODULE__), "deps", "build", "src", "libhello.$(dlext)"))

function __init__()
    @initcxx
end
end
