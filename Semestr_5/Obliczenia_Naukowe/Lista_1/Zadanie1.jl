#Praca Igora Urbanowicz
using Printf
type = Float64
x:: type  = 2
y:: type = 0
number :: type = 0
while x+1>1
    global y = x
    global x /= 2
end

@printf("x = %.6e\n", y)
#println(y, "  ",y+1>1)
#println(x, "  ",x+1>1)
#println(y, " y = ",bitstring(y))
#println(x, " x = ",bitstring(x))
println

x:: type = 1

while x > 0.0
    global y = x
    global x /= 2
end 
#println(x, " x = ",bitstring(x))
@printf("x = %.6e\n", y)
x:: type = 2.0

while !(isinf(x))
    global y = x 
    global x *=2
end
x = y

while !(isinf(x))
    global number = x
    global y /= 2 
    global x += y
end 
println(x, " x = ",bitstring(x))
println(number, " y = ",bitstring(number))