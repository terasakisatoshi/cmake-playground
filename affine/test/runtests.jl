using Test

using MyCxxWrap5

@testset "Affine W, b" begin
    W = EigenMatrix{Float64,2,2}()
    b = EigenMatrix{Float64,2,1}()

    jlW = rand(2, 2)
    for ci in CartesianIndices(jlW)
        W[ci.I...] = jlW[ci]
    end

    jlb = rand(2)
    for i in eachindex(jlb)
        b[i, 1] = jlb[i]
    end

    aff = Affine(W, b)
    affW = getW(aff)
    affb = getb(aff)
    for ci in CartesianIndices(jlW)
        @test affW[ci.I...] == jlW[ci]
    end

    for i in eachindex(jlb)
        @test affb[i, 1] == jlb[i]
    end
end
