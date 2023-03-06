#!/usr/bin/env julia

# imports
using LinearAlgebra
include("hilb.jl")
include("matcond.jl")
using Printf

function solve(A)
    # prepare
    x = ones(size(A)[1])
    b = A * x
    # calc using two methods
    gauss = A \ b
    inverted = inv(A) * b

    return gauss, inverted
end

# this function calculates the relative error between the original
# and the recalculated value
function calc_relative_error(x, x̃)
    return (norm(x - x̃)/norm(x))
end

# scientific notation formatting function
function scn(n)
    return @sprintf("%.0e", n)
    # return string(n)
end

# generates and print out the results
function printout(A, n, c, latex_table=false)

    gauss, inverted = solve(A)

    if !latex_table
        print(
            "n = ", n, "\n",
            (c != 0 ? string("c = ", scn(c), "\n") : ""),
            "  cond(A)                   = ", cond(A), "\n",
            "  rank(A)                   = ", rank(A), "\n",
            "  relative error (gauss)    = ", calc_relative_error(ones(n), gauss), "\n",
            "  relative error (inverted) = ", calc_relative_error(ones(n), inverted), "\n\n"
        )
    else
        println(
            n, " & ",
            (c != 0 ? string(scn(c), " & ") : ""),
            cond(A), " & ",
            rank(A), " & ",
            calc_relative_error(ones(n), gauss), " & ",
            calc_relative_error(ones(n), inverted), "\\\\"
        )
    end
end

# 1. Hilbert’s matrix Hₙ for n > 1
for n in 2:24

    A = hilb(n)
    printout(A, n, 0, false)

end

# 2. Random matrix Rₙ for n = 5,10,20 and c = 1, 10, 10³, 10⁷, 10^12, 10^16
for n in [5,10,20]

    for c in [1, 10, 10^3, 10^7, 10^12, 10^16]

        A = matcond(n, Float64(c))
        printout(A, n, c, false)

    end

end
