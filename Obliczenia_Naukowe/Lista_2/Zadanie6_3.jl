include("Methods.jl")
using .FuncionsMethods

type = FuncionsMethods.type

r, fr, k, err = FuncionsMethods.styczne(
    x -> exp(1 - x) - 1,
    x -> -1.0 * exp(1 - x),
    type(10.0),
    type(10^(-5)),
    type(10^(-5)),
    100
)

println(
    "NEWTONA dla x (1, inf): \n",
    "x = ", r, "\n",
    "f(x) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)

r, fr, k, err = FuncionsMethods.styczne(
    x -> x * exp(-x),
    x -> -1.0 * exp(1.0 * x) * (x - 1),
    type(1000.0),
    type(10^(-5)),
    type(10^(-5)),
    100
)

println(
    "NEWTONA dla x0 > 1: \n",
    "x = ", r, "\n",
    "f(x) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)