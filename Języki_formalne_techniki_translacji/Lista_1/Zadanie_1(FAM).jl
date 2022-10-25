

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
            while (!endswith(pattern[1:nextind(pattern, 0 ,q)]*a, pattern[1:nextind(pattern, 0 ,k)]))
                k = prevind(pattern, k)
            end
            qFuncion[(q,a)]=k
        end
    end
    return qFuncion, m
end

function finiteAtomatonMatcher(base, qFuncion, m)
    n = length(base)
    q=0
    i=1
    while i <= n
        q = qFuncion[q, base[nextind(base, 0 ,i)]]
        if q == m
                s = i - m
            print( Int(s), " ")
        end
        i += 1
    end
end

#base_file = read(open("Base.txt", "r"),String)
#pattern_file = read(open("Pattern.txt", "r"),String)
#character_list = getUniqeCharacters(base_file)

#println(character_list)
#qFuncion,m = computerTransitionFuncion(pattern_file,character_list)
#println(qFuncion,"  " ,pattern_file)
#finiteAtomatonMatcher(base_file,qFuncion,m)