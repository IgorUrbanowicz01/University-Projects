
function f(x, h)
    (sin(x+h) + cos(3x+h) - (sin(x) + cos(3x)))/h
end

for i in 0:54
    println(round(f(1,2.0^-i); digits = 5))
end