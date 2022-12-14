include("interpolation.jl")
using .Interpolation

FL = Interpolation.FL

x = Vector{FL}([3, 1, 5, 6])
f = Vector{FL}([1, -3, 2, 4])

fx = Interpolation.ilorazyRoznicowe(x, f)

ft = Interpolation.warNewton(x, fx, 1.0)

println(ft)
