using Test
using MyCxxWrap6: twice, twice!, triple, triple!

# 何回かコードを実行しておかしなことが起きないかを確認
@testset "twice" begin
    x = rand(5, 5)
    v = twice(x)
    @test v == 2x
    @test length(v) == length(x)
    @test size(v) == size(x)

    x = rand(10, 10)
    v = twice(x)
    @test v == 2x
    @test length(v) == length(x)
    @test size(v) == size(x)

    x = rand(5, 5)
    v = twice(x)
    @test v == 2x
    @test length(v) == length(x)
    @test size(v) == size(x)

    x = rand(10, 10)
    v = twice(x)
    @test v == 2x
    @test length(v) == length(x)
    @test size(v) == size(x)
end

@testset "twice!" begin
    x = rand(5, 5)
    expected = 2copy(x)
    twice!(x)
    @test x == expected
    @test length(x) == length(expected)
    @test size(x) == size(expected)

    x = rand(10, 10)
    expected = 2copy(x)
    twice!(x)
    @test x == expected
    @test length(x) == length(expected)
    @test size(x) == size(expected)

    x = rand(5, 5)
    expected = 2copy(x)
    twice!(x)
    @test x == expected
    @test length(x) == length(expected)
    @test size(x) == size(expected)

    x = rand(10, 10)
    expected = 2copy(x)
    twice!(x)
    @test x == expected
    @test length(x) == length(expected)
    @test size(x) == size(expected)
end

@testset "triple" begin
    x = rand(5, 5)
    v = triple(x)
    @test v == 3x
    @test length(v) == length(x)
    @test size(v) == size(x)

    x = rand(10, 10)
    v = triple(x)
    @test v == 3x
    @test length(v) == length(x)
    @test size(v) == size(x)

    x = rand(5, 5)
    v = triple(x)
    @test v == 3x
    @test length(v) == length(x)
    @test size(v) == size(x)

    x = rand(10, 10)
    v = triple(x)
    @test v == 3x
    @test length(v) == length(x)
    @test size(v) == size(x)
end

@testset "triple!" begin
    x = rand(5, 5)
    expected = 3copy(x)
    triple!(x)
    @test x == expected
    @test length(x) == length(expected)
    @test size(x) == size(expected)

    x = rand(10, 10)
    expected = 3copy(x)
    triple!(x)
    @test x == expected
    @test length(x) == length(expected)
    @test size(x) == size(expected)

    x = rand(5, 5)
    expected = 3copy(x)
    triple!(x)
    @test x == expected
    @test length(x) == length(expected)
    @test size(x) == size(expected)

    x = rand(10, 10)
    expected = 3copy(x)
    triple!(x)
    @test x == expected
    @test length(x) == length(expected)
    @test size(x) == size(expected)
end

