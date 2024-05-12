using Test

using MyCxxWrap4: Affine, transform, transform!, BarnsleyCategoricalDistribution

@testset "Affine/transform" begin
    w11 = 1.0
    w12 = 0.0
    w21 = 0.0
    w22 = 1.0
    b1 = 1.
    b2 = -1.

    aff = Affine(w11, w12, w21, w22, b1 ,b2)

    x = 1.
    y = 1.
    @test transform(aff, x ,y) == (2.0, 0.0)
end

@testset "Affine/transform!" begin
    w11 = 1.0
    w12 = 0.0
    w21 = 0.0
    w22 = 1.0
    b1 = 1.
    b2 = -1.

    aff = Affine(w11, w12, w21, w22, b1 ,b2)

    x = Ref{Float64}(1.)
    y = Ref{Float64}(1.)
    transform!(aff, x ,y)
    @test (x[], y[]) == (2.0, 0.0)
end

@testset "BarnsleyCategoricalDistribution" begin
    d = BarnsleyCategoricalDistribution(42);
    @test [rand(d) for _ in 1:20] == Int32[1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0, 3, 1, 1, 0, 1, 1]
end