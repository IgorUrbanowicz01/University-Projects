

include("Methods.jl")
using .FuncionsMethods

type = FuncionsMethods.type

r, fr, k, err = FuncionsMethods.bisekcja(
    x -> 3x - exp(x),
    type(0.0),
    type(1.0),
    type(10^(-4)),
    type(10^(-4))
)

println(
    "r = ", r, "\n",
    "f(r) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)

r, fr, k, err = FuncionsMethods.bisekcja(
    x -> 3x - exp(x),
    type(1.0),
    type(2.0),
    type(10^(-4)),
    type(10^(-4))
)

println(
    "r = ", r, "\n",
    "f(r) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)