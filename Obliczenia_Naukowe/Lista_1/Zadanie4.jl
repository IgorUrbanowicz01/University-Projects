#Praca Igora Urbanowicz

using Printf

x::Float64 = 2.0
y::Float64 = 0
while x*(1/x) == 1 && x>1.0
    global x /= 1.0001
end
@printf("x = %.20f\n", x)
x::Float64 = 2.0
while x > 1.0
    if x*(1/x) == 1
        global y=x
    end
    global x /= 1.000001
end
@printf("y = %.20f\n", y)