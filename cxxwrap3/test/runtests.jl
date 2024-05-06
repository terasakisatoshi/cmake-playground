using Test
using MyCxxWrap3

@testset "greet" begin
	@test MyCxxWrap3.greet("Hello") == "Hello"
end
