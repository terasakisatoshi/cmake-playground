module MyCxxWrap4
module CxxAffine
    import ..MyCxxWrap4
    using CxxWrap
    using Libdl
    @wrapmodule(() -> joinpath(pkgdir(MyCxxWrap4), "build/lib/libjl_affine.$(dlext)",), :define_julia_module_affine)
    function __init__()
        @initcxx
    end
end

module CxxFern
    import ..MyCxxWrap4
    using CxxWrap
    using Libdl
    @wrapmodule(() -> joinpath(pkgdir(MyCxxWrap4), "build/lib/libjl_fern.$(dlext)"), :define_julia_module_fern)
    function __init__()
        @initcxx
    end
end

using .CxxAffine

Affine = CxxAffine.Affine
transform = CxxAffine.transform

using .CxxFern

BarnsleyCategoricalDistribution = CxxFern.BarnsleyCategoricalDistribution

end # module MyCxxWrap4
