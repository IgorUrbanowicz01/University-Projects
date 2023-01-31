include("interpolation.jl")
using .Interpolation

FL = Interpolation.FL

x = Vector{FL}([-1, 0, 1, 2])
f = Vector{FL}([-1, 0, -1, 2])

fx = Interpolation.ilorazyRoznicowe(x, f)

a = Interpolation.naturalna(x, fx)

println(a)
