using Test

using MyCxxWrap4: Affine, transform!

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