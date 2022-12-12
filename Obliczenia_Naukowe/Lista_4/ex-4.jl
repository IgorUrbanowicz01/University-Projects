include("interpolation.jl")
using .Interpolation

Interpolation.rysujNnfx(x->sin(x) + cos(x), 0.0, 5.0, 5)

println("end the interactive session to close all plots")
