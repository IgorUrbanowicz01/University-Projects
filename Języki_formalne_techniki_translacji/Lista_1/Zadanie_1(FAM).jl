

function getUniqeCharacters(base)
    character_list :: String = ""
    for i in base
        if !contains(character_list, i)
            character_list *= i
        end
    end
    return character_list
end

function computerTransitionFuncion(pattern,character_list)
    qFuncion = Dict()
    m = length(pattern)
    for q in 0:m
        for a in character_list
            k = min(m,q+1)
            while !endswith(pattern[1:thisind(pattern, q)]*a, pattern[1:thisind(pattern, k)])
                k = k - 1
                k = thisind(pattern, k)
                if k == 0
                    break
                end
            end
            println(q, " ",  a, "  ",k,"  ", pattern)
            qFuncion[(q,a)]=k
        end
    end
    return qFuncion, m
end

function finiteAtomatonMatcher(base, qFuncion, m)
    n = length(base)
    q=0
    for i in 1:n
        q = qFuncion[q,base[thisind(base, i)]]
        if q == m
            s = i-m
            println("Wrzozec występuje z przesunięciem ", s)
        end
        i = thisind(base, i)
    end
end

base_file = read(open("Base.txt", "r"),String)
pattern_file = read(open("Pattern.txt", "r"),String)
character_list = getUniqeCharacters(base_file)

println(character_list)

qFuncion,m = computerTransitionFuncion(pattern_file,base_file)
println(qFuncion)
println(typeof(m))
finiteAtomatonMatcher(base_file,qFuncion,m)