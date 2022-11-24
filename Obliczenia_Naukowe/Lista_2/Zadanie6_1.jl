
include("Methods.jl")
using .FuncionsMethods

type = FuncionsMethods.type


change_starting = 1;

if change_starting == 1
    a, b = type(0.23), type(1.56)
else
    a, b = type(0.5), type(1.5)
end


r, fr, k, err = FuncionsMethods.bisekcja(
    x -> exp(1 - x) - 1,
    a,
    b,
    type(10^(-5)),
    type(10^(-5))
)

println(
    "BISEKCJA: \n",
    "r = ", r, "\n",
    "f(r) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)

if change_starting == 1
    a = type(0.23)
else
    a = type(1.0)
end

r, fr, k, err = FuncionsMethods.styczne(
    x -> exp(1 - x) - 1,
    x -> -1.0 * exp(1 - x),
    a,
    type(10^(-5)),
    type(10^(-5)),
    100
)

println(
    "NEWTON: \n",
    "r = ", r, "\n",
    "f(r) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)

if change_starting == 1
    a, b = type(-0.0), type(0.8)
else
    a, b = type(0.0), type(1.0)
end

r, fr, k, err = FuncionsMethods.sieczna(
    x -> exp(1 - x) - 1,
    a,
    b,
    type(10^(-5)),
    type(10^(-5)),
    100
)

println(
    "SIECZNA: \n",
    "r = ", r, "\n",
    "f(r) = ", fr, "\n",
    "k = ", k, "\n",
    err == 0 ? "" : string("error code:", err)
)