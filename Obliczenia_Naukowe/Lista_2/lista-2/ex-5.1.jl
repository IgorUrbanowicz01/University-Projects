#!/usr/bin/env julia
#

#

fl = Float32

# starting points
p = fl(0.01)
pp = fl(0.01)

r = 3

# calculate the next sequence member
function calc(x)
    return fl(x + fl(r*fl(x*fl(1 - x))))
end

# print out the consecutive members of the sequences
for n in 1:40

    global p = calc(p)
    global pp = calc(pp)
    if n == 10
        global pp = floor(pp, digits=3)
    end
    println(n, " & ", p, " & ", pp, "\\\\")

end
