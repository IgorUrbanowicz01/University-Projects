include("Methods.jl")
using .FuncionsMethods

type = FuncionsMethods.type

change_starting = 1;

if change_starting == 1
    a, b = type(-0.29), type(1.0)
else
    a, b = type(-0.5), type(1.0)
end

r, fr, k, err = FuncionsMethods.bisekcja(
    x -> x * exp(-x),
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
    a = type(-0.29)
else
    a = type(-0.0)
end

r, fr, k, err = FuncionsMethods.styczne(
    x -> x * exp(-x),
    x -> -1.0 * exp(-1.0 * x) * (x - 1),
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
    a, b = type(-0.2), type(-0.6)
else
    a, b = type(-1.0), type(0.0)
end

r, fr, k, err = FuncionsMethods.sieczna(
    x -> x * exp(-x),
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