module MyCxxWrap4

using Reexport

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

@reexport using .CxxAffine: Affine
export transform!, transform

function transform(aff::Affine, x::T, y::T) where T<:AbstractFloat
    refx = Ref(x)
    refy = Ref(y)
    CxxAffine.transform(aff, refx, refy)
    return (refx[], refy[])
end

function transform!(aff::Affine, refx::Ref{T}, refy::Ref{T}) where T<:AbstractFloat
    CxxAffine.transform(aff, refx, refy)
end

@reexport using .CxxFern: BarnsleyCategoricalDistribution

end # module MyCxxWrap4
