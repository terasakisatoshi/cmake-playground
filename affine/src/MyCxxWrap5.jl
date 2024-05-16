module MyCxxWrap5

using CxxWrap
using Libdl

@wrapmodule(() -> joinpath(pkgdir(@__MODULE__), "build/lib/libjl_affine.$(dlext)"))

function __init__()
    @initcxx
end

end # module MyAffine
