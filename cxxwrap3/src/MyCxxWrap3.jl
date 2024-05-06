# Load the module and generate the functions
module MyCxxWrap3
using Libdl: dlext

using CxxWrap
@wrapmodule(() -> joinpath(pkgdir(@__MODULE__), "build", "src", "libhello.$(dlext)"))

function __init__()
    @initcxx
end
end
