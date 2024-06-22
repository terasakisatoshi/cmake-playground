module MyCxxWrap5

using Reexport


module MyAffine

using ..MyCxxWrap5

using CxxWrap
using Libdl

@wrapmodule(() -> joinpath(pkgdir(@__MODULE__), "../deps/build/lib/libjl_affine.$(dlext)"))

function __init__()
    @initcxx
end

end # MyAffine

@reexport using .MyAffine: Affine, getW, getb, EigenMatrix

end # module MyCxxWrap5
