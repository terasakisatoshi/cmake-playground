# cmake -S . -B ./build && cmake --build ./build && ./build/MyHello

using Test
using ReferenceTests

@testset "MyHello" begin
	mktempdir() do d
		run(`cmake -S ../ -B $(d)`)
		run(`cmake --build $(d)`)
		exec = joinpath(d, "MyHello")
		o = read(`$(exec)`, String)
		reftxt = "MyHello.txt"
		@test_reference reftxt o
	end
end