
function f(x)
    sqrt(x^2+1)-1
end

function g(x)
    x^2/(sqrt(x^2+1)+1)
end

for i in 1:100
    println(f(8.0^-i))
end
for i in 1:100
    println(g(8.0^-i))
end