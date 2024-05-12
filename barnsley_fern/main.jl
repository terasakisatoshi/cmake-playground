using MyCxxWrap4: Affine, BarnsleyCategoricalDistribution, transform
using Plots

function main()

    aff1 = Affine(0.0, 0.0, 0.0, 0.16, 0.0, 0.0);
    aff2 = Affine(0.85, 0.04, -0.04, 0.85, 0.0, 1.6);
    aff3 = Affine(0.2, -0.26, 0.23, 0.22, 0.0, 1.6);
    aff4 = Affine(-0.15, 0.28, 0.26, 0.24, 0.0, 0.44);

    transforms = (aff1, aff2, aff3, aff4)
    d = BarnsleyCategoricalDistribution()
    N = 100000
    xs = Float64[]
    ys = Float64[]
    sizehint!(xs, N)
    sizehint!(ys, N)

    x = Ref{Float64}(0.)
    y = Ref{Float64}(0.)
    for i in 1:N
        c = rand(d)
        aff = transforms[begin+c]
        transform(aff, x, y)
        xderef = x[] # dereference
        yderef = y[] # dereference
        push!(xs, xderef)
        push!(ys, yderef)
    end
    scatter(xs, ys)
end

if abspath(PROGRAM_FILE) == @__FILE__
    p = main()
    savefig(p, "out.png")
end