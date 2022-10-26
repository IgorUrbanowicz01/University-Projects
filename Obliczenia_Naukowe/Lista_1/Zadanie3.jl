#Praca Igora Urbanowicz

x:: Float16  = 2.0

for i = 1:100
    #println(x," = ",bitstring(x))
    print(nextfloat(x) - x,"   ")
    println(bitstring(nextfloat(x) - x),"-różnica między float")
    global x = nextfloat(x)
end
