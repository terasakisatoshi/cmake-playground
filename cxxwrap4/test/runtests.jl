using Test
using MyCxxWrap4

@testset "greet" begin
	x = rand(10)
	v= MyCxxWrap4.twice(x)
	@test 2x == v
end
