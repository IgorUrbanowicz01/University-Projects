

include("Methods.jl")
using .FuncionsMethods

type = FuncionsMethods.type

r, fr, k, err = FuncionsMethods.bisekcja(
    x -> sin(x) - (x / 2)^2,
    type(1.5),
    type(2.0),
    type((10^(-5)) / 2),
    type((10^(-5)) / 2)
)

println(
    "BISEKCJA: \n"
    "r = ", r, "\n",
    "f(r) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)

r, fr, k, err = FuncionsMethods.styczne(
    x -> sin(x) - (x / 2)^2,
    x -> cos(x) - x / 2,
    type(1.5),
    type((10^(-5)) / 2),
    type((10^(-5)) / 2),
    200
)

println(
    "NEWTON: \n"
    "r = ", r, "\n",
    "f(r) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)

r, fr, k, err = FuncionsMethods.sieczna(
    x -> sin(x) - (x / 2)^2,
    type(1.0),
    type(2.0),
    type((10^(-5)) / 2),
    type((10^(-5)) / 2),
    200
)

println(
    "SIECZNA: \n"
    "r = ", r, "\n",
    "f(r) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)