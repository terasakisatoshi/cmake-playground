using DataFrames, CSV, StatsPlots

df = CSV.read("out.csv", DataFrame)
@df df scatter(:x, :y)
