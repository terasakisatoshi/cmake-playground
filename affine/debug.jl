using Test

using MyCxxWrap5

W = MyCxxWrap5.EigenMatrix{Float64,2,2}()
b = MyCxxWrap5.EigenMatrix{Float64,2,1}()

W_ = rand(2, 2)
for ci in CartesianIndices(W_)
    W[ci.I...] = W_[ci]
end

b_ = rand(2)
for i in eachindex(b_)
    b[i, 1] = b_[i]
end

aff = MyCxxWrap5.Affine(W, b)
println(W)
println(MyCxxWrap5.getW(aff))

println(b)
println(MyCxxWrap5.getb(aff))
