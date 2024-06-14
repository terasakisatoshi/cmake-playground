using Test
using MyCxxWrap4

# 何回かコードを実行しておかしなことが起きないかを確認
@testset "twice" begin
    x = rand(5)
    v = MyCxxWrap4.twice(x)
    @test v == 2x
    @test length(v) == length(x)

    x = rand(10)
    v = MyCxxWrap4.twice(x)
    @test v == 2x
    @test length(v) == length(x)

    x = rand(5)
    v = MyCxxWrap4.twice(x)
    @test v == 2x
    @test length(v) == length(x)

    x = rand(10)
    v = MyCxxWrap4.twice(x)
    @test v == 2x
    @test length(v) == length(x)
end

@testset "twice!" begin
    x = rand(5)
    expected = 2copy(x)
    MyCxxWrap4.twice!(x)
    @test x == expected
    @test length(x) == length(expected)

    x = rand(10)
    expected = 2copy(x)
    MyCxxWrap4.twice!(x)
    @test x == expected
    @test length(x) == length(expected)

    x = rand(5)
    expected = 2copy(x)
    MyCxxWrap4.twice!(x)
    @test x == expected
    @test length(x) == length(expected)

    x = rand(10)
    expected = 2copy(x)
    MyCxxWrap4.twice!(x)
    @test x == expected
    @test length(x) == length(expected)
end

@testset "triple" begin
    x = rand(5)
    v = MyCxxWrap4.triple(x)
    @test v == 3x
    @test length(v) == length(x)

    x = rand(10)
    v = MyCxxWrap4.triple(x)
    @test v == 3x
    @test length(v) == length(x)

    x = rand(5)
    v = MyCxxWrap4.triple(x)
    @test v == 3x
    @test length(v) == length(x)

    x = rand(10)
    v = MyCxxWrap4.triple(x)
    @test v == 3x
    @test length(v) == length(x)
end

@testset "triple!" begin
    x = rand(5)
    expected = 3copy(x)
    MyCxxWrap4.triple!(x)
    @test x == expected
    @test length(x) == length(expected)

    x = rand(10)
    expected = 3copy(x)
    MyCxxWrap4.triple!(x)
    @test x == expected
    @test length(x) == length(expected)

    x = rand(5)
    expected = 3copy(x)
    MyCxxWrap4.triple!(x)
    @test x == expected
    @test length(x) == length(expected)

    x = rand(10)
    expected = 3copy(x)
    MyCxxWrap4.triple!(x)
    @test x == expected
    @test length(x) == length(expected)
end

