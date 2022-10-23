

base_file = read(open("Base.txt", "r"),String)
pattern_file = read(open("Pattern.txt", "r"),String)

function computePrefix(pattern)
    m = length(pattern)
    pi_=zeros(Int64 ,m)
    k = 0
    q = 2
    while q <= m
        while k > 0 && pattern[nextind(pattern, k)] != pattern[nextind(pattern,0,q)]
            k = pi_[k]
        end
        if pattern[nextind(pattern, k)] == pattern[nextind(pattern,0,q)]
            k +=1
        end
        pi_[q] = k
        q += 1
    end
    return pi_
end

function kmpMatcher(base_file, pattern_file)
    n = length(base_file)
    m = length(pattern_file)
    pi_ = computePrefix(pattern_file)
    q = 0
    i=1
    while i <= n
        while q > 0 && pattern_file[nextind(pattern_file, 0 ,q+1)] != base_file[nextind(base_file, 0 , i)]
            q = pi_[q]
        end
        if pattern_file[nextind(pattern_file,0,q+1)] == base_file[nextind(base_file, 0 , i)]
            q += 1
        end
        if q == m
            print(" ", i - m)
            q = pi_[q]
        end
        i += 1
    end
end

#kmpMatcher(base_file, pattern_file)