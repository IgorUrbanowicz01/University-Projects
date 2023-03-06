#Praca Igora Urbanowicz

x = [2.718281828, -3.141592654, 1.414213562, 0.5772156649, 0.3010299957]
y = [1486.2497, 878366.9879, -22.37492, 4773714.647, 0.000185049]

S = 0.0
arr1 = []
arr2 = []
a1=0.0
a2=0.0

for i in 1:(length(x))
    global S += x[i]*y[i]
end
println(S)
S = 0.0

for i in 1:(length(x))
    global S += x[length(x)-i+1]*y[length(x)-i+1]
end
println(S)

for i in 1:(length(x))
    temp = x[i]*y[i]
    if temp > 0
        push!(arr1, temp)
    else
        push!(arr2, temp)
    end
end



S = 0.0
arr1 = sort(arr1, rev=true)
arr2 = sort(arr2)
for i in arr1
    global a1 += i
end
for i in arr2
    global a2 += i
end
S = a1 +a2 
println(S)

S = 0.0
a1=0.0
a2=0.0
arr1 = sort(arr1)
arr2 = sort(arr2, rev=true)
println(arr1)
println(arr2)
for i in arr1
    global a1 += i
end
for i in arr2
    global a2 += i
end
println(a1)
println(a2)

S = a1 +a2 
println(S)
